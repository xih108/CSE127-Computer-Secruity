from requests import HTTPSession

# Make a connection pool.
http = HTTPSession()

# Make a request.
r = http.request('get', 'https://c10-32.sysnet.ucsd.edu/challenges/challenge/')

# View response data.
r.json()