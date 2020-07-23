#!/bin/bash
cat << "EOF" | openssl dgst -sha256 > DIGEST
       [��=z�}B0�^,Le�;g�D�I
A
�,�]]���҆�O"����#��}����A;?��Z`7��Ię�r/C������!E�p۱)� h�_h��-*�qz�;���WM���H���*p߾���
EOF
digest=$(cat DIGEST | sed 's/(stdin)= //' )
echo "The sha256 digest is $digest"
