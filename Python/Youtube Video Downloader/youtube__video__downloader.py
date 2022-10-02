from pytube import YouTube

print("\n")
url = input("Enter the URL: ")

print("\n")
response = input("Do you want video or audio file: ") 

video_url = YouTube(url)


if response == "audio":
	try:
		SAVE_PATH = "C:\\Users\\Prabin\\Music\\Music"
		available_streams =video_url.streams
		first_stream = video_url.streams.filter(type = "audio",file_extension = "mp4").first()	
		print("\n")
		print("------Downloading Audio file---------")
		print("\n")
		print("Title: " + video_url.title)		
		print("\n")
		print("Duration: " + str(video_url.length) + " seconds")	
		print("\n")
		first_stream.download(SAVE_PATH)	
		print("------Download Complete------")
	except:
		print("\n")
		print("Some Error Occured!!")

elif response == "video":
	try:
		SAVE_PATH = "C:\\Users\\Prabin\\Videos"
		available_streams =video_url.streams
		first_stream = video_url.streams.filter(type = "video",progressive = True,file_extension = "mp4").first()	
		print("\n")
		print("------Downloading Video file---------")
		print("\n")
		print("Title: " + video_url.title)		
		print("\n")
		print("Duration: " + str(video_url.length) + " seconds")	
		print("\n")
		first_stream.download(SAVE_PATH)	
		print("------Download Complete------")
	except:
		print("\n")
		print("Some Error Occured!!")
