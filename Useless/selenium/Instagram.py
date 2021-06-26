# import {{{
from selenium import webdriver
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.common.keys import Keys
import datetime
import time
# }}}

# Getting driver {{{
driver = webdriver.Chrome()
# }}}

# Global varaible {{{
email_id = ''
password = ''
account_name = ''
# }}}

# maximize window {{{
# driver.maximize_window()
# }}}

# open instagram {{{
driver.get('https://www.instagram.com/')
# }}}

# function to return element of xpath {{{
def Get(Xpath):
    element = WebDriverWait(driver, 20).until(EC.element_to_be_clickable((By.XPATH, Xpath)))
    return element
# }}}

# click log in facebook button {{{
logwithfacebook_button = Get('//*[@id="loginForm"]/div/div[5]/button')
logwithfacebook_button.click()
# }}}

# log with facebook {{{
emailid_input_field = Get('//*[@id="email"]')
emailid_input_field.send_keys(email_id)
passwordid_input_field = Get('//*[@id="pass"]')
passwordid_input_field.send_keys(password)
login_button = driver.find_element_by_xpath('//*[@id="loginbutton"]')
login_button.click()
# }}}

# click not now {{{
notnow_button = Get('/html/body/div[4]/div/div/div/div[3]/button[2]')
notnow_button.click()
# }}}

# Search 'account_name' {{{
search_button = Get('//*[@id="react-root"]/section/nav/div[2]/div/div/div[2]/div/div')
search_button.click()
search_button_input = Get('//*[@id="react-root"]/section/nav/div[2]/div/div/div[2]/input')
search_button_input.send_keys(account_name)
time.sleep(2)
search_button_input.send_keys(Keys.ENTER)
search_button_input.send_keys(Keys.ENTER)
# }}}

# (almost) Smooth scroll {{{
# SCROLL_PAUSE_TIME = .01
# height = 0

# while True:
    # height += 5
    # s1 = "window.scrollTo(0, " + str(height) + ");"
    # driver.execute_script(s1)

    # time.sleep(SCROLL_PAUSE_TIME)
# }}}

# select first pic {{{
# pic_1 = driver.find_element_by_xpath('//*[@id="react-root"]/section/main/div/div[3]/article/div[1]/div/div[1]/div[1]/a/div[1]/div[2]')
# pic_1.click()

# time.sleep(10)

# back_button = driver.find_element_by_xpath('/html/body/div[4]/div[3]/button')
# back_button.click()
# driver.back()
# }}}

# Loop through all post {{{
all_pic = driver.find_elements_by_class_name('_9AhH0')

print(len(all_pic), flush=True)
print(flush=True)

all_pic[0].click()

while True:
    # pic.click()
    time.sleep(2)
    # all_img = driver.find_elements_by_xpath("//img[not(@sizes='293px') and @class='FFVAD']")
    # print(len(all_img), flush=True)
    xpath_like_button = "/html/body/div[4]/div[2]/div/article/div[3]/section[1]/span[1]/button/div/span//*[@class='_8-yf5 ']"
    like_button = driver.find_element_by_xpath(xpath_like_button)
    print(like_button.get_attribute('aria-label'), flush=True)
    get_label = like_button.get_attribute('aria-label')
    assert type(get_label) == str
    if (get_label == "Unlike"):
        like_button = driver.find_element_by_xpath("//span[@class='fr66n']//button[@class='wpO6b ' and @type='button']")
        like_button.click()
    time.sleep(2)
    next_button = driver.find_element_by_xpath("//a[text()='Next']")
    next_button.click()
#  }}}
