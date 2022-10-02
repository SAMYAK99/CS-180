'''
    input = playlist id
    output = total number of videos and duration
'''
from googleapiclient.discovery import build
import math
from datetime import datetime, timedelta


token = 1
video_ids = []

API_KEY = 'YOUR-API-KEY'

def append_video_ids(json_data):
    """parses the JSON data to consolidate all video ids in a list"""
    json_data = json_data['items']
    for item in json_data:
        video_ids.append(item['contentDetails']['videoId'])


def playlist_duration_finder(pl_id):
    # playlist ID
    if '=' in pl_id:
        pl_id = pl_id.split('=')
        try:
            pl_id = pl_id[2]
        except:
            pl_id = pl_id[1]
    else:
        pl_id = pl_id

    # youtube api

    youtube = build('youtube', 'v3', developerKey = API_KEY)

    response=youtube.playlistItems().list(
        part='contentDetails, snippet',
        maxResults=500,
        playlistId=pl_id
    )

    response = response.execute()

    append_video_ids(response)

    while token:
        if 'nextPageToken' in response:
            new_response = youtube.playlistItems().list(
                part='contentDetails, snippet',
                maxResults=500,
                playlistId=pl_id,
                pageToken=response['nextPageToken']
            )
            response = new_response.execute()
            append_video_ids(response)
        else:
            break

    all_time=[]

    # getting duration for all video ids in ISO format
    for item in video_ids:
        response = youtube.videos().list(
            part='contentDetails',
            id=item
        )
        response=response.execute()

        if response['items'] != []:
            all_time.append(response['items'][0]['contentDetails']['duration'])

    formatted_time=[]

    # formatting time from ISO format to hh mm ss
    for time in all_time:

        if 'H' in time:
            total_time=time.split('PT')  # ['', 3h12m4s]

            hours=total_time[1].split('H')  # 3h12m4s > [3, 12m4s]

            minutes=hours[1].split('M')  # [12, 4s]
            seconds=minutes[1].split('S')

            if minutes[0] == '':
                minutes[0]='00'

            if seconds[0] == '':
                seconds[0]='00'

            x=f'{hours[0]}:{minutes[0]}:{seconds[0]}'
            formatted_time.append(x)

        elif 'M' in time:
            total_time=time.split('PT')  # ['', 'xmys']
            minutes=total_time[1].split('M')  # ['x','ys']
            seconds=minutes[1].split('S')  # ['y','s']

            if seconds[0] == '':
                seconds[0]='00'

            x=f'00:{minutes[0]}:{seconds[0]}'
            formatted_time.append(x)

        else:
            total_time=time.split('PT')  # ['', 'ys']
            seconds=total_time[1].split('S')  # ['y','s']

        x=f'00:00:{seconds[0]}'
        formatted_time.append(x)

    # summing all times
    d = 0
    h = 0
    m = 0
    s = 0

    for x in formatted_time:
        stripped_time = datetime.strptime(x, '%H:%M:%S')
        y = str(stripped_time)
        y = y.split()[1]
        y = y.split(':')
        hrs = int(y[0])
        mins = int(y[1])
        secs = int(y[2])

        a = timedelta(hours=hrs, minutes=mins, seconds=secs)
        b = timedelta(days=d, hours=h, minutes=m, seconds=s)

        entire_time = a + b

        d = entire_time.days  # d done

        s = entire_time.seconds

        h = math.floor((s / 3600))  # hours
        rem = s % 3600  # remaining seconds
        m = math.floor((rem / 60))
        s = s % 60

    entire_time = str(entire_time)

    # more than a day
    if ',' in entire_time:
        entire_time = entire_time.split(',')
        d = entire_time[0]
        h = entire_time[1].split(':')[0]
        m = entire_time[1].split(':')[1]
        s = entire_time[1].split(':')[2]

        return f'''Total playback time for the given playlist: {d}{h} hours {m} minutes {s} seconds'''

    elif ':' in entire_time:
        h = entire_time.split(':')[0]
        m = entire_time.split(':')[1]
        s = entire_time.split(':')[2]

        return f'''Total playback time for the given playlist : {h} hours {m} minutes {s} seconds'''


def total_videos():
    """returns total number of videos in given playlist"""

    return f'Total number of videos in this playlist: {len(video_ids)}'

if __name__ == "__main__":
    playlist_id = input('Enter a valid YouTube Playlist Link: ')

    duration = playlist_duration_finder(playlist_id)
    print(duration)

    total_number_of_videos = total_videos()
    print(total_number_of_videos)
