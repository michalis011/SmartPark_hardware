import os
import shutil
import time 

f_path=r'C:/Users/Mike/Desktop/4th year Group Project/Node-red/ANPR/svm_anpr/images/test_images/test_image.png'
t = os.path.getctime(r'C:/Users/Mike/Desktop/4th year Group Project/Node-red/ANPR/svm_anpr/images/test_images/test_image.png')
t_str = time.ctime(t)
t_obj = time.strptime(t_str) 
form_t = time.strftime("%Y-%m-%d %H:%M:%S", t_obj) 
form_t = form_t.replace(":", "꞉")
new_path =  os.path.split(f_path)[0] + '/' + form_t + os.path.splitext(f_path)[1]
os.rename(f_path, new_path)