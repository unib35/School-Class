def exam2():
    print("2. 사칙연산 문제")
    firstNum = int(input("첫번째 숫자를 입력하세요 : "))
    secondNum = int(input("두번째 숫자를 입력하세요 : "))
    oper = input("연산자를 입력하세요(사칙연산) : ")

    if(oper == '+'):
        result = firstNum + secondNum
        print("두수의 합은 {0} 입니다.".format(result))
    elif(oper == '-'):
        result = firstNum - secondNum
        print("두수의 차는 {0} 입니다.".format(result))
    elif(oper == '*'):
        result = firstNum * secondNum
        print("두수의 곱은 {0} 입니다.".format(result))
    elif(oper == '-'):
        result = firstNum / secondNum
        print("두수의 나누기는 {0} 입니다.".format(result))
    else:
        print("연산자를 잘못입력하셨습니다.")

exam2()
