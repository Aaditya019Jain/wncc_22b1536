import requests
from bs4 import BeautifulSoup
import pandas as pd
req= requests.get("https://itc.gymkhana.iitb.ac.in/wncc/soc/")
soup=BeautifulSoup(req.content, "html.parser")
lst=[]
for text in soup.find_all( "p" ,class_="lead text-center font-weight-bold text-dark"):
    lst.append(text.get_text())
lst2=[]
lst3=[]
a="https://itc.gymkhana.iitb.ac.in"
for link in soup.find_all("a",href=lambda href: href and '/wncc/soc/projects/2023/project' in href):
    k=link.get("href")
    b=k
    url=a+b

    req1=requests.get(url)
    soup=BeautifulSoup(req1.content,"html.parser")
    for i in soup.find_all("li"):
          for x in i.find_all("p",class_="lead"):
               lst3.append(x.get_text())
    j=len(lst3)
    
    if j>1:
        g=""
        for d in lst3:
            g=g+d+" "+","
        lst2.append(g)
    lst3.clear()
result=list(zip(lst,lst2))
df=pd.DataFrame(result, columns=["NAME OF PROJECT","MENTORS, NUMBER OF MENTEES"])
print(df)

