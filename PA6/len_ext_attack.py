import sys, urllib.parse, codecs
from pymd5 import md5, padding
url = sys.argv[1]

# Your code to modify url goes here
sign1 = url.find("=")
sign2 = url.find("&")
token = url[sign1+1:sign2]
msg = url[sign2+1:]
# print(msg)
msg_len = len(msg)
m_len = 8 + msg_len
bits = (m_len + len(padding(m_len*8)))*8
# print(bits)
h = md5(state=codecs.decode(token, "hex"), count=bits)#1024
h.update("&command3=UnlockAllSafes")
new_token = h.hexdigest()
# print(new_token)

new_url = url[:sign1+1] + new_token + "&" + msg + urllib.parse.quote(padding(m_len*8)) + "&command3=UnlockAllSafes"
print(new_url)
