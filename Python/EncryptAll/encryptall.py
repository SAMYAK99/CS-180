"""
CLI based encryption to encrypt every file in specified directory and it's sub directory.
Generate Key for encryption and decryption.
Encrypt with generated key, files need to be decrypted with the same key used for encryption. If same key not provided error will be raised
Same key can be used to encrypt multiple files, multiple times.
"""
from cryptography.fernet import Fernet
from os import system, name
from pathlib import Path

prohibited = """
  ██████████████████████████████████████████████████████
  █▄─▄▄─█▄─▄▄▀█─▄▄─█─█─█▄─▄█▄─▄─▀█▄─▄█─▄─▄─█▄─▄▄─█▄─▄▄▀█
  ██─▄▄▄██─▄─▄█─██─█─▄─██─███─▄─▀██─████─████─▄█▀██─██─█
  ▀▄▄▄▀▀▀▄▄▀▄▄▀▄▄▄▄▀▄▀▄▀▄▄▄▀▄▄▄▄▀▀▄▄▄▀▀▄▄▄▀▀▄▄▄▄▄▀▄▄▄▄▀▀\n"""
line = "-----------------------------------------------------------\n"


def clearConsole():
    command = "clear"
    if name in ("nt", "dos"):
        command = "cls"
    system(command)
    print(prohibited + line)


def main():
    clearConsole()
    selection = int(input("Generate Key: 0\nEncrypt: 1\nDecrypt: 2\nYour Choice: "))
    if selection == 0:
        key = Fernet.generate_key().decode("utf-8")  # Generate Key
        print(f"Generated Key: {key}")
    elif selection == 1:
        key = input("Enter Key: ")
        clearConsole()
        fernet = Fernet(key)
        user_path = input(r"Enter Path: ")  # Path to directory to encrypt it's files and subdirectory files.
        for path in Path(user_path).rglob("*.*"):  # Pattern to filter which file to encrypt for e.g. for pdf *.pdf
            with open(rf"{path}", "rb") as file:
                original = file.read()  # reading file
            encrypted = fernet.encrypt(original)  # encrypting file
            with open(rf"{path}", "wb") as encrypted_file:
                encrypted_file.write(encrypted)  # writing encrypted file
            print(rf"{path} encrypted.")
    elif selection == 2:
        key = input("Enter Key: ")
        clearConsole()
        fernet = Fernet(key)
        user_path = input(r"Enter Path: ")  # Path to directory to encrypt it's files and subdirectory files.
        for path in Path(user_path).rglob("*.*"):  # Pattern to filter which file to encrypt for e.g. for pdf *.pdf
            with open(rf"{path}", "rb") as enc_file:
                encrypted = enc_file.read()  # reading encrypted file
            decrypted = fernet.decrypt(encrypted)  # decrypting file
            with open(rf"{path}", "wb") as dec_file:
                dec_file.write(decrypted)  # writing decrypted file
            print(rf"{path} decrypted.")
    else:
        raise Exception


if __name__ == "__main__":
    try:
        main()
    except Exception as e:
        print(e, "\nFired...")
    finally:
        input("\nPress key to exit...")
