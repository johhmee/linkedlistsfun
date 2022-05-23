from unicodedata import name


class User:
    def __init__(self, userId, password):
        self.userId=userId
        self.password=password



userID1=input("Create a username: ")
password1=input("Create a password: ")
User1=User(userID1, password1)

print("Account created! Please Login again.")
loginUsername=input("Username: ")
while loginUsername!=userID1:
    print("No account found. Try Again.")
    loginUsername=input("Username: ")

loginPass=input("Password: ")
while loginPass!=password1:
    print("Wrong password. Try Again.")
    loginPass=input("Password: ")
else:
    print("Welcome back!")