import re, sys, svgelements as se
# Cuts the start menu title's letters out of L's vector trace of u/Plebian_Donkey_Konga's lettering
# sheet (L, 2026-10-24). Usage: python3 tools/split_title_letters.py assets/launcher/title-font-source.svg assets/launcher
src=open(sys.argv[1]).read(); out=sys.argv[2]
# Each traced path, split into its subpaths, so a shape that runs over two letters is shared out.
items=[]
for el in re.findall(r'<path [^>]*/>',src):
    fill=re.search(r'fill="([^"]+)"',el).group(1)
    d=re.search(r' d="([^"]+)"',el).group(1)
    subs=['M'+s for s in d.strip().split('M') if s.strip()]
    items.append((fill,[(s,se.Path(s).bbox()) for s in subs]))
# Each letter's box on the sheet (sheet units); a subpath goes to the letter whose box holds it.
letters={'b':(137,26,230,140),'a':(4,38,140,140),'n':(560,188,662,286),'j':(124,154,190,303),'o':(686,195,791,281),
 'e_blue':(456,549,556,660),'i_blue':(55,680,112,808),'o_blue':(704,720,808,806),'r_blue':(148,862,277,977),'t_blue':(379,841,495,961)}
m=4
for k,(x0,y0,x1,y1) in letters.items():
    els=[];bb=[]
    for fill,subs in items:
        sel=[(s,b) for s,b in subs if b and b[0]>=x0-m and b[1]>=y0-m and b[2]<=x1+m and b[3]<=y1+m]
        if sel:
            els.append(f'<path fill="{fill}" d="{" ".join(s for s,_ in sel)}"/>'); bb+= [b for _,b in sel]
    bx0=min(b[0] for b in bb)-1; by0=min(b[1] for b in bb)-1; bx1=max(b[2] for b in bb)+1; by1=max(b[3] for b in bb)+1
    open(f'{out}/title_{k}.svg','w').write(f'<svg xmlns="http://www.w3.org/2000/svg" viewBox="{bx0:.2f} {by0:.2f} {bx1-bx0:.2f} {by1-by0:.2f}">\n'+'\n'.join(els)+'\n</svg>\n')
    print(k,len(els),round(bx1-bx0),round(by1-by0))
