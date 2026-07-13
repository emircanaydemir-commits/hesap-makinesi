//arka plan animasyonu
const arka = document.getElementById("arkaplan");
for (let i = 0; i < 60; i++) {
    const yeni = document.createElement("div");
    yeni.classList.add("sayilar");
    let rastgele;
    rastgele = Math.floor(Math.random() * 2);
    yeni.textContent = rastgele;
    rastgele = Math.floor(Math.random() * 100);
    yeni.style.left = rastgele + "vw";
    rastgele = Math.random() * 10;
    yeni.style.animationDelay = -rastgele + "s";
    rastgele = Math.floor(Math.random() * 30 + 10);
    yeni.style.fontSize = rastgele + "px";
    arka.appendChild(yeni);
}
//tıkladığında yaz
const yazılacak = document.getElementById("yazılacak");
const bir = document.getElementById("bir");
bir.addEventListener("click", function () {
    yazılacak.textContent += "1";
});
const iki = document.getElementById("iki");
iki.addEventListener("click", function () {
    yazılacak.textContent += "2";
});
const uc = document.getElementById("uc");
uc.addEventListener("click", function () {
    yazılacak.textContent += "3";
})
const dort = document.getElementById("dort");
dort.addEventListener("click", function () {
    yazılacak.textContent += "4";
});
const bes = document.getElementById("bes");
bes.addEventListener("click", function () {
    yazılacak.textContent += "5";
})
const altı = document.getElementById("altı");
altı.addEventListener("click", function () {
    yazılacak.textContent += "6";
})
const yedi = document.getElementById("yedi");
yedi.addEventListener("click", function () {
    yazılacak.textContent += "7";
})
const sekiz = document.getElementById("sekiz");
sekiz.addEventListener("click", function () {
    yazılacak.textContent += "8";
});
const dokuz = document.getElementById("dokuz");
dokuz.addEventListener("click", function () {
    yazılacak.textContent += "9";
});
const sifir = document.getElementById("sifir");
sifir.addEventListener("click", function () {
    yazılacak.textContent += "0";
});
const solayrac = document.getElementById("ayracsol");
solayrac.addEventListener("click", function () {
    yazılacak.textContent += "(";
});
const sagayrac = document.getElementById("ayracsag");
sagayrac.addEventListener("click", function () {
    yazılacak.textContent += ")";
});
const nokta = document.getElementById("nokta");
nokta.addEventListener("click", function () {
    yazılacak.textContent += ".";
})
const bol = document.getElementById("bol");
bol.addEventListener("click", function () {
    yazılacak.textContent += "÷";
});
const topla = document.getElementById("artı");
topla.addEventListener("click", function () {
    yazılacak.textContent += "+";
});
const cıkar = document.getElementById("eksi");
cıkar.addEventListener("click", function () {
    yazılacak.textContent += "-";
});
const carp = document.getElementById("carp");
carp.addEventListener("click", function () {
    yazılacak.textContent += "x";
});
//temizleme butonu
const temizle = document.getElementById("temizle");
const sonuc = document.getElementById("sonuc");
temizle.addEventListener("click", function () {
    yazılacak.textContent = "";
    sonuc.textContent = "";
});
//eşittir butonu ve c kodunu bağlama
const esittir = document.getElementById("esittir");
esittir.addEventListener("click",function(){
    let ifade=yazılacak.textContent;
    //metindeki bazı ifadeleri c diline uygun hale getirelim
    ifade=ifade.replace(/x/g,"*");
    ifade=ifade.replace(/÷/g,"%");
    console.log(ifade);
    // c deki parçala fonksiyonunu çağır
    try{
        let sonucdeger=Module.ccall(
            'parcala',
            'number',
            ['string'],
            [ifade]

        );
        sonuc.textContent=sonucdeger;
    }
    catch(error){
        sonuc.textContent="Hata!";
    }
});