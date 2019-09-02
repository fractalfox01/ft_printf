#include <limits.h>
#include "../includes/ft_printf.h"

void	str_tests(void)
{
	/*
	** failing char tests: needs to print ^@ the '\0' character when +- 0.
	*/
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
}

char		*fp_itoa(int n)
{
	char	*tmp;
	char	*ret;
	long	i;
	long	nbr;
	
	tmp = ft_strnew(12);
	i = 0;
	nbr = (long)n;
	if (nbr < 0)
		nbr *= -1;
	while (nbr / 10 > 0)
	{
		tmp[i++] = (nbr % 10) + 48;
		nbr /= 10;
	}
	tmp[i++] = nbr + 48;
	if (n < 0)
		tmp[i++] = '-';
	tmp[i] = '\0';
	ret = ft_strrev(tmp);
	ft_strdel(&tmp);
	return (ret);
}

void	int_tests(void)
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
	ft_printf("Mine:\n");
	ft_printf("%i", 42);
	ft_printf("Kashim a %i histoires à raconter", 1001);
	ft_printf("Il fait au moins %i\n", -8000);
	ft_printf("%i", -0);
	ft_printf("%i", 0);
	ft_printf("%i", INT_MAX);
	ft_printf("%i", INT_MIN);
	ft_printf("%i", INT_MIN - 1);
	ft_printf("%i", INT_MAX + 1);
	ft_printf("%%i 0000042 == |%i|\n", 0000042);
	ft_printf("%%i \t == |%i|\n", '\t');
	ft_printf("%%i Lydie == |%i|\n", 'L'+'y'+'d'+'i'+'e');

	ft_printf("\ntheirs:\n\n");
	printf("%i", 42);
	printf("Kashim a %i histoires à raconter", 1001);
	printf("Il fait au moins %i\n", -8000);
	printf("%i", -0);
	printf("%i", 0);
	printf("%i", INT_MAX);
	printf("%i", INT_MIN);
	printf("%i", INT_MIN - 1);
	printf("%i", INT_MAX + 1);
	printf("%%i 0000042 == |%i|\n", 0000042);
	printf("%%i \t == |%i|\n", '\t');
	printf("%%i Lydie == |%i|\n", 'L'+'y'+'d'+'i'+'e');

	ft_printf("Mine:\n");
	ft_printf("%%04i 42 == |%04i|\n", 42);
	ft_printf("%%05i 42 == |%05i|\n", 42);
	ft_printf("%%0i 42 == |%0i|\n", 42);
	ft_printf("%%0d 0000042 == |%0d|\n", 0000042);

	ft_printf("\ntheirs:\n\n");
	printf("%%04i 42 == |%04i|\n", 42);
	printf("%%05i 42 == |%05i|\n", 42);
	printf("%%0i 42 == |%0i|\n", 42);
	printf("%%0d 0000042 == |%0d|\n", 0000042);
	// ft_printf("int testing: %%d\n", 42);
	// ft_printf("Int 1: |%d|\nInt 2: |%10d|\nInt 3: |%-10d|\nInt 4: |%10.5d|\nInt 5: |%-10.5d|\nInt 6: |%+10.5d|\nInt 7: |%+-10.5d|\n", 42, 90234383, -234234, 25, -25, 420, -420);
	// printf("Int 1: |%d|\nInt 2: |%10d|\nInt 3: |%-10d|\nInt 4: |%10.5d|\nInt 5: |%-10.5d|\nInt 6: |%+10.5d|\nInt 7: |%+-10.5d|\n", 42, 90234383, -234234, 25, -25, 420, -420);
	
	// ft_printf("\nlong testing: %%l\n");
	// ft_printf("Int 1: |%ld|\nInt 2: |%20ld|\nInt 3: |%-20ld|\nInt 4: |%20.5ld|\nInt 5: |%-20.5ld|\nInt 6: |%+20.5ld|\nInt 7: |%+-20.7ld|\n", g, b, c, d, e, f, g);
	// printf("Int 1: |%ld|\nInt 2: |%20ld|\nInt 3: |%-20ld|\nInt 4: |%20.5ld|\nInt 5: |%-20.5ld|\nInt 6: |%+20.5ld|\nInt 7: |%+-20.7ld|\n", g, b, c, d, e, f, g);

	// ft_printf("\nshort testing: %%h\n");
	// ft_printf("Int 1: |%hd|\nInt 2: |%10hd|\nInt 3: |%-10hd|\nInt 4: |%10.5hd|\nInt 5: |%-10.5hd|\nInt 6: |%+10.5hd|\nInt 7: |%+-10.5hd|\n", h, i, i, j, j, i, i);
	// printf("Int 1: |%hd|\nInt 2: |%10hd|\nInt 3: |%-10hd|\nInt 4: |%10.5hd|\nInt 5: |%-10.5hd|\nInt 6: |%+10.5hd|\nInt 7: |%+-10.5hd|\n", h, i, i, j, j, i, i);

	// ft_printf("\nlong long testing: %%ll\n");
	// ft_printf("Int 1: |%lld|\nInt 2: |%25lld|\nInt 3: |%-25lld|\nInt 4: |%35.25lld|\nInt 5: |%-35.25lld|\nInt 6: |%+35.25lld|\nInt 7: |%+-35.25lld|\n", m, k, l, l, k, l, k);
	// printf("Int 1: |%lld|\nInt 2: |%25lld|\nInt 3: |%-25lld|\nInt 4: |%35.25lld|\nInt 5: |%-35.25lld|\nInt 6: |%+35.25lld|\nInt 7: |%+-35.25lld|\n", m, k, l, l, k, l, k);
}

void	octal_test(void)
{
	// short x = 0xff;
	// int a = 0xbeef;
	// long b = 0xbeefbeddead;
	// long long c = 0x7fffffffffffff;

	// ft_printf("octal 1: |%o|\noctal 2: |%ho|\noctal 3: |%lo|\noctal 4: |%llo|\n", a, x, b, c);
	// printf("octal 1: |%o|\noctal 2: |%ho|\noctal 3: |%lo|\noctal 4: |%llo|\n", a, x, b, c);
	// ft_printf("\noctal 1: |%10o|\noctal 2: |%10ho|\noctal 3: |%20lo|\noctal 4: |%20llo|\n", a, x, b, c);
	// printf("octal 1: |%10o|\noctal 2: |%10ho|\noctal 3: |%20lo|\noctal 4: |%20llo|\n", a, x, b, c);
	// ft_printf("\noctal 1: |%-10o|\noctal 2: |%-10ho|\noctal 3: |%-20lo|\noctal 4: |%-20llo|\n", a, x, b, c);
	// printf("octal 1: |%-10o|\noctal 2: |%-10ho|\noctal 3: |%-20lo|\noctal 4: |%-20llo|\n", a, x, b, c);

	ft_printf("Mine:\n");
	ft_printf("%o", 42);
	ft_printf("Kashim a %o histoires à raconter", 1001);
	ft_printf("Il fait au moins %o\n", -8000);
	ft_printf("%o", -0);
	ft_printf("%o", 0);
	ft_printf("%o", INT_MAX);
	ft_printf("%o", INT_MIN);
	ft_printf("%o", INT_MIN - 1);
	ft_printf("%o", INT_MAX + 1);
	ft_printf("%%o 0000042 == |%o|\n", 0000042);
	ft_printf("%%o \t == |%o|\n", '\t');
	ft_printf("%%o Lydie == |%o|\n", 'L'+'y'+'d'+'i'+'e');

	ft_printf("Theirs:\n");
	printf("%o", 42);
	printf("Kashim a %o histoires à raconter", 1001);
	printf("Il fait au moins %o\n", -8000);
	printf("%o", -0);
	printf("%o", 0);
	printf("%o", INT_MAX);
	printf("%o", INT_MIN);
	printf("%o", INT_MIN - 1);
	printf("%o", INT_MAX + 1);
	printf("%%o 0000042 == |%o|\n", 0000042);
	printf("%%o \t == |%o|\n", '\t');
	printf("%%o Lydie == |%o|\n", 'L'+'y'+'d'+'i'+'e');
}

void	hex_test(void)
{
	// short x = 0xff;
	// int	a = 0xbeef;
	// long b = 0xdeadbeddead;
	// long long c = 0x7ffffffffffffffe;

	// ft_printf("hex 1: |%x|\nhex 2: |%hx|\nhex 3: |%lx|\nhex 4: |%llx|\n", a, x, b, c);
	// printf("hex 1: |%x|\nhex 2: |%hx|\nhex 3: |%lx|\nhex 4: |%llx|\n", a, x, b, c);
	// ft_printf("\nhex 1: |%15x|\nhex 2: |%15hx|\nhex 3: |%25lx|\nhex 4: |%25llx|\n", a, x, b, c);
	// printf("hex 1: |%15x|\nhex 2: |%15hx|\nhex 3: |%25lx|\nhex 4: |%25llx|\n", a, x, b, c);
	// ft_printf("\nhex 1: |%-15x|\nhex 2: |%-15hx|\nhex 3: |%-25lx|\nhex 4: |%-25llx|\n", a, x, b, c);
	// printf("hex 1: |%-15x|\nhex 2: |%-15hx|\nhex 3: |%-25lx|\nhex 4: |%-25llx|\n", a, x, b, c);
	// ft_printf("\nhex 1: |%-15.7x|\nhex 2: |%-15.5hx|\nhex 3: |%-25.15lx|\nhex 4: |%-25.20llx|\n", a, x, b, c);
	// printf("hex 1: |%-15.7x|\nhex 2: |%-15.5hx|\nhex 3: |%-25.15lx|\nhex 4: |%-25.20llx|\n", a, x, b, c);
	// ft_printf("\nhex 1: |%15.7x|\nhex 2: |%15.5hx|\nhex 3: |%25.15lx|\nhex 4: |%25.20llx|\n", a, x, b, c);
	// printf("hex 1: |%15.7x|\nhex 2: |%15.5hx|\nhex 3: |%25.15lx|\nhex 4: |%25.20llx|\n", a, x, b, c);
	ft_printf("Mine:\n");
	ft_printf("%x", 42);
	ft_printf("Kashim a %x histoires à raconter", 1001);
	ft_printf("Il fait au moins %x\n", -8000);
	ft_printf("%x", -0);
	ft_printf("%x", 0);
	ft_printf("%x", INT_MAX);
	ft_printf("%x", INT_MIN);
	ft_printf("%x", INT_MIN - 1);
	ft_printf("%x", INT_MAX + 1);
	ft_printf("%%x 0000042 == |%x|\n", 0000042);
	ft_printf("%%x \t == |%x|\n", '\t');
	ft_printf("%%x Lydie == |%x|\n", 'L'+'y'+'d'+'i'+'e');

	ft_printf("\nTheirs:\n");
	printf("Mine:\n");
	printf("%x", 42);
	printf("Kashim a %x histoires à raconter", 1001);
	printf("Il fait au moins %x\n", -8000);
	printf("%x", -0);
	printf("%x", 0);
	printf("%x", INT_MAX);
	printf("%x", INT_MIN);
	printf("%x", INT_MIN - 1);
	printf("%x", INT_MAX + 1);
	printf("%%x 0000042 == |%x|\n", 0000042);
	printf("%%x \t == |%x|\n", '\t');
	printf("%%x Lydie == |%x|\n", 'L'+'y'+'d'+'i'+'e');
}

void	float_test(void)
{
	ft_printf("%f", (double)42);
	ft_printf("\n");
	ft_printf("Kashim a %f histoires à raconter", (double)1001);
	ft_printf("\n");
	ft_printf("Il fait au moins %f\n", (double)-8000);
	ft_printf("%f", (double)-0);
	ft_printf("\n");
	ft_printf("%f", (double)0);
	ft_printf("\n");
	ft_printf("%f", (double)INT_MAX);
	ft_printf("\n");
	ft_printf("%f", (double)INT_MIN);
	ft_printf("\n");
	ft_printf("%f", (double)INT_MIN - 1);
	ft_printf("\n");
	ft_printf("%f", (double)INT_MAX + 1);
	ft_printf("\n");
	ft_printf("%%f 0000042 == |%f|\n", (double)0000042);
	ft_printf("%%f \t == |%f|\n", (double)'\t');
	ft_printf("%%f Lydie == |%f|\n", (double)'L'+'y'+'d'+'i'+'e');
	ft_printf("%%f 42.42 == |%f|\n", 42.42);
	ft_printf("%F", (double)42);
	ft_printf("\n");
	ft_printf("Kashim a %F histoires à raconter", (double)1001);
	ft_printf("\n");
	ft_printf("Il fait au moins %F\n", (double)-8000);
	ft_printf("\n");
	ft_printf("%F", (double)-0);
	ft_printf("\n");
	ft_printf("%F", (double)0);
	ft_printf("\n");
	ft_printf("%F", (double)INT_MAX);
	ft_printf("\n");
	ft_printf("%F", (double)INT_MIN);
	ft_printf("\n");
	ft_printf("%F", (double)INT_MIN - 1);
	ft_printf("\n");
	ft_printf("%F", (double)INT_MAX + 1);
	ft_printf("\n");
	ft_printf("%%F 0000042 == |%F|\n", (double)0000042);
	ft_printf("%%F \t == |%F|\n", (double)'\t');
	ft_printf("%%F Lydie == |%F|\n", (double)'L'+'y'+'d'+'i'+'e');
	ft_printf("%%F 42.42 == |%F|\n", 42.42);
	ft_printf("%%F 42.42 == |%.2F|\n", 42.42);

	ft_printf("\nTheirs:\n\n");
	
	printf("%f", (double)42);
	printf("\n");
	printf("Kashim a %f histoires à raconter", (double)1001);
	printf("\n");
	printf("Il fait au moins %f\n", (double)-8000);
	printf("%f", (double)-0);
	printf("\n");
	printf("%f", (double)0);
	printf("\n");
	printf("%f", (double)INT_MAX);
	printf("\n");
	printf("%f", (double)INT_MIN);
	printf("\n");
	printf("%f", (double)INT_MIN - 1);
	printf("\n");
	printf("%f", (double)INT_MAX + 1);
	printf("\n");
	printf("%%f 0000042 == |%f|\n", (double)0000042);
	printf("%%f \t == |%f|\n", (double)'\t');
	printf("%%f Lydie == |%f|\n", (double)'L'+'y'+'d'+'i'+'e');
	printf("%%f 42.42 == |%f|\n", 42.42);
	printf("%F", (double)42);
	printf("\n");
	printf("Kashim a %F histoires à raconter", (double)1001);
	printf("\n");
	printf("Il fait au moins %F\n", (double)-8000);
	printf("\n");
	printf("%F", (double)-0);
	printf("\n");
	printf("%F", (double)0);
	printf("\n");
	printf("%F", (double)INT_MAX);
	printf("\n");
	printf("%F", (double)INT_MIN);
	printf("\n");
	printf("%F", (double)INT_MIN - 1);
	printf("\n");
	printf("%F", (double)INT_MAX + 1);
	printf("\n");
	printf("%%F 0000042 == |%F|\n", (double)0000042);
	printf("%%F \t == |%F|\n", (double)'\t');
	printf("%%F Lydie == |%F|\n", (double)'L'+'y'+'d'+'i'+'e');
	printf("%%F 42.42 == |%F|\n", 42.42);
	printf("%%F 42.42 == |%.2F|\n", 42.42);


	long double b = 123476598453656.123543657678756;
	float c = 12347.123543657678756;

	// NOTE: Standard printf does not work with 'l' length modifier.
	ft_printf("float 1: |%f|\nfloat 2: |%20f|\nfloat 3: |%25f|\nfloat 4: |%-25f|\n", c, c, c, c);
	printf("float 1: |%f|\nfloat 2: |%20f|\nfloat 3: |%25f|\nfloat 4: |%-25f|\n", c, c, c, c);
	ft_printf("float 1: |%f|\nfloat 2: |%20Lf|\nfloat 3: |%25lf|\nfloat 4: |%-25lf|\nfloat 5: |%+-50lf|\nfloat 6: |%-+50f|\nfloat 7: |%-+15.2lf|\n", c, b, b, b, b, c, b);
	printf("float 1: |%f|\nfloat 2: |%20Lf|\nfloat 3: |%25Lf|\nfloat 4: |%-25Lf|\nfloat 5: |%+-50Lf|\nfloat 6: |%-+50f|\nfloat 7: |%-+15.2Lf|\n", c, b, b, b, b, c, b);
}

void	pointer_test()
{
	int		*iptr;
	int b = 42;
	char	str[20] = "Hello World";
	char	*sptr = str;
	iptr = &b;
	
	ft_printf("int pointer: %p\nStr pointer: %p\n", iptr, sptr);
	printf("int pointer: %p\nStr pointer: %p\n", iptr, sptr);
}

void	unsigned_test()
{
	unsigned a = 123456678;
	unsigned long b = 0xdeadbeef;
	unsigned long long c = 0x7fffffffffffffff;

	ft_printf("usign: |%u|\nusign long: |%lu|\nusign long long: |%llu|\n", a, b, c);
	printf("usign: |%u|\nusign long: |%lu|\nusign long long: |%llu|\n", a, b, c);
	ft_printf("\nusign: |%15u|\nusign long: |%15lu|\nusign long long: |%25llu|\n", a, b, c);
	printf("usign: |%15u|\nusign long: |%15lu|\nusign long long: |%25llu|\n", a, b, c);
	ft_printf("\nusign: |%-15u|\nusign long: |%-15lu|\nusign long long: |%-25llu|\n", a, b, c);
	printf("usign: |%-15u|\nusign long: |%-15lu|\nusign long long: |%-25llu|\n", a, b, c);
}

int		main(void)
{
	ft_printf("%%04i 42 == |%04i|\n", 42);
	ft_printf("%%05i 42 == |%05i|\n", 42);
	ft_printf("%%0i 42 == |%0i|\n", 42);
	ft_printf("%%0d 0000042 == |%0d|\n", 0000042);

	printf("%%04i 42 == |%04i|\n", 42);
	printf("%%05i 42 == |%05i|\n", 42);
	printf("%%0i 42 == |%0i|\n", 42);
	printf("%%0d 0000042 == |%0d|\n", 0000042);
	// STRING TESTS:
	//str_tests();

	// INTEGER TESTS:
	// int_tests();

	// OCTAL TESTS:
	// octal_test();

	// HEX TESTS:
	// hex_test();

	// FLOAT TESTS:
	//float_test(); // Working

	// POINTER TESTS:
	// pointer_test();

	// UNSIGNED TESTS:
	// unsigned_test();
	return (0);
}
