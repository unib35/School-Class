def exam4():
    print("4. 자판기 문제")

    def start():
        print("메뉴 [1] 콜라(800원)  [2] 사이다(700원)  [3] 포카리스웨트(600원)  [4] 생수(500원)")

        insertcoin = int(input("투입하실 동전금액을 입력하세요 : "))
        if(insertcoin < 500):
            print("투입 금액이 부족합니다.")
        else:
            menu = int(input("음료 메뉴를 선택하세요 : "))
            if(menu == 1):
                price = 800
                beverage = "콜라"
            elif(menu == 2):
                price = 700
                beverage = "사이다"
            elif(menu == 3):
                price = 600
                beverage = "포카리스웨트"
            elif(menu == 4):
                price = 500
                beverage = "생수"

            count = int(input("수량을 입력하세요 : "))
            totalprice = count * price
            if(totalprice > insertcoin):
                print("결제 금액이 부족합니다.")

            else:
                returncoin = insertcoin - totalprice
                print("")
                print("{0} {1}개 구매완료".format(beverage, count))
                print("지불금액 : {0}원, 잔액 : {1}원".format(insertcoin, returncoin))
                print("")
                print("자판기 프로그램 종료") 
    start()
exam4()
