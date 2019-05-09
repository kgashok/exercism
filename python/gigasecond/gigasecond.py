import datetime 

def add_gigasecond(start):
    gigasecond = datetime.timedelta(seconds=10**9)
    print(gigasecond)
    return start + gigasecond