#include <limits.h>
#include <stdlib.h>
#include "../includes/ft_printf.h"

void	str_tests(void)
{
	char *str = NULL;
	ft_printf("%c", -0);
	ft_printf("%c", 0);
	ft_printf("%c", INT_MAX);
	ft_printf("%c", 'c');
	ft_printf("%c", '\n');

    ft_printf("\nTheirs:\n\n");
	printf("%c", -0);
	printf("%c", 0);
	printf("%c", INT_MAX);
	printf("%c", 'c');
	printf("%c", '\n');
    printf("Done\n");

	ft_printf("%s", "pouet");
	ft_printf(" pouet %s !!\n", "camembert");
	ft_printf("%s !\n", "Ceci n'est pas un \0 exercice !");
	ft_printf("%s!\n", "Ceci n'est toujours pas un exercice !");
	ft_printf("%s!\n", str);
	int ret_a = ft_printf("%s", "Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Etalafinilla*bip*");

	ft_printf("\nTheirs:\n\n");
	ft_printf("%s", "pouet");
	ft_printf(" pouet %s !!\n", "camembert");
	ft_printf("%s !\n", "Ceci n'est pas un \0 exercice !");
	ft_printf("%s!\n", "Ceci n'est toujours pas un exercice !");
	ft_printf("%s!\n", str);
	int	ret_b = ft_printf("%s", "Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Etalafinilla*bip*");
	if (ret_a == ret_b)
		ft_printf(ft_strjoin(FT_GREEN, "\nSuccess\n\n"));
	ft_printf(ft_strjoin(FT_END_ATTR, "\n\n"));
	ft_printf("\n\n\n");
	ft_printf("Str 1: |%s|\nStr 2: |%10s|\nStr 3: |%-10s|\nStr 4: |%10.7s|\nStr 5: |%-10.7s|\n", "hello", "world", "Hello", "World", "hEllo");
	printf("Str 1: |%s|\nStr 2: |%10s|\nStr 3: |%-10s|\nStr 4: |%10.7s|\nStr 5: |%-10.7s|\n", "hello", "world", "Hello", "World", "hEllo");
	ft_printf("\n\n");
	ft_printf("Str 1: |%s|\nStr 2: |%4s|\nStr 3: |%-4s|\nStr 4: |%10.4s|\nStr 5: |%-10.4s|\nStr 6: |%-.7s|\n", "hello", "world", "Hello", "World", "hEllo", "wOrld");
	printf("Str 1: |%s|\nStr 2: |%4s|\nStr 3: |%-4s|\nStr 4: |%10.4s|\nStr 5: |%-10.4s|\nStr 6: |%-.7s|\n", "hello", "world", "Hello", "World", "hEllo", "wOrld");

	int meow = ft_printf("%-.s", NULL);
	meow += ft_printf("%-.14s", NULL);
	meow += ft_printf("%-.03s", NULL);
	meow += ft_printf("%.s", NULL);
	// meow += ft_printf("%0.s", NULL);
	// meow += ft_printf("%0s", NULL);
	meow += ft_printf("%s", NULL);
	
	int moo = printf("%-.s", NULL);
	moo += printf("%-.14s", NULL);
	moo += printf("%-.03s", NULL);
	moo += printf("%.s", NULL);
	// moo += printf("%0.s", NULL);
	// moo += printf("%0s", NULL);
	moo += printf("%s", NULL);
	if (meow == moo)
		ft_printf("\nMATCHES!\n");
	else
		ft_printf("\nBOO\n");
	
}

int test_int()
{
    long	a, b, c, d, e, f, g;
	short	h, i, j;
	long long k, l, m;
	a = 342345245645;
	b = 3423534543;
	c = -234235426545437823;
	d = 9045834502349;
	e = 42;
	f = -0;
	g = -4294967290;
	h = 0;
	i = -15000;
	j = 15000;
	k = 0x7ffffffffffffffe;
	l = -3245465845856945425;
	m = 0;

    ft_printf("Mine: %%i and %%d\n");
	ft_printf("%%04i 42 == |%04i|\n", 42);
	ft_printf("%%05i 42 == |%05i|\n", 42);
	ft_printf("%%0i 42 == |%0i|\n", 42);
	ft_printf("%%0d 0000042 == |%0d|\n", 0000042);

	ft_printf("\ntheirs: %%i and %%d\n\n");
	printf("%%04i 42 == |%04i|\n", 42);
	printf("%%05i 42 == |%05i|\n", 42);
	printf("%%0i 42 == |%0i|\n", 42);
	printf("%%0d 0000042 == |%0d|\n", 0000042);
	
    ft_printf("int testing: %%d\n", 42);
	ft_printf("Int 1: |%d|\nInt 2: |%10d|\nInt 3: |%-10d|\nInt 4: |%10.5d|\nInt 5: |%-10.5d|\nInt 6: |%+10.5d|\nInt 7: |%+-10.5d|\n", 42, 90234383, -234234, 25, -25, 420, -420);
	printf("Int 1: |%d|\nInt 2: |%10d|\nInt 3: |%-10d|\nInt 4: |%10.5d|\nInt 5: |%-10.5d|\nInt 6: |%+10.5d|\nInt 7: |%+-10.5d|\n", 42, 90234383, -234234, 25, -25, 420, -420);
	
	ft_printf("\nlong testing: %%l\n");
	ft_printf("Int 1: |%ld|\nInt 2: |%20ld|\nInt 3: |%-20ld|\nInt 4: |%20.5ld|\nInt 5: |%-20.5ld|\nInt 6: |%+20.5ld|\nInt 7: |%+-20.7ld|\n", g, b, c, d, e, f, g);
	printf("Int 1: |%ld|\nInt 2: |%20ld|\nInt 3: |%-20ld|\nInt 4: |%20.5ld|\nInt 5: |%-20.5ld|\nInt 6: |%+20.5ld|\nInt 7: |%+-20.7ld|\n", g, b, c, d, e, f, g);

	ft_printf("\nshort testing: %%h\n");
	ft_printf("Int 1: |%hd|\nInt 2: |%10hd|\nInt 3: |%-10hd|\nInt 4: |%10.5hd|\nInt 5: |%-10.5hd|\nInt 6: |%+10.5hd|\nInt 7: |%+-10.5hd|\nInt 8: |%+-10.5hi|\n", h, i, i, j, j, i, -0, -0);
	printf("Int 1: |%hd|\nInt 2: |%10hd|\nInt 3: |%-10hd|\nInt 4: |%10.5hd|\nInt 5: |%-10.5hd|\nInt 6: |%+10.5hd|\nInt 7: |%+-10.5hd|\nInt 8: |%+-10.5hi|\n", h, i, i, j, j, i, -0, -0);

	ft_printf("\nlong long testing: %%ll\n");
	ft_printf("Int 1: |%lld|\nInt 2: |%25lld|\nInt 3: |%-25lld|\nInt 4: |%35.25lld|\nInt 5: |%-35.25lld|\nInt 6: |%+35.25lld|\nInt 7: |%+-35.25lld|\nInt 8: |%+-35.25lli|\n", m, k, l, l, k, l, k, -0);
	printf("Int 1: |%lld|\nInt 2: |%25lld|\nInt 3: |%-25lld|\nInt 4: |%35.25lld|\nInt 5: |%-35.25lld|\nInt 6: |%+35.25lld|\nInt 7: |%+-35.25lld|\nInt 8: |%+-35.25lli|\n", m, k, l, l, k, l, k, -0);

}

void	hex_test(void)
{
	short x = 0xff;
	int	a = 0xbeef;
	long b = LONG_MAX;
	long long c = 0x7ffffffffffffffe;

	ft_printf("hex 1: |%x|\nhex 2: |%hx|\nhex 3: |%lx|\nhex 4: |%llx|\n", a, x, b, c);
	printf("hex 1: |%x|\nhex 2: |%hx|\nhex 3: |%lx|\nhex 4: |%llx|\n", a, x, b, c);
	ft_printf("\nhex 1: |%15x|\nhex 2: |%15hx|\nhex 3: |%25lx|\nhex 4: |%25llx|\n", a, x, b, c);
	printf("hex 1: |%15x|\nhex 2: |%15hx|\nhex 3: |%25lx|\nhex 4: |%25llx|\n", a, x, b, c);
	ft_printf("\nhex 1: |%-15x|\nhex 2: |%-15hx|\nhex 3: |%-25lx|\nhex 4: |%-25llx|\n", a, x, b, c);
	printf("hex 1: |%-15x|\nhex 2: |%-15hx|\nhex 3: |%-25lx|\nhex 4: |%-25llx|\n", a, x, b, c);
	ft_printf("\nhex 1: |%-15.7x|\nhex 2: |%-15.5hx|\nhex 3: |%-25.15lx|\nhex 4: |%-25.20llx|\n", a, x, b, c);
	printf("hex 1: |%-15.7x|\nhex 2: |%-15.5hx|\nhex 3: |%-25.15lx|\nhex 4: |%-25.20llx|\n", a, x, b, c);
	ft_printf("\nhex 1: |%15.7x|\nhex 2: |%15.5hx|\nhex 3: |%25.15lx|\nhex 4: |%25.20llx|\n", a, x, b, c);
	printf("hex 1: |%15.7x|\nhex 2: |%15.5hx|\nhex 3: |%25.15lx|\nhex 4: |%25.20llx|\n", a, x, b, c);

    ft_printf("hex 1: |%x|\nhex 2: |%hX|\nhex 3: |%lX|\nhex 4: |%llx|\n", a, x, b, c);
	printf("hex 1: |%x|\nhex 2: |%hX|\nhex 3: |%lX|\nhex 4: |%llx|\n", a, x, b, c);
	ft_printf("\nhex 1: |%15X|\nhex 2: |%15hX|\nhex 3: |%25lX|\nhex 4: |%25llX|\n", a, x, b, c);
	printf("hex 1: |%15X|\nhex 2: |%15hX|\nhex 3: |%25lX|\nhex 4: |%25llX|\n", a, x, b, c);
	ft_printf("\nhex 1: |%-15X|\nhex 2: |%-15hX|\nhex 3: |%-25lX|\nhex 4: |%-25llX|\n", a, x, b, c);
	printf("hex 1: |%-15X|\nhex 2: |%-15hX|\nhex 3: |%-25lX|\nhex 4: |%-25llX|\n", a, x, b, c);
	ft_printf("\nhex 1: |%-15.7X|\nhex 2: |%-15.5hX|\nhex 3: |%-25.15lX|\nhex 4: |%-25.20llX|\n", a, x, b, c);
	printf("hex 1: |%-15.7X|\nhex 2: |%-15.5hX|\nhex 3: |%-25.15lX|\nhex 4: |%-25.20llX|\n", a, x, b, c);
	ft_printf("\nhex 1: |%15.7X|\nhex 2: |%15.5hX|\nhex 3: |%25.15lX|\nhex 4: |%25.20llX|\n", a, x, b, c);
	printf("hex 1: |%15.7X|\nhex 2: |%15.5hX|\nhex 3: |%25.15lX|\nhex 4: |%25.20llX|\n", a, x, b, c);


	// TO RUN THE FOLLOWING TEST, THE MAKEFILE NEEDS FLAGS TURNED OFF

	// int meow, moo;

	// int meow = ft_printf("%#x\n", 0);
	// meow += ft_printf("%#X\n", 42);
	// meow += ft_printf("%#08X\n", 42);
	// meow += ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
	// meow += ft_printf("%X", 4294967296);
	// meow += ft_printf("%x", 4294967296);
	// meow += ft_printf("%X", -42);
	// meow += ft_printf("%x", -42);
	// meow += ft_printf("%x", 42);
	// meow += ft_printf("Kashim a %x histoires à raconter", 1001);
	// meow += ft_printf("Il fait au moins %x\n", -8000);
	// meow += ft_printf("%x", -0);
	// meow += ft_printf("%x", 0);
	// meow += ft_printf("%x", INT_MAX);
	// meow += ft_printf("%x", INT_MIN);
	// meow += ft_printf("%x", INT_MIN - 1);
	// meow += ft_printf("%x", INT_MAX + 1);
	// meow += ft_printf("%%x 0000042 == |%x|\n", 0000042);
	// meow += ft_printf("%%x \t == |%x|\n", '\t');
	// meow += ft_printf("%%x Lydie == |%x|\n", 'L'+'y'+'d'+'i'+'e');
	// meow += ft_printf("%x", 4294967296);

	// ft_printf("\nTheirs:\n");
	// int moo = printf("%#x\n", 0);
	// moo += printf("%#X\n", 42);
	// moo += printf("%#08X\n", 42);
	// moo += printf("@moulitest: %#.x %#.0x\n", 0, 0);
	// moo += printf("%X", 4294967296);
	// moo += printf("%x", 4294967296);
	// moo += printf("%X", -42);
	// moo += printf("%x", -42);
	// moo += printf("%x", 42);
	// moo += printf("Kashim a %x histoires à raconter", 1001);
	// moo += printf("Il fait au moins %x\n", -8000);
	// moo += printf("%x", -0);
	// moo += printf("%x", 0);
	// moo += printf("%x", INT_MAX);
	// moo += printf("%x", INT_MIN);
	// moo += printf("%x", INT_MIN - 1);
	// moo += printf("%x", INT_MAX + 1);
	// moo += printf("%%x 0000042 == |%x|\n", 0000042);
	// moo += printf("%%x \t == |%x|\n", '\t');
	// moo += printf("%%x Lydie == |%x|\n", 'L'+'y'+'d'+'i'+'e');
	// moo += printf("%x", 4294967296);
	
	// if (meow == moo)
	// 	ft_printf(ft_strjoin(ft_strjoin(FT_GREEN, "\nPASS\n"), FT_END_ATTR));
	// else
	// 	ft_printf(ft_strjoin(ft_strjoin(FT_RED, "\nFAIL\n"), FT_END_ATTR));

	// ft_printf("%x\n", -42);
	// ft_printf("%hhx\n", -0);
	// ft_printf("%hhx\n", 0);
	// ft_printf("%hhx\n", INT_MAX);
	// ft_printf("%hhx\n", INT_MIN);
	// ft_printf("%hhx\n", INT_MIN - 1);
	// ft_printf("%hhx\n", INT_MAX + 1);
	// ft_printf("%%hhx 0000042 == |%x|\n", 0000042);
	// ft_printf("%%hhx \t == |%x|\n", '\t');
	// ft_printf("%%hhx Lydie == |%x|\n", 'L'+'y'+'d'+'i'+'e');
	// ft_printf("%hhx", 4294967296);

	// ft_printf("%hx", -0);
	// ft_printf("%hx", 0);
	// ft_printf("%hx", INT_MAX);
	// ft_printf("%hx", INT_MIN);
	// ft_printf("%hx", INT_MIN - 1);
	// ft_printf("%hx", INT_MAX + 1);
	// ft_printf("%%hx 0000042 == |%x|\n", 0000042);
	// ft_printf("%%hx \t == |%x|\n", '\t');
	// ft_printf("%%hx Lydie == |%x|\n", 'L'+'y'+'d'+'i'+'e');
	// ft_printf("%hx", 4294967296);

	// ft_printf("%lx", -0);
	// ft_printf("%lx", 0);
	// ft_printf("%lx", INT_MAX);
	// ft_printf("%lx", INT_MIN);
	// ft_printf("%lx", INT_MIN - 1);
	// ft_printf("%lx", INT_MAX + 1);
	// ft_printf("%%lx 0000042 == |%x|\n", 0000042);
	// ft_printf("%%lx \t == |%x|\n", '\t');
	// ft_printf("%%lx Lydie == |%x|\n", 'L'+'y'+'d'+'i'+'e');
	// ft_printf("%lx", 4294967296);

	// ft_printf("%llx", -0);
	// ft_printf("%llx", 0);
	// ft_printf("%llx", INT_MAX);
	// ft_printf("%llx", INT_MIN);
	// ft_printf("%llx", INT_MIN - 1);
	// ft_printf("%llx", INT_MAX + 1);
	// ft_printf("%%llx 0000042 == |%x|\n", 0000042);
	// ft_printf("%%llx \t == |%x|\n", '\t');
	// ft_printf("%%llx Lydie == |%x|\n", 'L'+'y'+'d'+'i'+'e');
	// ft_printf("%llx", 4294967296);

	// printf("%x\n", -42);
	// printf("%hhx\n", -0);
	// printf("%hhx\n", 0);
	// printf("%hhx\n", INT_MAX);
	// printf("%hhx\n", INT_MIN);
	// printf("%hhx\n", INT_MIN - 1);
	// printf("%hhx\n", INT_MAX + 1);
	// printf("%%hhx 0000042 == |%x|\n", 0000042);
	// printf("%%hhx \t == |%x|\n", '\t');
	// printf("%%hhx Lydie == |%x|\n", 'L'+'y'+'d'+'i'+'e');
	// printf("%hhx", 4294967296);

	// printf("%hx", -0);
	// printf("%hx", 0);
	// printf("%hx", INT_MAX);
	// printf("%hx", INT_MIN);
	// printf("%hx", INT_MIN - 1);
	// printf("%hx", INT_MAX + 1);
	// printf("%%hx 0000042 == |%x|\n", 0000042);
	// printf("%%hx \t == |%x|\n", '\t');
	// printf("%%hx Lydie == |%x|\n", 'L'+'y'+'d'+'i'+'e');
	// printf("%hx", 4294967296);

	// printf("%lx", -0);
	// printf("%lx", 0);
	// printf("%lx", INT_MAX);
	// printf("%lx", INT_MIN);
	// printf("%lx", INT_MIN - 1);
	// printf("%lx", INT_MAX + 1);
	// printf("%%lx 0000042 == |%x|\n", 0000042);
	// printf("%%lx \t == |%x|\n", '\t');
	// printf("%%lx Lydie == |%x|\n", 'L'+'y'+'d'+'i'+'e');
	// printf("%lx", 4294967296);

	// printf("%llx", -0);
	// printf("%llx", 0);
	// printf("%llx", INT_MAX);
	// printf("%llx", INT_MIN);
	// printf("%llx", INT_MIN - 1);
	// printf("%llx", INT_MAX + 1);
	// printf("%%llx 0000042 == |%x|\n", 0000042);
	// printf("%%llx \t == |%x|\n", '\t');
	// printf("%%llx Lydie == |%x|\n", 'L'+'y'+'d'+'i'+'e');
	// printf("%llx", 4294967296);
}

int main(void)
{
    // ft_printf("%#s\n", "hello");
    // printf("%#s\n", "hello");
	// ft_printf("%llf\n", 42.5);
	// printf("%llf\n", 42.5);
	// ft_printf("%%#X 42 ==  %#X\n", 42);
	// printf("%%#X 42 ==  %#X\n", 42);
	// ft_printf("%% d -42 == |% d|\n", -42);
	// printf("%% d -42 == |% d|\n", -42);
	// ft_printf("%% i -42 == |% i|\n", -42);
	// printf("%% i -42 == |% i|\n", -42);

	ft_printf("%%04.3i 42 == |%04.3i|\n", 42);
	// printf("%%04.3i 42 == |%04.3i|\n", 42);
	// system("leaks ft_printf");
	// ft_printf("%%04.5i 42 == |%04.5i|\n", 42);
	// printf("%%04.5i 42 == |%04.5i|\n", 42);

	// ft_printf("%% 4.5i 42 == |% 4.5i|\n", 42);
	// printf("%% 4.5i 42 == |% 4.5i|\n", 42);

	// ft_printf("%%04.2i 42 == |%04.2i|\n", 42);
	// printf("%%04.2i 42 == |%04.2i|\n", 42);
    // ft_printf("%+.7u\n", 234);
    // printf("%+.7u\n", 234);
    // test_int();
    // str_tests();
    // hex_test();
    return (0);
}