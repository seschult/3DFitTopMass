


#include "ZROOT.h"



#include "Fill3D.h"
#include "FCN.h"
#include "TemplateHolder.h"


using namespace std;




int main(int argc, char* argv[])
{
	
	// uncomment me on 6 ROOT::EnableThreadSafety();
if (argc>4) exit(1);	

std::string Channel = argv[2];
std::string Outputfolder = argv[3];

std::vector<double> gMTOP={170,171.5,172.5,173.5,175};
std::vector<double> gbJSF={0.96, 0.98, 1.0, 1.02, 1.04};
std::vector<double> gJSF={0.96, 0.98, 1.0, 1.02, 1.04};


Fill3D* topquark = new Fill3D(argv[1],argv[2],gMTOP,gbJSF,gJSF);


topquark->top_fit();
topquark->save_par(Outputfolder);

for(int i = 0; i < topquark->gALL.size(); i++){
   topquark->gALL[i]->plot(Form("%sout_mass_%2.2f_JSF_%2.2f_bJSF_%3.1f",Outputfolder.c_str(),topquark->gALL[i]->fmtop,topquark->gALL[i]->fJSF,topquark->gALL[i]->fbJSF));
   //topquark->gALL[i]->save(Outputfolder,Form(topquark->gALL[i]->fmtop),Form(topquark->gALL[i]->fJSF),Form(topquark->gALL[i]->fbJSF));
   topquark->gALL[i]->save(Outputfolder);

};
return 0;
}
