# Para criar o arquivo, execute o codigo da seguinte forma:
# python csv.py >> <filename>.txt

a = "1111010101010101010100101100101010101010101010100101001010101010101010111100011010111001011"
array = list(a)

for i in range(0,len(a),5):
    try:
        line="{},{},{},{},{}".format(a[i], a[i+1],a[i+2],a[i+3],a[i+4])
        print(line)
    except:
        print("FINISHED")
