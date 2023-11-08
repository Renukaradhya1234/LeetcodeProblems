def user_range(start , end = 0, updation = 1):
  start, end = start if end > 0 else end, end if end > 0 else start
  while start < end:
    yield start
    start += updation
