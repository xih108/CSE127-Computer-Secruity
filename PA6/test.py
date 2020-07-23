import crypto
import sys 
sys.modules['Crypto'] = crypto
from crypto.PublicKey import RSA
from crypto.Hash import SHA
from roots import *
 
#message = sys.argv[1]
# Your code to forge a signature goes here.

# some example functions from roots

# signature = int(open('sig', 'rb').read().hex(), 16)
# print(signature)
pubkey = RSA.importKey(open('key.pub').read( ))
signature = int(open('sig', 'rb').read().hex(), 16)
print(SHA.new(b"CSE 127 rul3z!").hexdigest())
print("{:0512x}".format(pow(signature, pubkey.e, pubkey.n)))
