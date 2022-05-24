import random

mycount = 0
def exam7():
  print("\n7. 윷놀이 문제")
  yuts = []
  
  def yutGame():
    game = input("윷을 던질까요? (y/n)\n")

    if game == 'y':
      yuts.append(yutPlay())
      print(yuts)

      global mycount
      mycount += 1
      yutGame()

    elif game == 'n':
      displayStatic()
      print("게임을 종료합니다.")
      return
      
    else:
      print("입력 오류로 게임을 종료합니다.")
      return
    
  def displayStatic():
    global mycount
    print("총",mycount, "회 던졌습니다.")
    
    print("도는", yuts.count("도"),"회 나왔습니다.")
    print("개는", yuts.count("개"),"회 나왔습니다.")
    print("걸는", yuts.count("걸"),"회 나왔습니다.")
    print("윷는", yuts.count("윷"),"회 나왔습니다.")
    print("모는", yuts.count("모"),"회 나왔습니다.")

  def yutPlay():
    yut = []

    for i in range(1,5):
      yut.append(random.randrange(0,2))
    print(yut)
    yutSum = sum(yut)

    if int(yutSum) == 0:
      print("윷")
      return "윷"

    elif int(yutSum) == 1:
      print("도")
      return "도"

    elif int(yutSum) == 2:
      print("개")
      return "개"  

    elif int(yutSum) == 3:
      print("걸")
      return "걸"

    elif int(yutSum) == 4:
      print("모")
      return "모"

  yutGame()
exam7()