from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import time
import urllib.request

driver = webdriver.Chrome()

# fireup chrome {{{
driver.get('https://instagram.fknu1-1.fna.fbcdn.net/v/t51.2885-15/sh0.08/e35/s640x640/120844076_376511980198915_5499180540948661245_n.jpg?_nc_ht=instagram.fknu1-1.fna.fbcdn.net&_nc_cat=107&_nc_ohc=PPJHjPTEWI0AX-qR4Rc&oh=9c5e93bd4eb0d91ea04dfc627f3a12aa&oe=5FA93370')
# }}}

img = driver.find_element_by_xpath('/html/body/img')
src = img.get_attribute('src')

time.sleep(5)

urllib.request.urlretrieve(src, 'asdfghjkl;')
