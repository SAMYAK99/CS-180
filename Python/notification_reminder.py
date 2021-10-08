import time
from plyer import notification

msg = input("Please enter the reminder message: ")
sleep_time = int(input("Enter time after which you want to be remineded: "))
timer = int(input("Enter the interval time: "))

while True:
    notification.notify(
        title="Hey there!",
        message=msg,
        # app_icon = "<path of the icon-image>",
        timeout=timer,
    )
    time.sleep(sleep_time)  # time is seconds
