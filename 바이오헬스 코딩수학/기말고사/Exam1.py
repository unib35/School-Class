def exam1():
    print("1. 나이계산 문제")
    def getName():
        userName = input("이름을 입력하세요 : ")
        return userName

    def getYear():
        birthYear = int(input("출생연도를 입력하세요 : "))
        return birthYear

    def printAge(userName, age):
        print("{0}님의 나이는 {1}세 입니다.".format(userName, age))
        
    def countAge():
        userName = getName()
        birthYear = getYear()
        currentYear = 2022
        age = currentYear - (birthYear - 1)
        printAge(userName, age)

    countAge()
#xam1()
