#calculator

first_no=int(input('enter the first number: '))

second_no=int(input('enter the second number: '))

operation=input('enter the operation: supported operations are +, -, *, /:')

if operation=='+':
    print("Addition:",first_no + second_no)
elif operation=='-':
    print('Substraction:',first_no - second_no)
elif operation=='*':
    print('Multiplication:',first_no * second_no)
elif operation=='/':
    if second_no != 0:
        print('Division:',first_no / second_no)
    else:
        print("Error: Division by zero is not allowed")
else:
    print("Invalid operation")