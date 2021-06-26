import requests
import bs4
print(bs4.BeautifulSoup("<html><head></head><body>Sacr&eacute; bleu!</body></html>", "html.parser").get_text())
