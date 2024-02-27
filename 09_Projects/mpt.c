#include<stdio.h>
#include<string.h>
void input(char arr[],int count1); //function prototype
main()
{
//intailization
int i=0,temp=0,t=0,count1=0;
char arr[100];
char exit;
do
{
printf("Enter element name or symbol:");
scanf(" %[^\n]s",&arr);
 for(i=0;arr[i];i++)  //this loop will convert uppercase alphabets to lowercase
    {
    if(arr[i]>=65 && arr[i]<=96)
    {
    temp=arr[i];
    temp=temp+32;
    arr[i]=temp;
    }
    }
    count1++;  //this count1 for print searching history once time on the top of file
    input(arr,count1); //function calling
    printf("Do you want to search another element?\nif yes press y if want to exit press n\n");
    scanf(" %c",&exit);
    i=0;
    temp=0;
}
while(exit!='n');
return 0;
}
    void input(char arr1[],int count1) //function working
    {
    int j=0,count=0;
    FILE *fptr;
    char *elements[] = {
    "hydrogen","helium","lithium","berylium","boron","carbon","nitrogen","oxygen",
    "fluorine","neon","sodium","magnesium","aluminum","silicon","phosphorus","sulfur","chlorine","argon",
    "potassium","calcium","scandium","titanium","vanadium","chromium","manganese","iron","cobalt","nickel",
    "copper","zinc","gallium","germanium","arsenic","selenium","bromine","krypton",
    "rubidium","strontium","yttrium","zirconium","niobium","molybdenum","technetium","ruthenium","rhodium",
    "palladium","silver","cadmium","indium","tin","antimony","tellurium","iodine",
    "xenon","cesium","barium","lanthanum","cerium","praseodymium","neodymium","promethium","samarium","europium","gudolinium",
    "terbium","dysprosium","holmium","erbium","thulium","ytterbium","lutetium","hafnium","tantalum","tungsten",
    "rhenium","osmium","iridium","platinum","gold","mercury","thallium","lead","bismuth","polonium","astatine",
    "radon","francium","radium","actinium","thorium","protacitinium","uranium","neptunium","plutonium",
    "americium","curium","berkelium","californium","einsteinium","fermium","mendelevium","nobelium",
    "lawrencium","rutherfordium","dubnium","seaborgium","bohrium","hassium","meitnerium"
    }; //this pointer string for save the elements name
    char *symbol[]={
    "h","he","li","be","b","c","n","o","f","ne","na","mg","al","si","p","s","cl","ar","k",
    "ca","sc","ti","v","cr","mn","fe","co","ni","cu","zn","ga","ge","as","se","br","kr","rb","sr","y","zr",
    "nb","mo","tc","ru","rh","pd","ag","cd","in","sn","sb","te","i","xe","cs","ba","la","ce","pr","nd","pm",
    "sm","eu","gd","tb","dy","ho","er","tm","yb","lu","hf","ta","w","re","os","lr","pt","au","hg","tl","pb",
    "bi","po","at","rn","fr","ra","ac","th","pa","u","np","pu","am","cm","bk","cf","es","fm","md","no","lr",
    "rf","db","sg","bh","hs","mt"
    };//this pointer string for save the symbol of elements

    float atomic_weight[]={
    1.0079,4.0026,6.941,9.0122,10.811,12.0107,14.0067,15.9994,18.9984,20.1797,22.9815,
    24.305,26.9815,28.0855,30.9738,32.065,35.453,39.948,39.0983,40.078,44.9559,47.867,50.9415,51.9961,54.938,55.845,58.9332,
    58.6934,63.546,65.39,69.723,72.64,74.9216,78.96,79.904,83.8,85.4678,87.62,88.9059,91.224,92.9064,
    95.64,98,101.07,102.9055,106.42,107.8682,112.411,114.818,118.71,121.76,127.6,126.9045,131.293,
    132.9055,137.327,138.9055,140.116,140.9077,144.24,145,150.36,151.964,157.25,158.9253,162.5,164.9303,167.259,
    168.9342,173.04,174.967,178.49,180.9479,183.84,186.207,190.23,192.217,195.078,196.9665,200.59,204.3833,
    207.2,208.9804,209,210,222,223,226,227,232.0381,231.0359,238.0289,237,244,243,247,247,251,252,257,258,
    259,262,261,262,266,264,277,268
    }; //this array for save the values of atomic weight
    int atomic_number[]={
    1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,
    31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,64,
    65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,97,98,
    99,100,101,102,103,104,105,106,107,108,109
    }; //this array for save the elements atomic numbers
    int discovery[]={
    1776,1895,1817,1797,1808,1809,1772,1774,1886,1898,1807,1755,1825,1824,1669,1668,1774,
    1894,1807,1808,1879,1791,1830,1797,1774,1775,1735,1751,1751,1752,1875,1886,1884,1817,1826,1898,1861,
    1790,1794,1789,1801,1781,1937,1844,1803,1803,1804,1817,1863,1861,1862,1783,1811,1898,1860,1808,1839,
    1803,1885,1885,1945,1879,1901,1880,1843,1886,1867,1842,1879,1878,1907,1923,1802,1783,1925,1803,1803,
    1735,1736,1765,1861,1862,1864,1898,1940,1900,1939,1898,1899,1829,1913,1789,1940,1940,1944,1944,1949,
    1950,1952,1952,1955,1958,1961,1964,1967,1974,1981,1984,1982
    };//this array for save the years of dicoveray of a element
    int group[]={
    1,18,1,2,13,14,15,16,17,18,1,2,13,14,15,16,17,18,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,
    16,17,18,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,1,2,3,101,101,101,101,101,101,101,101,101,101,
    101,101,101,101,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,1,1,2,3,102,102,102,102,102,102,102,102,102,
    102,102,102,102,4,5,6,7,8,9
    };//this array save elements group
    int melting[]={
    -259,-272,180,1278,2300,3500,-210,-218,-220,-249,98,639,660,1410,44,113,-101,-189,64,839,1539,1660,
    1890,1857,1245,1535,1495,1453,1083,420,30,937,81,217,-7,-157,39,769,1523,1852,2468,2617,2200,2250,
    1966,1552,962,321,157,232,630,449,114,-112,29,725,920,795,935,1010,1100,1072,822,1311,1360,1412,1470,
    1522,1545,824,1656,2150,2996,3410,3180,3045,2410,1772,1064,-39,303,327,271,254,302,-71,27,700,1050,1750,
    1568,1132,640,640,994,1340,986,900,860,1527,0000,827,1627
    };//this array save melting popint values of a element
    int boiling[]={
        -253,-269,1347,2970,2550,4827,-196,-183,-188,-246,883,1090,2467,2355,280,445,-35,-186,774,1484,
        2832,3287,3380,2672,1962,2750,2870,2732,2567,907,2403,2830,613,685,59,-153,688,1384,3337,4377,
        4927,4612,4877,3900,3727,2927,2212,765,2000,2270,1750,990,184,-108,678,1140,3469,3257,3127,
        3127,3000,1900,1597,3233,3041,2562,2720,2510,1727,1466,3315,5400,5425,5660,5627,5027,4527,3827,
        2807,357,1457,1740,1560,962,337,-62,677,1737,3200,4790,7777,3818,3902,3235,2607

    };//this array will save the boiling point values
    char *electron[]={
        "1S^1","1S^2","1S^2 2S^1","1S^2 2S^2","1s^2 2s^2 2p^1","1s^2 2s^2 2p^2","1s^2 2s^2 2p^3","2s^2 2p^4","2s^2 2p^5",
        "2S^2 2P^6","3S^1","3s^2","3S^2 3P^1","3S^2 3P^2","3S^2 3P^3","3S^2 3P^4","3S^2 3P^5","3S^2 3P^6",
        "4S^1","4S^2","3d^1 4S^2","3d^2 4S^2","3d^3 4S^2","3d^5 4S^1","3d^5 4S^2","3d^6 4S^2","3d^7 4S^2","3d^8 4S^2",
        "3d^10 4S^1","3d^10 4S^2","3d^10 4s^2 4p^1","3d^10 4s^2 4p^2","3d^10 4s^2 4p^3","3d^10 4s^2 4p^4","3d^10 4s^2 4p^5",
        "3d^10 4s^2 4p^6","5s^1","5s^2","4d^1 5s^2","4d^2 5s^2","4d^4 5s^1","4d^5 5s^1","4d^5 5s^2","4d^7 5s^1","4d^8 5s^1",
        "4d^10","4d^10 5s^1","4d^10 5s^2","4d^10 5s^2 5p^1","4d^10 5s^2 5p^2","4d^10 5s^2 5p^3","4d^10 5s^2 5p^4",
        "4d^10 5s^2 5p^5","4d^10 5s^2 5p^6","6s^1","6s^2","5d^1 6s^2","4f^1 5d^1 6s^2","4f^3 6s^2","4f^4 6s^2","4f^5 6s^2","4f^6 6s^2","4f^7 6s^2","4f^7 5d^1 6s^2","4f^9 6s^2","4f^10 6s^2","4f^11 6s^2","4f^12 6s^2","4f^13 6s^2","4f^14 6s^2","4f^14 5d^1 6s^2","4f^14 5d^2 6s^2","4f^14 5d^3 6s^2","4f^14 5d^4 6s^2","4f^14 5d^5 6s^2","4f^14 5d^6 6s^2","4f^14 5d^7 6s^2","4f^14 5d^9 6s^1","4f^14 5d^10 6s^1","4f^14 5d^10 6s^2","4f^14 5d^10 6s^2 6p^1","4f^14 5d^10 6s^2 6p^2","4f^14 5d^10 6s^2 6p^3","4f^14 5d^10 6s^2 6p^4","4f^14 5d^10 6s^2 6p^5","4f^14 5d^10 6s^2 6p^6","7s^1","7s^2","6s^1 7s^2","6d2 7s2","5f^2 6d^1 7s^2","5f^3 6d^1 7s^2","5f^4 6d^1 7s^2","5f^6 7s^2","5f^7 7s^2"

    };//this array will save electron configration of every elements
    for(j=0;j<109;j++) // this loop will compare user input with the elements string and symbol string
    {
    if (strcmp(arr1,elements[j]) == 0 || strcmp(arr1,symbol[j]) == 0  )
    {
        count=j;// if its match then count save the value of j
        break;
    }
    }
if (strcmp(arr1,elements[count]) == 0 || strcmp(arr1,symbol[count]) == 0  )
{
printf("Element name:%s\n",elements[count]);
printf("Element symbol:%s\n",symbol[count]);
printf("Atomic weight:%f\n",atomic_weight[count]);
printf("Atomic number:%d\n",atomic_number[count]);
if(count==5||count==15||count==25||count==28||count==29||count==32||count==46||count==49||count==50||count==78||count==79||count==81||count==82)
{
printf("Element Discovery date:ancient\n");
}
else
{
printf("Element Discovery date:%d\n",discovery[count]);
}
printf("Element group:%d\n",group[count]);
if(count==100 ||count==103||count==104||count==105||count==106||count==107||count==108)
{
    printf("Melting point:no melting point\n");
}
else{
printf("Melting point:%d\n",melting[count]);
}
if(count==90||count==95||count==96||count==97||count==98||count==99||count==100||count==101||count==102||count==103||count==104||count==105||count==106||count==107||count==108)
{
    printf("Boiling point:no boiling point");
}
else{
printf("Boiling point:%d\n",boiling[count]);
}
printf("Electron configuration:%s\n",electron[count]);
}
else{
    printf("Not found");

}
fptr=fopen("periodic.txt","a+"); //filing its save the searching history in periodic.txt file name
if(fptr==NULL){
printf("Error!");
return 0;
}
if(count1==1)
{
    printf("your searching history  is save on your file\n");
    printf("please remove your last history on your file because its enter history to a same file\n");

    fprintf(fptr,"Searching History\n");
}
fprintf(fptr,"Element name:%s\n",elements[count]);
fprintf(fptr,"Element symbol:%s\n",symbol[count]);
fprintf(fptr,"Atomic weight:%f\n",atomic_weight[count]);
fprintf(fptr,"Atomic number:%d\n",atomic_number[count]);
if(count==5||count==15||count==25||count==28||count==29||count==32||count==46||count==49||count==50||count==78||count==79||count==81||count==82)
{
  fprintf(fptr,"Element Discovery date:ancient\n");
}
else
{
  fprintf(fptr,"Element Discovery date:%d\n",discovery[count]);
}
fprintf(fptr,"Element group:%d\n",group[count]);
if(count==100 ||count==103||count==104||count==105||count==106||count==107||count==108)
{
    fprintf(fptr,"Melting point:no melting point\n");
}
else
{
   fprintf(fptr,"Melting point:%d\n",melting[count]);
}
if(count==90||count==95||count==96||count==97||count==98||count==99||count==100||count==101||count==102||count==103||count==104||count==105||count==106||count==107||count==108)
{
   fprintf(fptr,"Boiling point:no boiling point");
}
else
{
  fprintf(fptr,"Boiling point:%d\n",boiling[count]);
}
fprintf(fptr,"Electron configuration:%s\n",electron[count]);
fclose(fptr);
}
