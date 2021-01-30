'''
# 2020년 2학기 03분반 기말 고사
- 메인 프로그램을 비롯해서 반드시 기존 코드 수정없이,
각 문제의 주석 및 실행 예에 부합하고, 전체 프로그램이 정상 동작하도록
각 사용자 정의 함수의 pass 명령을 지우고, 몸체를 완성하시오.
- "학번_이름.py"로 파일 변경 후, 제출하고 감독자에게 확인 받을 것!
'''

'''문제1: "OOO은(는) 명예를 걸고 부끄럼 없이 정직하게 시험에 임할 것을 서약합니다."을 
화면 출력(각자 이름으로 변경)하는 아래 함수 완성'''
def test1():
    print('''"홍세정은(는) 명예를 걸고 부끄럼 없이 정직하게 시험에 임할 것을 서약합니다."''')


'''문제2: 실행 예와 같이, 반복문을 이용하여 1에서 9사이의 숫자를 입력받아 입력받은 숫자의 절에 해당하는 
구구단을 출력하는 함수 완성. 1에서 9이외의 숫자가 입력되면 다시 입력 받도록 처리
실행 예)
1에서 9까지의 수를 입력하세요: 11
1에서 9까지의 수를 입력하세요: 2
2*1= 2 2*2= 4 2*3= 6
2*4= 8 2*5=10 2*6=12
2*7=14 2*8=16 2*9=18
'''

def test2():
    i = int(input('1에서 9까지의 수를 입력하세요: '))
    for a in range(1, 10):
        print('{}*{}= {:2}'.format(i, a, i*a), end=" ")
        if(a%3==0):
            print("")



''' 문제3: 소수란 양의 자연수 중에서 1과 자기 자신이외의 약수를 가지지 않는 수를 말한다. 
양의 정수를 전달받아서 이 숫자가 소수인지 아닌지를 판별하여 True/False를 반환하는 함수 완성'''
def test3(prime):
    for i in range (2, prime):
        if prime % i == 0:
            return False
    return True



''' 문제4: 전달받은 임의의 문자열들 중에서 가장 길이가 짧은 문자열을 출력하는 아래 함수 완성
실해 예)
가장 길이가 짧은 문자열은 wiz
'''
def test4(*str):
    n = 0
    for i in range(0, len(str)-1):
        if len(str[i]) > len(str[i+1]):
            n = i+1
    print('가장 길이가 짧은 문자열은', str[n])


'''문제5: 실행 예와 같이 임의로 5개의 정수를 입력받아서 리스트에 저장하고 평균(mean)과 
표준편차(std)를 반환하는 아래 함수 완성. 
std => 분산의 제곱근, 분산 => 편차(평균 - 원소) 제곱의 평균
실행 예)
5개 정수 입력: 45,67,20,34,2
평균: 33.60, 표준편차: 22.04
'''
def test5():
     num1, num2, num3, num4, num5 = input('5개 정수 입력: ').split(',')
     list = [int(num1), int(num2), int(num3), int(num4), int(num5)]
     print(list)
     mean = 0
     std = 0
     for i in range(0, 5):
         mean += list[i]

     mean = mean/5.0
     
     for i in range(0,5):
         std += (list[i]-mean)**2
         
     std = std/5.0
     std = std**0.5
     
     return mean, std

'''문제6: 실행 예와 같이 딕셔너리를 이용해서 이름, 전화번호 저장. 그리고, 이름 입력없이 
엔터키를 치면 검색모드, 검색모드에서는 이름으로 전화번호 검색 가능, 검색모드에서 입력없이 
엔터키를 치면 프로그램 종료하는 아래 함수 완성
실행 예)
(입력모드)이름을 입력하시오: 홍길동
전화번호를 입력하시오: 010-1111-2222
(입력모드)이름을 입력하시오: 유관순
전화번호를 입력하시오: 010-2222-3333
(입력모드)이름을 입력하시오: 
(검색모드)이름을 입력하시오: 이순신
이순신 는 없는 번호입니다.
(검색모드)이름을 입력하시오: 유관순
유관순 의 전화번호는 010-2222-3333 입니다.
(검색모드)이름을 입력하시오:
프로그램 종료...
'''
def test6():
    person = {}
    while True:
        name = input('(입력모드)이름을 입력하시오: ')

        if not name:
            while True:
                name_search = input('(검색모드)이름을 입력하시오: ')
                if not name_search:
                    print('프로그램 종료...')
                    return
                if person.get(name_search) is None:
                    print('{} 는 없는 번호입니다.'.format(name_search))
                else:
                    print('{} 의 전화번호는 {} 입니다.'.format(name_search, person[name_search]))

        else:
            phone = input('전화번호를 입력하시오: ')
            person[name] = phone
            print(person)


####### 메인 프로그램 시작 #######
test1()

print()

test2()

print()

n = int(input('숫자 입력: '))
if test3(n):
    print('{}(은)는 소수입니다.'.format(n))
else:
    print('{}(은)는 소수가 아닙니다.'.format(n))

print()

test4('dynos','bears','twins','wiz','heros')

print()

avg, std= test5()
print('평균: {:.2f}, 표준편차: {:.2f}'.format(avg, std))

print()


test6()

print()


