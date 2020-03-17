#!/usr/bin/python

import os
import time

from imapclient import IMAPClient
from max31850 import read_temp
 
HOSTNAME = 'imap.gmail.com'
MAILBOX = 'Inbox'
FROM_KEREM = 'kerem.yollu@gmail.com'
FROM_THOMAS = 'thomasgrob@hotmail.com'
MAIL_CHECK_FREQ = 60        # check mail every 60 seconds
 
# The following three variables must be customized for this
# script to work
USERNAME = 'ggbrauerei@gmail.com'
PASSWORD = 'ThomasGrob710'
NEWMAIL_OFFSET = 1          # my unread messages never goes to zero, use this to override
 
def mail_check():
   # login to mailserver
 	server = IMAPClient(HOSTNAME, use_uid=True, ssl=True)
 	server.login(USERNAME, PASSWORD)
 
 	# select our MAILBOX and looked for unread messages
	unseen = server.folder_status(MAILBOX, ['UNSEEN'])	
	newmail_count = (unseen[b'UNSEEN'])
	print('%d unseen messages' % newmail_count)

	select_info = server.select_folder('INBOX')	
	print('%d messages in INBOX' % select_info[b'EXISTS'])
	
 	messages_from_kerem = server.search(['FROM', FROM_THOMAS])
	print("%d messages from Thomas" % len(messages_from_kerem))	

	if len(messages_from_kerem) > 0:
		for mail_id, data in server.fetch(messages_from_kerem,['ENVELOPE','BODY[TEXT]']).items():
			envelope = data[b'ENVELOPE']
			body = data[b'BODY[TEXT]']
			print("%d messages from Thomas" % len(messages_from_kerem))	
			print('ID #%d: "%s" ' % (mail_id, envelope.subject.decode()))	
			if envelope.subject.decode() == "Temp":
				cmd_beginning = 'echo Temp = '
				cmd_end = 'C | msmtp thomasgrob@hotmail.com'
				cmd_temp = read_temp()
				cmd = cmd_beginning + cmd_temp + cmd_end  
				os.system(cmd)
				server.delete_messages(mail_id,False)
				print("Mail deleted")
	
 
while True:
	mail_check()
	time.sleep(MAIL_CHECK_FREQ)
