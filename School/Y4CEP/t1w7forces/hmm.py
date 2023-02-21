import pyautogui
import time

time.sleep(2);
for i in range(10):
    if (i % 2 == 0):
        pyautogui.keyDown('w');
        pyautogui.keyDown('q');
        time.sleep(40);
        pyautogui.keyUp('w');
        pyautogui.keyUp('q');
    else:
        pyautogui.keyDown('s');
        pyautogui.keyDown('q');
        time.sleep(40);
        pyautogui.keyUp('s');
        pyautogui.keyUp('q');