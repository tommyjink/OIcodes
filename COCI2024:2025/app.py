v=float(input())
if(v!=int(v)):v=int(v)+1
if(v<=2):print("10")
elif(v<=5):print(int(10+(v-2)*8))
elif(v<=10):print(int(34+(v-5)*6))
else:print(int(64+(v-10)*5))