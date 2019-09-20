#include <limits.h>
#include <unistd.h>
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
	ft_printf("Mine: %%i\n");
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

	ft_printf("\ntheirs: %%i\n\n");
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
	ft_printf("Mine:\n");

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

	// int			r00 = 0;
	char		c = 0;
	char		*str1 = "pouet";
	
	int meow = ft_printf("int pointer: %p\nStr pointer: %p\n", iptr, sptr);
	int moo = printf("int pointer: %p\nStr pointer: %p\n", iptr, sptr);

	meow += ft_printf("%p\n", &c);
	moo += printf("%p\n", &c);

	meow += ft_printf("%p\n", str1);
	moo += printf("%p\n", str1);

	meow += ft_printf("%p\n", &str1);
	moo += printf("%p\n", &str1);

	str1 = NULL;
	meow += ft_printf("%p\n", str1);
	moo += printf("%p\n", str1);

	str1 = (char *)malloc(sizeof(char) * 10);
	str1 = strdup("Coucou les haricots !");
	meow += ft_printf("%p\n", str1);
	moo += printf("%p\n", str1);

	if (meow == moo)
		ft_printf(ft_strjoin(ft_strjoin(FT_GREEN, "Pass\n"), FT_END_ATTR));
	else
		ft_printf(ft_strjoin(ft_strjoin(FT_RED, "Fail\n"), FT_END_ATTR));
}

void	unsigned_test()
{
	ft_printf("\nMine:\n");
	int ar = ft_printf("%u", 42);
	ar += ft_printf("Kashim a %u histoires à raconter", 1001);
	ar += ft_printf("Il fait au moins %u\n", -8000);
	ar += ft_printf("%u", -0);
	ar += ft_printf("%u", 0);
	ar += ft_printf("%u", INT_MAX);
	ar += ft_printf("%u", INT_MIN);
	ar += ft_printf("%u", INT_MIN - 1);
	ar += ft_printf("%u", INT_MAX + 1);
	ar += ft_printf("%%u 0000042 == |%u|\n", 0000042);
	ar += ft_printf("%%u \t == |%u|\n", '\t');
	ar += ft_printf("%%u Lydie == |%u|\n", 'L'+'y'+'d'+'i'+'e');

	ft_printf("\nTheirs:\n");
	int br = printf("%u", 42);
	br += printf("Kashim a %u histoires à raconter", 1001);
	br += printf("Il fait au moins %u\n", -8000);
	br += printf("%u", -0);
	br += printf("%u", 0);
	br += printf("%u", INT_MAX);
	br += printf("%u", INT_MIN);
	br += printf("%u", INT_MIN - 1);
	br += printf("%u", INT_MAX + 1);
	br += printf("%%u 0000042 == |%u|\n", 0000042);
	br += printf("%%u \t == |%u|\n", '\t');
	br += printf("%%u Lydie == |%u|\n", 'L'+'y'+'d'+'i'+'e');

	if (ar == br)
		ft_printf("\nPass\n");
	else
		ft_printf("\nFail\n\n");
	unsigned a = 123456678;
	unsigned long b = 0xdeadbeef;
	unsigned long long c = 0x7fffffffffffffff;
	unsigned char aa = -125;
	unsigned int bb = -125;
	unsigned long cc = -125;
	unsigned short dd = -125;
	size_t ee = -125;
	uintmax_t ff = -125;
	unsigned long long	gg = -125;

	unsigned char hh = 0;
	unsigned int ii = 0;
	unsigned long jj = 0;
	unsigned short kk = 0;
	size_t ll = 0;
	uintmax_t mm = 0;
	unsigned long long nn = 0;

	unsigned char oo = (unsigned char)~0U>>1;
	unsigned int pp = ~0U>>1;
	unsigned long qq = ~0U>>1;
	unsigned short rr = (short)~0U>>1;
	size_t ss = (size_t)~0U>>1;
	uintmax_t tt = (uintmax_t)~0U>>1;
	unsigned long long uu = (unsigned long long)~0U>>1;

	unsigned char vv = -mm-1;
	unsigned int ww = -nn-1;
	unsigned long xx = -oo-1;
	unsigned short yy = -pp-1;
	unsigned long zz = -qq-1;
	uintmax_t zzz = -rr-1;
	unsigned long long aaa = -rr-1;

	ft_printf("usign: |%u|\nusign long: |%lu|\nusign long long: |%llu|\n", a, b, c);
	printf("usign: |%u|\nusign long: |%lu|\nusign long long: |%llu|\n", a, b, c);
	ft_printf("\nusign: |%15u|\nusign long: |%15lu|\nusign long long: |%25llu|\n", a, b, c);
	printf("usign: |%15u|\nusign long: |%15lu|\nusign long long: |%25llu|\n", a, b, c);
	ft_printf("\nusign: |%-15u|\nusign long: |%-15lu|\nusign long long: |%-25llu|\n", a, b, c);
	printf("usign: |%-15u|\nusign long: |%-15lu|\nusign long long: |%-25llu|\n", a, b, c);

	ft_printf("\nMine:\n");
	// ft_printf("sizeof: e = %zu\n", ee);
	ft_printf("unsigned char		a = %hhu sizeof a = %lu\n", aa,sizeof(aa));
	ft_printf("unsigned int		b = %u sizeof b = %lu\n",bb,sizeof(bb));
	ft_printf("unsigned long		c = %lu sizeof c = %lu\n",cc,sizeof(cc));
	ft_printf("unsigned short		d = %hu sizeof d = %lu\n",dd,sizeof(dd));
	ft_printf("size_t			e = %zu sizeof e = %lu\n",ee, sizeof(ee));
	ft_printf("uintmax_t		f = %ju sizeof f = %lu\n",ff, sizeof(ff));
	ft_printf("unsigned long long	g = %llu sizeof g = %lu\n\n",gg,sizeof(gg));

	ft_printf("unsigned char		h = %hhu sizeof h = %lu\n", hh,sizeof(hh));
	ft_printf("unsigned int		i = %u sizeof i = %lu\n",ii,sizeof(ii));
	ft_printf("unsigned long		j = %lu sizeof j = %lu\n",jj,sizeof(jj));
	ft_printf("unsigned short		k = %hu sizeof k = %lu\n",kk,sizeof(kk));
	ft_printf("size_t			l = %zu sizeof l = %lu\n",ll,sizeof(ll));
	ft_printf("uintmax_t		m = %ju sizeof m = %lu\n",mm,sizeof(mm));
	ft_printf("unsigned long long	n = %llu sizeof n = %lu\n\n",nn,sizeof(nn));

	ft_printf("unsigned char		o = %hhu sizeof o = %lu\n", oo,sizeof(oo));
	ft_printf("unsigned int		p = %u sizeof p = %lu\n",pp,sizeof(pp));
	ft_printf("unsigned long		q = %lu sizeof q = %lu\n",qq,sizeof(qq));
	ft_printf("unsigned short		r = %hu sizeof r = %lu\n",rr,sizeof(rr));
	ft_printf("size_t			s = %zu sizeof s = %lu\n",ss,sizeof(ss));
	ft_printf("uintmax_t		t = %ju sizeof t = %lu\n",tt,sizeof(tt));
	ft_printf("unsigned long long	u = %llu sizeof u = %lu\n\n",uu,sizeof(uu));

	ft_printf("unsigned char		v = %hhu sizeof v = %lu\n", vv,sizeof(vv));
	ft_printf("unsigned int		w = %u sizeof w = %lu\n",ww,sizeof(ww));
	ft_printf("unsigned long		x = %lu sizeof x = %lu\n",xx,sizeof(xx));
	ft_printf("unsigned short		y = %hu sizeof y = %lu\n",yy,sizeof(yy));
	ft_printf("size_t			z = %zu sizeof z = %lu\n",zz,sizeof(zz));
	ft_printf("uintmax_t		zz = %ju sizeof zz = %lu\n",zzz,sizeof(zzz));
	ft_printf("unsigned long long	aa = %llu sizeof aa = %lu\n\n",aaa,sizeof(aaa));

	ft_printf("\nTheirs:\n");
	// printf("sizeof: e = %zu\n", ee);
	printf("unsigned char		a = %hhu sizeof a = %lu\n", aa,sizeof(aa));
	printf("unsigned int		b = %u sizeof b = %lu\n",bb,sizeof(bb));
	printf("unsigned long		c = %lu sizeof c = %lu\n",cc,sizeof(cc));
	printf("unsigned short		d = %hu sizeof d = %lu\n",dd,sizeof(dd));
	printf("size_t			e = %zu sizeof e = %lu\n",ee,sizeof(ee));
	printf("uintmax_t		f = %ju sizeof f = %lu\n",ff,sizeof(ff));
	printf("unsigned long long	g = %llu sizeof g = %lu\n\n",gg,sizeof(gg));

	printf("unsigned char		h = %hhu sizeof h = %lu\n", hh,sizeof(hh));
	printf("unsigned int		i = %u sizeof i = %lu\n",ii,sizeof(ii));
	printf("unsigned long		j = %lu sizeof j = %lu\n",jj,sizeof(jj));
	printf("unsigned short		k = %hu sizeof k = %lu\n",kk,sizeof(kk));
	printf("size_t			l = %zu sizeof l = %lu\n",ll,sizeof(ll));
	printf("uintmax_t		m = %ju sizeof m = %lu\n",mm,sizeof(mm));
	printf("unsigned long long	n = %llu sizeof n = %lu\n\n",nn,sizeof(nn));

	printf("unsigned char		o = %hhu sizeof o = %lu\n", oo,sizeof(oo));
	printf("unsigned int		p = %u sizeof p = %lu\n",pp,sizeof(pp));
	printf("unsigned long		q = %lu sizeof q = %lu\n",qq,sizeof(qq));
	printf("unsigned short		r = %hu sizeof r = %lu\n",rr,sizeof(rr));
	printf("size_t			s = %zu sizeof s = %lu\n",ss,sizeof(ss));
	printf("uintmax_t		t = %ju sizeof t = %lu\n",tt,sizeof(tt));
	printf("unsigned long long	u = %llu sizeof u = %lu\n\n",uu,sizeof(uu));

	printf("unsigned char		v = %hhu sizeof v = %lu\n", vv,sizeof(vv));
	printf("unsigned int		w = %u sizeof w = %lu\n",ww,sizeof(ww));
	printf("unsigned long		x = %lu sizeof x = %lu\n",xx,sizeof(xx));
	printf("unsigned short		y = %hu sizeof y = %lu\n",yy,sizeof(yy));
	printf("size_t			z = %zu sizeof z = %lu\n",zz,sizeof(zz));
	printf("uintmax_t		zz = %ju sizeof zz = %lu\n",zzz,sizeof(zzz));
	printf("unsigned long long	aa = %llu sizeof aa = %lu\n\n",aaa,sizeof(aaa));
}

void	validate_str(char *fmt, void *arg)
{
	char *str;

	str = (char *)arg;
	int a = ft_printf(ft_strjoin(ft_strjoin("Mine: |",fmt), "|\n"), str);
	int b = printf(ft_strjoin(ft_strjoin("Theirs: |",fmt), "|\n"), str);
	ft_printf("\n");
	if (a == (b - 2))
		ft_printf(ft_strjoin(FT_GREEN, ft_strjoin("Pass\n", FT_END_ATTR)));
	else
		ft_printf(ft_strjoin(FT_RED, ft_strjoin("Fail\n", FT_END_ATTR)));
}

void	validate_int(char *fmt, int arg)
{
	int a = ft_printf(ft_strjoin(ft_strjoin("Mine: |",fmt), "|\n"), arg);
	int b = printf(ft_strjoin(ft_strjoin("Theirs: |",fmt), "|\n"), arg);
	ft_printf("\n");
	if (a == (b - 2))
		ft_printf(ft_strjoin(FT_GREEN, ft_strjoin("Pass\n", FT_END_ATTR)));
	else
		ft_printf(ft_strjoin(FT_RED, ft_strjoin("Fail\n", FT_END_ATTR)));
}

void	char_test()
{
	int	meow = ft_printf("%c", 42);
	meow += ft_printf("Kashim a %c histoires à raconter", 1001);
	meow += ft_printf("Il fait au moins %c\n", -8000);
	meow += ft_printf("%c", -0);
	meow += ft_printf("%c", 0);
	meow += ft_printf("%c\n", INT_MAX);
	meow += ft_printf("%c\n", 'c');
	meow += ft_printf("%c\n", '\n');
	meow += ft_printf("%c", 'l');
	meow += ft_printf("%c", 'y');
	meow += ft_printf("%c", ' ');
	meow += ft_printf("%c", 'e');
	meow += ft_printf("%c", 's');
	meow += ft_printf("%c", 't');
	meow += ft_printf("%c", ' ');
	meow += ft_printf("%c", 'f');
	meow += ft_printf("%c", 'a');
	meow += ft_printf("%c", 'n');
	meow += ft_printf("%c", 't');
	meow += ft_printf("%c", 'a');
	meow += ft_printf("%c", 's');
	meow += ft_printf("%c", 't');
	meow += ft_printf("%c", 'i');
	meow += ft_printf("%c", 'q');
	meow += ft_printf("%c", 'u');
	meow += ft_printf("%c", 'e');
	meow += ft_printf("%c\n", '!');
	meow += ft_printf("%c\n", '\r');
	meow += ft_printf("%c\n", '\t');

	int moo = printf("%c", 42);
	moo += printf("Kashim a %c histoires à raconter", 1001);
	moo += printf("Il fait au moins %c\n", -8000);
	moo += printf("%c", -0);
	moo += printf("%c", 0);
	moo += printf("%c\n", INT_MAX);
	moo += printf("%c\n", 'c');
	moo += printf("%c\n", '\n');
	moo += printf("%c", 'l');
	moo += printf("%c", 'y');
	moo += printf("%c", ' ');
	moo += printf("%c", 'e');
	moo += printf("%c", 's');
	moo += printf("%c", 't');
	moo += printf("%c", ' ');
	moo += printf("%c", 'f');
	moo += printf("%c", 'a');
	moo += printf("%c", 'n');
	moo += printf("%c", 't');
	moo += printf("%c", 'a');
	moo += printf("%c", 's');
	moo += printf("%c", 't');
	moo += printf("%c", 'i');
	moo += printf("%c", 'q');
	moo += printf("%c", 'u');
	moo += printf("%c", 'e');
	moo += printf("%c\n", '!');
	moo += printf("%c\n", '\r');
	moo += printf("%c\n", '\t');

	if (meow == moo)
		ft_printf(ft_strjoin(ft_strjoin(FT_GREEN, "Pass\n"), FT_END_ATTR));
	else
		ft_printf(ft_strjoin(ft_strjoin(FT_RED, "Fail\n"), FT_END_ATTR));
}

int		main(void)
{
	char str[6] = "pasta";
	char *sptr;
	sptr = str;

	// int a = ft_printf("Kashim a %c histoires à raconter\n", 1001);
	// int b = printf("Kashim a %c histoires à raconter\n", 1001);
	// int a = ft_printf("Il fait au moins %c\n", -8000);
	// int b = printf("Il fait au moins %c\n", -8000);
	// int a = ft_printf("%c\n", INT_MAX);
	// int b = printf("%c\n", INT_MAX);
	// int	a = ft_printf("|%ld|\n", -0);
	// int	b = printf("|%ld|\n", -0);
	// int	a = ft_printf("%%#o 0 ==  %#o\n", 0);
	// int	b = printf("%%#o 0 ==  %#o\n", 0);
	//void *s_hidden = (void *)sptr;
	// validate_str("%4.0s", (void *)"hello");
	// validate_str("%.0s", (void *)"hello");
	// validate_str("%4.s", (void *)"hello");
	// validate_str("%4.0s", (void *)"hello");
	// ft_printf("%32s", NULL);
	// ft_printf("\n");
	// printf("%32s", NULL);

	// ft_printf("\n");
	// ft_printf("%-32s", NULL);
	// ft_printf("\n");
	// printf("%-32s", NULL);
	
	// ft_printf("\n");
	// ft_printf("%-16s", NULL);
	// ft_printf("\n");
	// printf("%-16s", NULL);
	
	// ft_printf("\n");
	// ft_printf("%-16s", NULL);
	// ft_printf("\n");
	// printf("%-16s", NULL);
	//ft_printf("Mine:\n");
	// ft_printf("%.0s", NULL);
	// int a = ft_printf("Kashim a %c histoires à raconter", 1001);
	// int a = ft_printf("%d", -0);
	// ft_printf("\n");
	// int a = ft_printf("%d", 0);
	// int a = ft_printf("%c\n", INT_MAX);
	// int c = ft_printf("%x", -42);
	// ft_printf("%-.03s", NULL);
	// ft_printf("%.u, %.0u", 0, 0);
	// int a = ft_printf("%x", -42);
	//printf("%Zebra% %@%#%^%(%");
	// int a = ft_printf("%llf", 42.5);
	// ft_printf("\n");
	// ft_printf("%-.s", NULL);
	// ft_printf("%-.14s", NULL);
	// ft_printf("%-.03s", NULL);
	// ft_printf("%.s", NULL);
	// ft_printf("%0.s", NULL);
	// ft_printf("%0s", NULL);
	// ft_printf("%s", NULL);

	// ft_printf("\nTheirs:\n");
	// printf("%.0s", NULL);
	// int b = printf("Kashim a %c histoires à raconter", 1001);
	// int b = printf("%d", -0);
	// printf("\n");
	// int b = printf("%d", 0);
	// int b = printf("%c\n", INT_MAX);
	// int b = ft_printf("%llf", 42.5);
	// int d = printf("%x", -42);
	// printf("%-.03s", NULL);
	// printf("%.u, %.0u", 0, 0);
	// int b = printf("%x", -42);
	//printf("%Zebra% %@%#%^%(%");
	// printf("\n");
	// if (c == d)
	// 	ft_printf("\nGOOD\n");
	// printf("%-.s", NULL);
	// printf("%-.14s", NULL);
	// printf("%-.03s", NULL);
	// printf("%.s", NULL);
	// printf("%0.s", NULL);
	// printf("%0s", NULL);
	// printf("%s", NULL);

	// ft_printf("\ntheirs:\n");
	// int b = printf("%.03s", NULL);

	// ft_printf("\nmine:\n");
	// int	a = ft_printf("%.03s", NULL);

	// ft_printf("%d - %d\n", a, b);

	// ft_printf("\nINT\n");
	// validate_int("%4.0d", 0);
	// validate_int("%.0d", 0);
	// validate_int("%4.d", 0);
	// validate_int("%4.0d", 0);
	
	// int ret_a = printf("%.d", 1);
	// ft_printf("size: %d\n", ret_a);
	// int ret_b = ft_printf("%.d", 1);
	// ft_printf("size: %d\n", ret_b);

	//printf("%.4u", 42);
	//ft_printf("%.4u", 42); // unsigned not work with precision yet... meow
	// ft_printf("{%s}", 0);
	// ft_printf("{%s}", "");
	//ft_printf("{%s}", 0);
	// int ret_a = printf("theirs: |%.hhd|\n", 0);
	//ft_printf("size: %d\n", ret_a);
	// int ret_b = ft_printf("mines:  |%.hhd|\n", 0);
	//ft_printf("size: %d\n", ret_b);
	//ft_printf("%.d", 0);
	//printf("%.d, %.0d", 0, 0);
	//ft_printf("%.d, %.0d", 0, 0);
// 	printf("%4.15d\n", -42);
// 	ft_printf("%4.15d\n", -42);
	// printf("%hhd", CHAR_MAX + 42);
	// ft_printf("%hhd", CHAR_MAX + 42);
	// ft_printf("After:\n");
	// int	ret_a = ft_printf("%.c", 0);
	// ft_printf("\n");
	// int	ret_b = printf("%.c", 0);
	// if (ret_a == ret_b)
	// 	ft_printf(ft_strjoin(FT_GREEN, ft_strjoin("SUCCESS!!\n", FT_END_ATTR)));
	// else
	// 	ft_printf(ft_strjoin(FT_RED, ft_strjoin("FAIL :(\n", FT_END_ATTR)));
	// ft_printf("%%04i 42 == |%x|\n", -42);
	// ft_printf("%%05i 42 == |%x|\n", -42);
	// ft_printf("%%0i 42 == |%x|\n", -42);
	// ft_printf("%%0d 0000042 == |%x|\n", -0000042);

	// printf("%%04i 42 == |%x|\n", -42);
	// printf("%%05i 42 == |%x|\n", -42);
	// printf("%%0i 42 == |%x|\n", -42);
	// printf("%%0d 0000042 == |%x|\n", -0000042);
	// printf("%%04i 42 == |%04c|\n", (char)42);
	// printf("%%05i 42 == |%05c|\n", (char)42);
	// printf("%%0i 42 == |%0c|\n", (char)42);
	// printf("%%0d 0000042 == |%0c|\n", (char)0000042);
	// long f = -0;
	// ft_printf("|%+20.5ld|\n", f);
	// printf("|%+20.5ld|\n", f);
	
		// int a = ft_printf("|%.o|\n", 42);
	// int b = printf("|%.o|\n", 42);
	// if (a == b)
	// 	ft_printf("good\n");
	// else
	// 	ft_printf("bad\n");

	// a = ft_printf("|%#.6o|\n", 42);
	// b = printf("|%#.6o|\n", 42);
	// if (a == b)
	// 	ft_printf("good\n");
	// else
	// 	ft_printf("bad\n");
	// a = ft_printf("|%#.4o|\n", 42);
	// b = printf("|%#.4o|\n", 42);
	// if (a == b)
	// 	ft_printf("good\n");
	// else
	// 	ft_printf("bad\n");
	
	//	PLUS TESTS
	// int meow = ft_printf("%%+i 42 == %+i\n", 42);
	// meow += ft_printf("%%+d 42 == %+d\n", INT_MAX);
	// meow += ft_printf("%%+i -42 == %+i\n", -42);
	// int meow = ft_printf("%%+04d 42 == %0+04d\n", 42);

	// int moo = printf("%%+i 42 == %+i\n", 42);
	// moo += printf("%%+d 42 == %+d\n", INT_MAX);
	// moo += printf("%%+i -42 == %+i\n", -42);
	// int moo = printf("%%+04d 42 == %0+04d\n", 42);

	// if (meow == moo)
	// 	ft_printf(ft_strjoin(FT_GREEN, ft_strjoin("SUCCESS!!\n", FT_END_ATTR)));
	// else
	// 	ft_printf(ft_strjoin(FT_RED, ft_strjoin("FAIL :(\n", FT_END_ATTR)));
	// CHAR tests
	// char_test(); // Working
	
	// STRING TESTS:
	// str_tests(); // working

	// INTEGER TESTS:
	// ft_printf("|%-3.1s|\n", NULL);
	// printf("|%-3.1s|\n", NULL);
	// int_tests(); // working

	// ft_printf("Il fait au moins %ld\n", -8000);
	// printf("Il fait au moins %ld\n", -8000);
	// ft_printf("Int 6: |%+10.5hd|\n", -5000);
	// printf("Int 6: |%+10.5hd|\n", -5000);
	// ft_printf("%%+04d 42 == %0+04d\n", 42);
	// printf("%%+04d 42 == %0+04d\n", 42);

	// ft_printf("%%      i 42 == |% i|\n", 42);
	// printf("%%      i 42 == |% i|\n", 42);
	// ft_printf("%%      i 42 == |%  i|\n", 42);
	// printf("%%      i 42 == |%  i|\n", 42);
	
	// ft_printf("%%      d 42 == |% d|\n", 42);
	// printf("%%      d 42 == |% d|\n", 42);
	// ft_printf("%%      d 42 == |%  d|\n", 42);
	// printf("%%      d 42 == |%  d|\n", 42);
	// int meow = ft_printf("%%-5.3s LYDI == |%-5.3s|\n", "LYDI");
	// meow += ft_printf("%% 4.5i 42 == |% 4.5i|\n", 42);
	// meow += ft_printf("%%04.5i 42 == |%04.5i|\n", 42);
	// meow += ft_printf("%%04.3i 42 == |%04.3i|\n", 42);
	// meow += ft_printf("%%04.2i 42 == |%04.2i|\n", 42);
	// ft_printf("\ntheirs:\n");
	// int moo = printf("%%-5.3s LYDI == |%-5.3s|\n", "LYDI");
	// moo += printf("%% 4.5i 42 == |% 4.5i|\n", 42);
	// moo += printf("%%04.5i 42 == |%04.5i|\n", 42);
	// moo += printf("%%04.3i 42 == |%04.3i|\n", 42);
	// moo += printf("%%04.2i 42 == |%04.2i|\n", 42);
	// if (meow == moo)
	// 	ft_printf(ft_strjoin(FT_GREEN, ft_strjoin("SUCCESS!!\n", FT_END_ATTR)));
	// else
	// 	ft_printf(ft_strjoin(FT_RED, ft_strjoin("FAIL :(\n", FT_END_ATTR)));

	// OCTAL TESTS:
	// octal_test(); // working

	// HEX TESTS:
	// hex_test(); // Working

	// FLOAT TESTS:
	// float_test(); // Working

	// POINTER TESTS:
	// pointer_test(); // Working

	// UNSIGNED TESTS:
	// unsigned_test(); // Working

	// ft_printf("%#s\n", "hello");
	// printf("%#s\n", "hello");

	// long double a = 42.5;

	// ft_printf("%llf\n", 42.5);
	// printf("%llf\n", 42.5);
	//ft_printf("%% i -42 == |% i|\n", -42);
	//printf("%% i -42 == |% i|\n", -42);

	//ft_printf("%% d -42 == |% d|\n", -42);
	//printf("%% d -42 == |% d|\n", -42);
	ft_printf("%0+04d\n", 42);
	// system("leaks ft_printf");
	printf("%0+04d\n", 42);


	// ft_printf("%%04.3i 42 == |%04.3i|\n", 42);
	// printf("%%04.3i 42 == |%04.3i|\n", 42);

	// ft_printf("%%#X INT_MIN ==  %#X\n", INT_MIN);
	// printf("%%#X INT_MIN ==  %#X\n", INT_MIN);
	// ft_printf("|%+00015d|\n", 42);
	// printf("|%+00015d|\n", 42);
	
	return (0);
}
