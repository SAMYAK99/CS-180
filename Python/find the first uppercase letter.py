def find_uppercase_iterative(input_str):
    for i in range(len(input_str)):
        if(input_str[i].isupper()):
            return input_str[i]
    return 'no upper case letter found'

def find_uppercase_recursive(input_str,index=0):
    if(input_str[index].isupper()):
        return input_str[index]
    if(index==len(input_str)-1):
        return 'no uppercase letter found'
    return find_uppercase_recursive(input_str,index+1)

if __name__=='__main__':
    print(find_uppercase_iterative('alokDubey'))
    print(find_uppercase_recursive('AlokDubey'))