import urllib.request

f = open('input', 'w')

user_agent = 'Mozilla/5.0 (Windows; U; Windows NT 5.1; en-US; rv:1.9.0.7) Gecko/2009021910 Firefox/3.0.7'

webb = open('web', 'r')
s = webb.read()
# s = "https://codeforces.com/problemset/problem/1418/C"

url = s
headers = {'User-Agent': user_agent, }

request = urllib.request.Request(url, None, headers)
response = urllib.request.urlopen(request)
data = response.read()
f.write(str(data))
