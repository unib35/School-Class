import random
def exam6():
  print("6. 주사위 문제")
  def userDice():
    userdice = random.randrange(1,7)
    return userdice
  def comDice():
    comdice = random.randrange(1,7)
    return comdice

  def startGame():
    usersum = 0
    comsum = 0
    for i in range(5):
      userdice = userDice()
      comdice = comDice()
      usersum += userdice
      comsum += comdice
      print("{0}번째 주사위".format(i+1))
      print("사용자 : {0}".format(userdice))
      print("컴퓨터 : {0}".format(comdice))
      print("")
      
    
    
    print("사용자 합계 : {0}".format(usersum))
    print("컴퓨터 합계 : {0}\n".format(comsum))  
    
    
    if(usersum >= 20 and usersum >= comsum):
      print("!!사용자 승리!!")
    elif(comsum >= 20 and comsum >= usersum):
      print("!!컴퓨터 승리!!")
    else:
      print("둘다 20미만으로 무승부")
  startGame()
  
exam6()
