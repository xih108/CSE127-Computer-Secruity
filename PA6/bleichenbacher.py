from Crypto.PublicKey import RSA
from Crypto.Hash import SHA
from roots import *
import sys
 
message = sys.argv[1]
# Your code to forge a signature goes here.

# some example functions from roots


sha = SHA.new(str.encode(message)).hexdigest()
ASN = "3021300906052B0E03021A05000414"
fix = "0001FFFF00" + ASN + str(sha)
signature = int(fix + 'FF'*(2048//8 -38-2),16)
root, is_exact = integer_nthroot(signature, 3)
print(integer_to_base64(root).decode())

