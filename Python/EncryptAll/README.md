# Encrypt All

CLI-Based program to encrypt all files from directory and sub-directory provided directory path is given.

## Feature

- OS independent.
- Lightweight application.
- Minimal requirements to run the program.
- CLI-based program to encrypt every file.

## Installation

- Download [Python interpreter](https://www.python.org/downloads/)
- Navigate to the folder and install requirements
  > pip install -r requirements.txt
- All set to run the program

## Execution

- `python path/encryptall.py`
- Generate Key and then use the generated key for encryption and decryption (same key used for encryption).

### Demo

1. #### **_Test/test.txt_**

```
I'm here for testing.
```

2. #### Generating Key

```

  ██████████████████████████████████████████████████████
  █▄─▄▄─█▄─▄▄▀█─▄▄─█─█─█▄─▄█▄─▄─▀█▄─▄█─▄─▄─█▄─▄▄─█▄─▄▄▀█
  ██─▄▄▄██─▄─▄█─██─█─▄─██─███─▄─▀██─████─████─▄█▀██─██─█
  ▀▄▄▄▀▀▀▄▄▀▄▄▀▄▄▄▄▀▄▀▄▀▄▄▄▀▄▄▄▄▀▀▄▄▄▀▀▄▄▄▀▀▄▄▄▄▄▀▄▄▄▄▀▀
-----------------------------------------------------------

Generate Key: 0
Encrypt: 1
Decrypt: 2
Your Choice: 0
Generated Key: sB8mqQCYN1LMiscd0o2A1ZsQ-4vJClE4Q33pxnf2RHk=

Press key to exit...
```

3. #### Encrypting **_Test/test.txt_**

```
  ██████████████████████████████████████████████████████
  █▄─▄▄─█▄─▄▄▀█─▄▄─█─█─█▄─▄█▄─▄─▀█▄─▄█─▄─▄─█▄─▄▄─█▄─▄▄▀█
  ██─▄▄▄██─▄─▄█─██─█─▄─██─███─▄─▀██─████─████─▄█▀██─██─█
  ▀▄▄▄▀▀▀▄▄▀▄▄▀▄▄▄▄▀▄▀▄▀▄▄▄▀▄▄▄▄▀▀▄▄▄▀▀▄▄▄▀▀▄▄▄▄▄▀▄▄▄▄▀▀
-----------------------------------------------------------

Generate Key: 0
Encrypt: 1
Decrypt: 2
Your Choice: 1
Enter Key: sB8mqQCYN1LMiscd0o2A1ZsQ-4vJClE4Q33pxnf2RHk=

Enter Path: ./Test
Test\test.txt encrypted.

Press key to exit...
```

4. #### **_Test/test.txt_** after encryption

```
gAAAAABjQYMWt1d975aARvMBWe5jYQ-9dPSwUv1cNuqU6EOak8xdYyjjDN04uVA5OFxQ7GlqlY7D078f1eygUd4B2aul4chuGb2-igCnYZ4YQ31ePkYozEs=
```

5. #### Decrypting **_Test/test.txt_**

```
  ██████████████████████████████████████████████████████
  █▄─▄▄─█▄─▄▄▀█─▄▄─█─█─█▄─▄█▄─▄─▀█▄─▄█─▄─▄─█▄─▄▄─█▄─▄▄▀█
  ██─▄▄▄██─▄─▄█─██─█─▄─██─███─▄─▀██─████─████─▄█▀██─██─█
  ▀▄▄▄▀▀▀▄▄▀▄▄▀▄▄▄▄▀▄▀▄▀▄▄▄▀▄▄▄▄▀▀▄▄▄▀▀▄▄▄▀▀▄▄▄▄▄▀▄▄▄▄▀▀
-----------------------------------------------------------

Generate Key: 0
Encrypt: 1
Decrypt: 2
Your Choice: 2
Enter Key: sB8mqQCYN1LMiscd0o2A1ZsQ-4vJClE4Q33pxnf2RHk=


Enter Path: ./Test
Test\test.txt decrypted.

Press key to exit...
```

6. #### **_Test/test.txt_** after decryption

```
I'm here for testing.
```
