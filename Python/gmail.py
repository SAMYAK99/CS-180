import smtplib

user = str(input('Enter your email ID: '))
password = str(input('Password: '))

sent_from = user
receiver = str(input("Enter receiver address: "))
to = [receiver]
subject = str(input('Enter Subject: '))
body = str(input('Enter Content: '))

email_text = """\
From: %s
To: %s
Subject: %s

%s
""" % (sent_from, ", ".join(to), subject, body)

try:
    smtp_server = smtplib.SMTP_SSL('smtp.gmail.com', 465)
    smtp_server.ehlo()
    smtp_server.login(user, password)
    smtp_server.sendmail(sent_from, to, email_text)
    smtp_server.close()
    print ("Email sent successfully!")
except Exception as ex:
    print ("Something went wrong….",ex)