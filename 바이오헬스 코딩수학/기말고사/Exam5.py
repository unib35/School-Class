import random
def exam5():
  def userCho():
    usercho = input("가위 바위 보 중에 하나를 입력하세요 : ")
    print("당신은 {0}을 내셨습니다.".format(usercho))
    return usercho

  def comCho():
    comcho = random.randrange(1,4)
    if(comcho == 1):
      print("컴퓨터는 가위를 냈습니다.")
      return "가위"
    elif(comcho == 2):
      print("컴퓨터는 바위를 냈습니다.")
      return "바위"
    elif(comcho == 3):
      print("컴퓨터는 보를 냈습니다.")
      return "보"


  def gamedecision(x, y):
    if(x == y):
      print("무승부입니다.")
    elif(x == "가위"):
      if(y == "보"):
        print("당신의 승리입니다.")
      elif(y == "바위"):
        print("컴퓨터의 승리입니다.")
    elif(x == "바위"):
      if(y == "가위"):
        print("당신의 승리입니다.")
      elif(y == "보"):
        print("컴퓨터의 승리입니다.")
    elif(x == "보"):
      if(y == "바위"):
        print("당신의 승리입니다.")
      elif(y == "가위"):
        print("컴퓨터의 승리입니다.")  
    
  


  def StartGame():
    print("안녕하세요 가위바위보 게임을 시작합니다.")
    usercho = userCho()
    comcho = comCho()
    gamedecision(usercho, comcho)
  
    game = input("게임을 계속합니다. 엔터를 누르세요 종료를 원하시면 0 을 누르세요\n")
    if game == "0":
      print("종료합니다.")
    else:
      StartGame()
  
  StartGame()
exam5()

  
