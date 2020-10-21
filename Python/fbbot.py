import os
import json
import requests
from dotenv import load_dotenv
from fbchat import Client, log, MessageReaction
from fbchat.models import *

# load_dotenv()
# username = os.getenv("USERNAME")
# password = os.getenv("PASSWORD")
username = input("USERNAME")
password = input("PASSWORD")
#dotenv required for Heroku




class FBChatClient(Client):
    def onMessage(self,
                  mid=None,
                  author_id=None,
                  message=None,
                  message_object=None,
                  thread_id=None,
                  thread_type=ThreadType.USER,
                  ts=None,
                  metadata=None,
                  msg=None):
        self.markAsDelivered(thread_id, message_object.uid)
        self.markAsRead(thread_id)

        if author_id == self.uid:
            return

        if thread_type != ThreadType.USER:
            return

        if '/nepse' in message.lower():
            api_json = requests.get('http://api-nepse.herokuapp.com/todays_price').json()
            array_given = message.split()
            if(len(array_given) > 1):
                response = array_given[1].strip()
                if response.lower() == 'companies':
                    keys = api_json.keys()
                    i = 1
                    string = 'List of Symbols for checking NEPSE\n\n'
                    for key in keys:
                        string = string + str(i) + ') ' + key + '\n'
                        i += 1
                else:
                    try:
                        response = response.upper()
                        status = api_json[response]           
                        string = f"NEPSE Stats For {response}\n\n"
                        string += f"Name: {status['name']}\n"
                        string += f"Conf: {status['conf']}\n"
                        string += f"Open: {status['open']}\n"
                        string += f"High: {status['high']}\n"
                        string += f"Close: {status['close']}\n"
                        string += f"Turnover: {status['turnover']}\n"
                        string += f"Transfer: {status['transfer']}\n"
                        string += f"Diff: {status['diff']}\n"
                        string += f"Range: {status['range']}\n"
                        string += f"Diff Percent: {status['diff_per']}\n"
                        string += f"Range Percent: {status['range_per']}\n"
                        string += f"Vwap Percent: {status['vwap_per']}\n"
                        string += f"120 days: {status['120 days']}\n"
                        string += f"180 days: {status['180 days']}\n"
                        string += f"52 weeks High: {status['52 weeks high']}\n"
                        string += f"52 weeks Low: {status['52 weeks high']}"
                    except KeyError:
                        string = 'The symbol does not match any records! Please enter a valid symbol'
        else:
            string = 'A NEPSE stats bot \n\nSend "/nepse companies" to get symbols of Companies Listed in NEPSE\n\n Send /nepse <symbol> to get the stats for that company\n\nCoded by:  @scifidemon'
        self.send(Message(string), thread_id=thread_id)
        print(f">> {message}")
        print()
        print()

client = FBChatClient(username, password, logging_level=35)

if not client.isLoggedIn():
    client.login()

client.listen()
