#include "Card.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

string r[13] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
string s[4] = { "spade", "heart", "clover", "diamonds" };

int Card_counting[14] = { 0, };

void Shuffle(vector <Card>& card)
{
	Card temp;

	srand(time(NULL));
	for (int i = 0; i < card.size(); i++)
	{
		int r = rand() % card.size();
		temp = card[i];
		card[i] = card[r];
		card[r] = temp;
	}
}//카드를 섞어주는 기능. 80% 이상 사용하면, 다음 게임을 시작할 때 다시 섞어준다.

int SumofNum(vector <Card>& card)
{
	int i = 0;
	int sum = 0;
	while (card[i].get_value() != 0)
	{
		sum += card[i].get_value();
		i++;
	}

	return sum;
}// 현재 플레이어의 카드 숫자 합이 얼마인지 계산하는 기능.


void Count_plus(string JQK, int card_num)
{
	int a = 0;
	if (JQK.compare("A") == 0)
		a = 1;
	else if (JQK.compare("J") == 0)
		a = 11;
	else if (JQK.compare("Q") == 0)
		a = 12;
	else if (JQK.compare("K") == 0)
		a = 13;
	else
		a = card_num;
	Card_counting[a]++;
} //card couning

bool HitStatus(vector <Card>& card)
{
	if (SumofNum(card) > 21)
	{
		for (int i = 0; i < 10; i++)
		{
			if (card[i].get_value() == 11)
			{
				card[i].set_value(1);
				break;
			}
		}
	} // 21이상일 때는 A의 값을 1로 변경.

	if (SumofNum(card) < 17)
		return true; // hit

	else
		return false; //stand
	
}

bool Counting_HitStatus(vector <Card>& card, int count)
{
	float two_six = 0; // 2~ 6 나올 확률
	float ten = 0; // A, 10, J, Q, K 나올 확률
		
	two_six = ((float)((6 * 4 * 5) - (Card_counting[2] + Card_counting[3] + Card_counting[4] + Card_counting[5] + Card_counting[6])) / (float)(312 - count)) * 100; 
	ten = ((float)((6 * 4 * 5) - (Card_counting[1] + Card_counting[10] + Card_counting[11] + Card_counting[12] + Card_counting[13])) / (float)(312 - count)) * 100;
	
	if (SumofNum(card) > 21)
	{
		for (int i = 0; i < 10; i++)
		{
			if (card[i].get_value() == 11)
			{
				card[i].set_value(1);
				break;
			}
		}
	} // 21이상일 때는 A의 값을 1로 변경.
	
	if (SumofNum(card) < 12)
		return true; // hit

	else if (SumofNum(card) < 17)
	{
		if (ten >= 50)
			return false; //stand
		else
			return true; //hit
	}

	else if (SumofNum(card) < 20)
	{
		if (two_six >= 50)
			return  true; // hit
		else
			return false; //stand
	}

	else
		return false; //stand

}


int Betting(int player, int count)
{
	float two_six = 0; // 2~ 6 나올 확률
	float ten = 0; // A, 10, J, Q, K 나올 확률

	two_six = (float)(Card_counting[2] + Card_counting[3] + Card_counting[4] + Card_counting[5] + Card_counting[6]) / (float)(312 - count);
	ten = (float)(Card_counting[1] + Card_counting[10] + Card_counting[11] + Card_counting[12] + Card_counting[13]) / (float)(312 - count);
	
	int k = 0; 
	int a = 100; //알파를 100으로 설정.
	k = (two_six - ten) * a;

	if (player == 1) 
	{
		if (k > 1)
			return 100 * k;
		else
			return 100;
		
	}

	else
		return 100; //simpler player betting 100won.

} // 배팅을 얼마할지 정해주는 기능, simple player은 100원.

int Game_win(int dealer, int player)
{
	if ((dealer > 21 && player > 21) || (dealer == player))
		return 1; //draw

	else if (dealer > 21 && player <= 21)
		return 0; //win

	else if (dealer <= 21 && player > 21)
		return 2; //lose
	else if (dealer < player)
		return 0; //win
	else if (dealer > player)
		return 2; //lose
	else
		return -1;

} //승패 판단

int main()
{
	int num;
	int player_money = 100000;
	int simple_player_money = 100000; //초기 자금 100,000원
	int player_win = 0;
	int simple_player_win = 0;
	int player_draw = 0;
	int simple_player_draw = 0;

	cout << "Play Game : ";
	cin >> num;

	vector <Card> deck(312);

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 52; j++)
		{
			if (j % 13 == 0)
				deck[j + (52 * i)].set_value(11);
			else if (j % 13 >= 9)
				deck[j + (52 * i)].set_value(10);
			else
				deck[j + (52 * i)].set_value(j % 13 + 1);
			deck[j + (52 * i)].set_rank(r[j % 13]);
			deck[j + (52 * i)].set_suit(s[j / 13]);
		}
	}

	Shuffle(deck);
	/*
	for (int i = 0; i < 312; i++)
	{
		deck[i].display();
	}
	*/

	//////////play///////////
	int count = 0;
	for (int n = 0; n < num; n++)
	{
		if (count > 249)
		{
			count = 0;
			Shuffle(deck); // 카드 다시 섞기
			for (int i = 0; i < 14; i++)
				Card_counting[i] = 0; // card count 초기화
		}

		/////////////////player///////////////////////
		vector <Card> dealer(10);
		vector <Card> player(10);
		vector <Card> simple_player(10);

		//////////////////betting//////////////
		int player_betting = Betting(1, count); //player betting
		int simple_player_betting = Betting(2, count); //simple_player betting


		dealer[0] = deck[count];
		player[0] = deck[count + 1];
		simple_player[0] = deck[count + 2];
		dealer[1] = deck[count + 3];
		player[1] = deck[count + 4];
		simple_player[1] = deck[count + 5]; // 기본 카드 두장씩 나눠줌.

		for (int i = count+1; i < count + 6; i++)
		{
			Count_plus(deck[i].get_rank(), deck[i].get_value());
		} // card counting
		// player는 dealer의 한 장은 모름.
		count = count + 6;

		while (1)
		{
			if (HitStatus(dealer) == true)
			{
				for (int i = 2; i < 10; i++)
				{
					if (dealer[i].get_value() == 0)
					{
						dealer[i] = deck[count];
						Count_plus(dealer[i].get_rank(), dealer[i].get_value());
						count++;
						break;
					}
				}
			}
			//cout << SumofNum(dealer) << endl;

			if (Counting_HitStatus(player, count) == true)
			{
				for (int i = 2; i < 10; i++)
				{
					if (player[i].get_value() == 0)
					{
						player[i] = deck[count];
						Count_plus(player[i].get_rank(), player[i].get_value());
						count++;
						break;
					}
				}
			}
			//cout << SumofNum(player) << endl;

			if (HitStatus(simple_player) == true)
			{
				for (int i = 2; i < 10; i++)
				{
					if (simple_player[i].get_value() == 0)
					{
						simple_player[i] = deck[count];
						Count_plus(simple_player[i].get_rank(), simple_player[i].get_value());
						count++;
						break;
					}
				}
			}
			//cout << SumofNum(simple_player) << endl;

			if (HitStatus(dealer) == false && HitStatus(simple_player) == false && Counting_HitStatus(player, count) == false)
				break;

		}

		Count_plus(dealer[0].get_rank(), dealer[0].get_value()); //게임이 끝난 후 dealer의 카드 한 장 open

		//cout << "dealer: " << SumofNum(dealer) << " player : " << SumofNum(player) << " simple_player : " << SumofNum(simple_player) << endl;

		////////////////////////////////////승패 여부에 따라 돈 받음, 잃음.////////////////////////////////////////////
		if (Game_win(SumofNum(dealer), SumofNum(player)) == 0) 
		{
			player_win++;

			if (SumofNum(player) == 21 && player[2].get_value() == 0) //블랙잭
				player_money = player_money + ((player_betting * 15) / 10); //2.5배 돌려받음.
			
			else
				player_money = player_money + player_betting; //2배 돌려받음.
		}//win

		else if (Game_win(SumofNum(dealer), SumofNum(player)) == 1)
			player_draw++;
		//draw

		else if (Game_win(SumofNum(dealer), SumofNum(player)) == 2) 
			player_money = player_money - player_betting; // 배팅 금액 잃음.
		//lose

		if (Game_win(SumofNum(dealer), SumofNum(simple_player)) == 0)
		{
			simple_player_win++;

			if (SumofNum(simple_player) == 21 && player[2].get_value() == 0) //블랙잭
				simple_player_money = simple_player_money + ((simple_player_betting * 15) / 10); //2.5배 돌려받음.
			
			else
				simple_player_money = simple_player_money + simple_player_betting; //2배 돌려받음.
		} //win

		else if (Game_win(SumofNum(dealer), SumofNum(simple_player)) == 1) 
			simple_player_draw++;
		// draw

		else if (Game_win(SumofNum(dealer), SumofNum(simple_player)) == 2)
			simple_player_money = simple_player_money - simple_player_betting; // 배팅 금액 잃음.
		//lose
	}

	float win_rate_player = ((float)player_win / (float)(num - player_draw)) * 100;
	float win_rate_simple_player = ((float)simple_player_win / (float)(num - simple_player_draw)) * 100;

	cout << "Card counting Player " << "/ win : " << player_win << " / draw : " << player_draw 
		 << " / 승률 : " << win_rate_player << "%" << " / 남은 돈 : " << player_money << endl;
	cout << "Card counting Player " << "/ win : " << simple_player_win << " / draw : " << simple_player_draw
		 << " / 승률 : " << win_rate_simple_player << "%" << " / 남은 돈 : " << simple_player_money << endl;
	cout << endl;


	return 0;
}