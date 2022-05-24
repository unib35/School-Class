def exam3():
    print("3. 별표 피라미드 문제")
    def star1(starNum):
        for i in range(1,starNum+1):
            print("*" * i)

    def star2(starNum):
        for i in range(starNum, 0, -1):
            print("*" * i)

    def star3(starNum):
        for i in range(1,starNum+1):
            print(" " * (starNum - i),end="")
            print("*" * i)

    def star4(starNum):
        for i in range(starNum, 0, -1):
            print(" " * (starNum - i),end="")
            print("*" * i)
            

    def Star():
        if(starMenu == 1):
            star1(starNum)
        elif(starMenu == 2):
            star2(starNum)
        elif(starMenu == 3):
            star3(starNum)
        elif(starMenu == 4):
            star4(starNum)
        else:
            print("메뉴를 잘못입력하셨습니다.")

    while True:
        starNum = int(input("별의 개수를 입력하세요 : "))
        print("1. 왼쪽-위 2. 왼쪽-아래 3.오른쪽-위 4.오른쪽-아래 0. 종료")
        starMenu = int(input("메뉴번호를 입력하세요 : "))
        
        if(starMenu == 0):
            print("별찍기를 종료합니다.")
            break
        Star()
exam3()
