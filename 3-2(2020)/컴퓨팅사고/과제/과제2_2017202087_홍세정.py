#과제2_2017202087_홍세정
#문자열을 압축 또는 해제

def Compact(string):  #압축하는 함수
    compact = "" #압축하여 출력될 문자열
    n = 1 #압축된 개수
    for i in range(1, len(string)):
        
        if string[i-1] == string[i]: #앞문자와 뒤문자가 같을때 n 증가 
            n = n + 1
            
        else:
            compact = compact + string[i-1] + str(n) #압축된 결과 저장
            n = 1
            
    compact = compact + string[i] + str(n)
    print(compact)
    
    print("압축 결과>>> ", compact) #압축된 문자열 출력


def Decompact(string): #압축해제하는 함수 
    decompact = "" #압축해제하여 출력될 문자열
    
    for i in range(1, len(string), 2):
        for j in range(0, int(string[i])): #압축된 수만큼 반복하여 저장
            decompact = decompact + string[i-1]
            
    print("해제 결과>>> ", decompact) #압축해제된 문자열 출력
    

    
while 1:
    menu = input("*** 메뉴 선택 (문자열 압축은 1번, 해제는 2번,  종료는 엔터): ")
    if menu == '1': #문자 1 입력했을때 
        a = input("- 압축할 문자열 입력: ")
        Compact(a)
    
    elif menu == '2': #문자 2 입력했을때
        a = input("- 해제할 문자열 입력: ")
        Decompact(a)

    elif not menu: #아무것도 입력되지 않았을 때
        print("종료")
        break
    
    else: #else
        print('')
