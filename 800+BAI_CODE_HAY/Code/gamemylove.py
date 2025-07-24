import pygame 
import time
import random


pygame.init()
pink=(255,0,255)
green = (0, 255, 0)
white = (255, 255, 255)
yellow = (255, 255, 102)
black = (0, 0, 0)
red = (213, 50, 80)
green = (0, 255, 0)
blue = (50, 153, 213)
clock = pygame.time.Clock()
dis=pygame.display.set_mode((600,600))
high=600
width=600
dis.fill(blue)

SIZE=15

def paint(list_snake,foodx,foody):
	dis.fill("#2F4F4F")
	for x in list_snake:
		pygame.draw.circle(dis,"#FFFFFF",[x[0],x[1]],SIZE-5)
	pygame.draw.circle(dis,red,[foodx,foody],SIZE)
def check(x,y,foodx,foody):
	distance=((x-foodx)**2+(y-foody)**2)**0.5
	if int(distance) <= 2*SIZE:
		return True
	else:
		return False

def gameLoop():
	x=high/2
	y=width/2
	change_x=0
	change_y=0
	list_snake=[]
	leng=1
	foodx=random.randint(1,width-SIZE)
	foody=random.randint(1,high-SIZE)
	while True:
		for event in pygame.event.get():
			if event.type==pygame.KEYDOWN:
				if event.key==pygame.K_q:
					pygame.quit()
					quit()
				elif event.key==pygame.K_UP:
					change_y=-1
					change_x=0
				elif event.key==pygame.K_DOWN:
					change_y=1
					change_x=0
				elif event.key==pygame.K_LEFT:
					change_x=-1
					change_y=0
				elif event.key==pygame.K_RIGHT:
					change_x=1
					change_y=0	
		
		x+=change_x*SIZE
		y+=change_y*SIZE	
		if (y<1): y=high-SIZE
		if (y>high): y=SIZE
		if (x<1): x=width-SIZE
		if (x>width): x=SIZE
		if (check(x,y,foodx,foody)):
			foodx=random.randint(1,width-SIZE)
			foody=random.randint(1,high-SIZE)
			leng+=1
	
		pos_snake=[]
		pos_snake.append(x)
		pos_snake.append(y)
		list_snake.append(pos_snake)
		
		if (len(list_snake)>leng):
			list_snake.pop(0)
		
		paint(list_snake,foodx,foody)
		pygame.display.update()
		clock.tick(20)
gameLoop()
