#include<iostream>
using namespace std;

int main() {
    string msg;
    string key;

    cout << "Enter Message: ";
    cin >> msg;
    cout << "Enter Key: ";
    cin >> key;

    int msgLength = msg.length();
    int keyLength = key.length(); 
    char generatedKey[msgLength], encryptedMsg[msgLength], decryptedMsg[msgLength];

    int i = 0, j = 0;
    while(i < msgLength) {
        if(j == keyLength) {
            j = 0;
        }
        generatedKey[i] = key[j];
        j++;
        i++;
    }
    generatedKey[i] = '\0';

    for(i = 0; i < msgLength; i++) {
        encryptedMsg[i] = ((msg[i] + generatedKey[i]) % 26)+'A';
    }
    encryptedMsg[i] = '\0';

    for(i = 0; i < msgLength; i++) {
        decryptedMsg[i] = ((encryptedMsg[i] - generatedKey[i]+26) % 26)+'A';
    }
    decryptedMsg[i] = '\0';

    cout << "\nMessage: " << msg << endl;
    cout << "Key: " << key << endl;
    cout << "Generated Key: " << generatedKey << endl;
    cout << "Encrypted Message: " << encryptedMsg << endl;
    cout << "Decrypted Message: " << decryptedMsg << endl;

    return 0;
}