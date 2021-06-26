import datetime

a = datetime.datetime(2018, 6, 2, 9, 6, 1)
b = datetime.datetime(2017, 5, 1, 0, 0, 0)
c = a-b
days = c.total_seconds() / 86400
print(type(days))
print('Total difference in days: ', days)
