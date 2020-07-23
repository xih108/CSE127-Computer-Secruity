
import crypto
import sys

sys.modules['Crypto'] = crypto
from crypto.PublicKey import RSA
from crypto.Hash import SHA


signature = int(open('sig', 'rb').read().hex(), 16)
print(signature)
pubkey = RSA.importKey(open('key.pub').read())
from Crypto.PublicKey import RSA
print("{:0128x}".format(pow(signature, pubkey.e, pubkey.n)))
print(SHA.new(b"CSE 127 rul3z!").hexdigest())
