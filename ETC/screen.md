
### Start a new screen session
```bash
screen -S <name>
```

### Detaching From Screen

```bash
Command: "Ctrl-a" 누른 상태에서 "d"
```

### Reattach to Screen
단 하나의 session 만 있는 경우
```bash
screen -r
```
* 아래와 같이 하나 이상의 session이 있는 경우
```bash
screen -ls

6750.hello      (2018년 10월 10일 20시 40분 12초)       (Detached)
6730.working    (2018년 10월 10일 20시 31분 02초)       (Detached)
```
이라면, 

```bash
screen -r 6730
```

### Kill detached session
```bash
screen -S <name> -X quit
```

### Kill all windows and terminate screen
```
(C-a \) 
즉, Ctrl+a 를 누르고  \를 누름
```
https://www.gnu.org/software/screen/manual/html_node/Quit.html#Quit
