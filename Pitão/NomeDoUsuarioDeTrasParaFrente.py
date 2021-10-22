
print('Pode digitar seu nome com letras maiúsculas, minúsculas ou mistas.')

nome = input('Digite seu nome: ').upper()

invNome = nome[::-1]

print('{} ---> {}'.format(nome, invNome)) 
