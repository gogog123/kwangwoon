#include <iostream>
#include "Buyer.h"
#include "Pharmacist.h"
using namespace std;

int main(void)
{
	Pharmacist pharmacist;
	Buyer buyer;
	int num;
	int mask_purchase;


	while (1)
	{
		cout << "0. 프로그램 종료" << endl;
		cout << "1. 마스크 재고 물어보기" << endl;
		cout << "2. 마스크 가격 물어보기" << endl;
		cout << "3. 마스크 구매하기" << endl;
		cout << "4. 내 마스크 갯수 확인하기" << endl;
		cout << "5. 내 지갑 확인하기" << endl;
		//input screen
		cin >> num;

		switch (num)
		{
		case 0:
			cout << "프로그램 종료" << endl;
			return 0;

		case 1:
			cout << "남은 마스크 갯수 : ";
			cout << pharmacist.Num_mask() << "개" << endl; //class pharmacist  print
			break;

		case 2:
			cout << "마스크 가격 :" << pharmacist.Mask_price() << "원" << endl; // class pharmacist print
			break;

		case 3:
			cout << "몇 개를 구매하시겠습니까?" << endl;
			cin >> mask_purchase; //input 
					if (mask_purchase > pharmacist.Num_mask() && 
						mask_purchase * pharmacist.Mask_price() > buyer.Change_money())
					{
						cout << "마스크 재고와 잔액 모두 부족합니다.\n";
					}
					else if (mask_purchase > pharmacist.Num_mask())
					{
						cout << "마스크 재고가 부족합니다.\n";
					}
					else if (mask_purchase * pharmacist.Mask_price() > buyer.Change_money())
					{
						cout << "잔액이 부족합니다.\n";
					}
					else
					{
						cout << mask_purchase << "개를 구매 완료." << endl;
						pharmacist.Purchase(mask_purchase);
						buyer.Purchase(mask_purchase);
						buyer.After_money(pharmacist.Mask_price(), mask_purchase);
						//change current mask num.
					} 
			break;

		case 4:
			cout << "내 마스크 갯수 : ";
			cout << buyer.Num_mask() << "개" << endl;
			break;

		case 5:
			cout << "내 잔액 : ";
			cout << buyer.Change_money() << "원" << endl;
			break;

		default:
			cout << "select num 0~5" << endl;
			break;
		}
		cout << endl;

	}

	return 0;
}