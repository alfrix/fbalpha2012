// FB Alpha CPS-2 driver module

// Maintained by Creamymami && KOF2112

#include "cps.h"


//-----------------------------------------------------------------------------------
// Inputs


// 1944, 19xx, Giga Wing
static struct BurnInputInfo gwingInputList[] = {
	{"P1 Coin"       , BIT_DIGITAL, CpsInp020+4, "p1 coin"	},
	{"P1 Start"      , BIT_DIGITAL, CpsInp020+0, "p1 start"	},
	{"P1 Up"         , BIT_DIGITAL, CpsInp001+3, "p1 up"	},
	{"P1 Down"       , BIT_DIGITAL, CpsInp001+2, "p1 down"	},
	{"P1 Left"       , BIT_DIGITAL, CpsInp001+1, "p1 left"	},
	{"P1 Right"      , BIT_DIGITAL, CpsInp001+0, "p1 right"	},
	{"P1 Shot"       , BIT_DIGITAL, CpsInp001+4, "p1 fire 1"},
	{"P1 Bomb"       , BIT_DIGITAL, CpsInp001+5, "p1 fire 2"},

	{"P2 Coin"       , BIT_DIGITAL, CpsInp020+5, "p2 coin"	},
	{"P2 Start"      , BIT_DIGITAL, CpsInp020+1, "p2 start"	},
	{"P2 Up"         , BIT_DIGITAL, CpsInp000+3, "p2 up"	},
	{"P2 Down"       , BIT_DIGITAL, CpsInp000+2, "p2 down"	},
	{"P2 Left"       , BIT_DIGITAL, CpsInp000+1, "p2 left"	},
	{"P2 Right"      , BIT_DIGITAL, CpsInp000+0, "p2 right"	},
	{"P2 Shot"       , BIT_DIGITAL, CpsInp000+4, "p2 fire 1"},
	{"P2 Bomb"       , BIT_DIGITAL, CpsInp000+5, "p2 fire 2"},

	{"Reset"         , BIT_DIGITAL, &CpsReset  , "reset"	},
	{"Diagnostic"    , BIT_DIGITAL, CpsInp021+1, "diag"	},
	{"Service"       , BIT_DIGITAL, CpsInp021+2, "service"	},
};

STDINPUTINFO(gwing)

// Mars Matrix
static struct BurnInputInfo mmatrixInputList[] =
{
	{"P1 Coin"       , BIT_DIGITAL, CpsInp020+4, "p1 coin"  },
	{"P1 Start"      , BIT_DIGITAL, CpsInp020+0, "p1 start" },
	{"P1 Up"         , BIT_DIGITAL, CpsInp001+3, "p1 up"    },
	{"P1 Down"       , BIT_DIGITAL, CpsInp001+2, "p1 down"  },
	{"P1 Left"       , BIT_DIGITAL, CpsInp001+1, "p1 left"  },
	{"P1 Right"      , BIT_DIGITAL, CpsInp001+0, "p1 right" },
	{"P1 Shot"       , BIT_DIGITAL, CpsInp001+4, "p1 fire 1"},

	{"P2 Coin"       , BIT_DIGITAL, CpsInp020+5, "p2 coin"  },
	{"P2 Start"      , BIT_DIGITAL, CpsInp020+1, "p2 start" },
	{"P2 Up"         , BIT_DIGITAL, CpsInp000+3, "p2 up"    },
	{"P2 Down"       , BIT_DIGITAL, CpsInp000+2, "p2 down"  },
	{"P2 Left"       , BIT_DIGITAL, CpsInp000+1, "p2 left"  },
	{"P2 Right"      , BIT_DIGITAL, CpsInp000+0, "p2 right" },
	{"P2 Shot"       , BIT_DIGITAL, CpsInp000+4, "p2 fire 1"},

	{"Reset"         , BIT_DIGITAL, &CpsReset  , "reset"    },
	{"Diagnostic"    , BIT_DIGITAL, CpsInp021+1, "diag"     },
	{"Service"       , BIT_DIGITAL, CpsInp021+2, "service"  },
};

STDINPUTINFO(mmatrix)


// Armored Warriors
static struct BurnInputInfo armwarInputList[] =
{
	{"P1 Coin"       , BIT_DIGITAL, CpsInp020+4, "p1 coin"  },
	{"P1 Start"      , BIT_DIGITAL, CpsInp020+0, "p1 start" },
	{"P1 Up"         , BIT_DIGITAL, CpsInp001+3, "p1 up"    },
	{"P1 Down"       , BIT_DIGITAL, CpsInp001+2, "p1 down"  },
	{"P1 Left"       , BIT_DIGITAL, CpsInp001+1, "p1 left"  },
	{"P1 Right"      , BIT_DIGITAL, CpsInp001+0, "p1 right" },
	{"P1 Attack"     , BIT_DIGITAL, CpsInp001+4, "p1 fire 1"},
	{"P1 Jump"       , BIT_DIGITAL, CpsInp001+5, "p1 fire 2"},
	{"P1 Shot"       , BIT_DIGITAL, CpsInp001+6, "p1 fire 3"},

	{"P2 Coin"       , BIT_DIGITAL, CpsInp020+5, "p2 coin"  },
	{"P2 Start"      , BIT_DIGITAL, CpsInp020+1, "p2 start" },
	{"P2 Up"         , BIT_DIGITAL, CpsInp000+3, "p2 up"    },
	{"P2 Down"       , BIT_DIGITAL, CpsInp000+2, "p2 down"  },
	{"P2 Left"       , BIT_DIGITAL, CpsInp000+1, "p2 left"  },
	{"P2 Right"      , BIT_DIGITAL, CpsInp000+0, "p2 right" },
	{"P2 Attack"     , BIT_DIGITAL, CpsInp000+4, "p2 fire 1"},
	{"P2 Jump"       , BIT_DIGITAL, CpsInp000+5, "p2 fire 2"},
	{"P2 Shot"       , BIT_DIGITAL, CpsInp000+6, "p2 fire 3"},

	{"P3 Coin"       , BIT_DIGITAL, CpsInp020+6, "p3 coin"  },
	{"P3 Start"      , BIT_DIGITAL, CpsInp020+2, "p3 start" },
	{"P3 Up"         , BIT_DIGITAL, CpsInp011+3, "p3 up"    },
	{"P3 Down"       , BIT_DIGITAL, CpsInp011+2, "p3 down"  },
	{"P3 Left"       , BIT_DIGITAL, CpsInp011+1, "p3 left"  },
	{"P3 Right"      , BIT_DIGITAL, CpsInp011+0, "p3 right" },
	{"P3 Attack"     , BIT_DIGITAL, CpsInp011+4, "p3 fire 1"},
	{"P3 Jump"       , BIT_DIGITAL, CpsInp011+5, "p3 fire 2"},
	{"P3 Shot"       , BIT_DIGITAL, CpsInp011+6, "p3 fire 3"},

	{"Reset"         , BIT_DIGITAL, &CpsReset  , "reset"    },
	{"Diagnostic"    , BIT_DIGITAL, CpsInp021+1, "diag"     },
	{"Service"       , BIT_DIGITAL, CpsInp021+2, "service"  },
};

STDINPUTINFO(armwar)


// Alien vs. Predator
static struct BurnInputInfo avspInputList[] =
{
	{"P1 Coin"       , BIT_DIGITAL, CpsInp020+4, "p1 coin"  },
	{"P1 Start"      , BIT_DIGITAL, CpsInp020+0, "p1 start" },
	{"P1 Up"         , BIT_DIGITAL, CpsInp001+3, "p1 up"    },
	{"P1 Down"       , BIT_DIGITAL, CpsInp001+2, "p1 down"  },
	{"P1 Left"       , BIT_DIGITAL, CpsInp001+1, "p1 left"  },
	{"P1 Right"      , BIT_DIGITAL, CpsInp001+0, "p1 right" },
	{"P1 Shot"       , BIT_DIGITAL, CpsInp001+4, "p1 fire 1"},
	{"P1 Attack"     , BIT_DIGITAL, CpsInp001+5, "p1 fire 2"},
	{"P1 Jump"       , BIT_DIGITAL, CpsInp001+6, "p1 fire 3"},

	{"P2 Coin"       , BIT_DIGITAL, CpsInp020+5, "p2 coin"  },
	{"P2 Start"      , BIT_DIGITAL, CpsInp020+1, "p2 start" },
	{"P2 Up"         , BIT_DIGITAL, CpsInp000+3, "p2 up"    },
	{"P2 Down"       , BIT_DIGITAL, CpsInp000+2, "p2 down"  },
	{"P2 Left"       , BIT_DIGITAL, CpsInp000+1, "p2 left"  },
	{"P2 Right"      , BIT_DIGITAL, CpsInp000+0, "p2 right" },
	{"P2 Shot"       , BIT_DIGITAL, CpsInp000+4, "p2 fire 1"},
	{"P2 Attack"     , BIT_DIGITAL, CpsInp000+5, "p2 fire 2"},
	{"P2 Jump"       , BIT_DIGITAL, CpsInp000+6, "p2 fire 3"},

	{"P3 Coin"       , BIT_DIGITAL, CpsInp020+6, "p3 coin"  },
	{"P3 Start"      , BIT_DIGITAL, CpsInp020+2, "p3 start" },
	{"P3 Up"         , BIT_DIGITAL, CpsInp011+3, "p3 up"    },
	{"P3 Down"       , BIT_DIGITAL, CpsInp011+2, "p3 down"  },
	{"P3 Left"       , BIT_DIGITAL, CpsInp011+1, "p3 left"  },
	{"P3 Right"      , BIT_DIGITAL, CpsInp011+0, "p3 right" },
	{"P3 Shot"       , BIT_DIGITAL, CpsInp011+4, "p3 fire 1"},
	{"P3 Attack"     , BIT_DIGITAL, CpsInp011+5, "p3 fire 2"},
	{"P3 Jump"       , BIT_DIGITAL, CpsInp011+6, "p3 fire 3"},

	{"Reset"         , BIT_DIGITAL, &CpsReset  , "reset"    },
	{"Diagnostic"    , BIT_DIGITAL, CpsInp021+1, "diag"     },
	{"Service"       , BIT_DIGITAL, CpsInp021+2, "service"  },
};

STDINPUTINFO(avsp)


// Battle Circuit
static struct BurnInputInfo batcirInputList[] =
{
	{"P1 Coin"       , BIT_DIGITAL, CpsInp020+4, "p1 coin"  },
	{"P1 Start"      , BIT_DIGITAL, CpsInp020+0, "p1 start" },
	{"P1 Up"         , BIT_DIGITAL, CpsInp001+3, "p1 up"    },
	{"P1 Down"       , BIT_DIGITAL, CpsInp001+2, "p1 down"  },
	{"P1 Left"       , BIT_DIGITAL, CpsInp001+1, "p1 left"  },
	{"P1 Right"      , BIT_DIGITAL, CpsInp001+0, "p1 right" },
	{"P1 Attack"     , BIT_DIGITAL, CpsInp001+4, "p1 fire 1"},
	{"P1 Jump"       , BIT_DIGITAL, CpsInp001+5, "p1 fire 2"},

	{"P2 Coin"       , BIT_DIGITAL, CpsInp020+5, "p2 coin"  },
	{"P2 Start"      , BIT_DIGITAL, CpsInp020+1, "p2 start" },
	{"P2 Up"         , BIT_DIGITAL, CpsInp000+3, "p2 up"    },
	{"P2 Down"       , BIT_DIGITAL, CpsInp000+2, "p2 down"  },
	{"P2 Left"       , BIT_DIGITAL, CpsInp000+1, "p2 left"  },
	{"P2 Right"      , BIT_DIGITAL, CpsInp000+0, "p2 right" },
	{"P2 Attack"     , BIT_DIGITAL, CpsInp000+4, "p2 fire 1"},
	{"P2 Jump"       , BIT_DIGITAL, CpsInp000+5, "p2 fire 2"},

	{"P3 Coin"       , BIT_DIGITAL, CpsInp020+6, "p3 coin"  },
	{"P3 Start"      , BIT_DIGITAL, CpsInp020+2, "p3 start" },
	{"P3 Up"         , BIT_DIGITAL, CpsInp011+3, "p3 up"    },
	{"P3 Down"       , BIT_DIGITAL, CpsInp011+2, "p3 down"  },
	{"P3 Left"       , BIT_DIGITAL, CpsInp011+1, "p3 left"  },
	{"P3 Right"      , BIT_DIGITAL, CpsInp011+0, "p3 right" },
	{"P3 Attack"     , BIT_DIGITAL, CpsInp011+4, "p3 fire 1"},
	{"P3 Jump"       , BIT_DIGITAL, CpsInp011+5, "p3 fire 2"},

	{"P4 Coin"       , BIT_DIGITAL, CpsInp020+7, "p4 coin"  },
	{"P4 Start"      , BIT_DIGITAL, CpsInp020+3, "p4 start" },
	{"P4 Up"         , BIT_DIGITAL, CpsInp010+3, "p4 up"    },
	{"P4 Down"       , BIT_DIGITAL, CpsInp010+2, "p4 down"  },
	{"P4 Left"       , BIT_DIGITAL, CpsInp010+1, "p4 left"  },
	{"P4 Right"      , BIT_DIGITAL, CpsInp010+0, "p4 right" },
	{"P4 Attack"     , BIT_DIGITAL, CpsInp010+4, "p4 fire 1"},
	{"P4 Jump"       , BIT_DIGITAL, CpsInp010+5, "p4 fire 2"},

	{"Reset"         , BIT_DIGITAL, &CpsReset,   "reset"    },
	{"Diagnostic"    , BIT_DIGITAL, CpsInp021+1, "diag"     },
	{"Service"       , BIT_DIGITAL, CpsInp021+2, "service"  },
};

STDINPUTINFO(batcir)


// CAPCOM Sports Club
static struct BurnInputInfo csclubInputList[] =
{
	{"P1 Coin"    ,BIT_DIGITAL, CpsInp020+4, "p1 coin"  },
	{"P1 Start"   ,BIT_DIGITAL, CpsInp020+0, "p1 start" },
	{"P1 Up"      ,BIT_DIGITAL, CpsInp001+3, "p1 up"    },
	{"P1 Down"    ,BIT_DIGITAL, CpsInp001+2, "p1 down"  },
	{"P1 Left"    ,BIT_DIGITAL, CpsInp001+1, "p1 left"  },
	{"P1 Right"   ,BIT_DIGITAL, CpsInp001+0, "p1 right" },
	{"P1 Button 1",BIT_DIGITAL, CpsInp001+4, "p1 fire 1"},
	{"P1 Button 2",BIT_DIGITAL, CpsInp001+5, "p1 fire 2"},
	{"P1 Button 3",BIT_DIGITAL, CpsInp001+6, "p1 fire 3"},

	{"P2 Coin"    ,BIT_DIGITAL, CpsInp020+5, "p2 coin"  },
	{"P2 Start"   ,BIT_DIGITAL, CpsInp020+1, "p2 start" },
	{"P2 Up"      ,BIT_DIGITAL, CpsInp000+3, "p2 up"    },
	{"P2 Down"    ,BIT_DIGITAL, CpsInp000+2, "p2 down"  },
	{"P2 Left"    ,BIT_DIGITAL, CpsInp000+1, "p2 left"  },
	{"P2 Right"   ,BIT_DIGITAL, CpsInp000+0, "p2 right" },
	{"P2 Button 1",BIT_DIGITAL, CpsInp000+4, "p2 fire 1"},
	{"P2 Button 2",BIT_DIGITAL, CpsInp000+5, "p2 fire 2"},
	{"P2 Button 3",BIT_DIGITAL, CpsInp000+6, "p2 fire 3"},

	{"Reset"      ,BIT_DIGITAL, &CpsReset, "reset"      },
	{"Diagnostic" ,BIT_DIGITAL, CpsInp021+1, "diag"     },
	{"Service"    ,BIT_DIGITAL, CpsInp021+2, "service"  },
};

STDINPUTINFO(csclub)


// Choko
static struct BurnInputInfo chokoInputList[] =
{
	{"P1 Coin"       , BIT_DIGITAL, CpsInp020+4, "p1 coin"},
	{"P1 Start"      , BIT_DIGITAL, CpsInp020+0, "p1 start"},
	{"P1 Up"         , BIT_DIGITAL, CpsInp001+3, "p1 up"},
	{"P1 Down"       , BIT_DIGITAL, CpsInp001+2, "p1 down"},
	{"P1 Left"       , BIT_DIGITAL, CpsInp001+1, "p1 left"},
	{"P1 Right"      , BIT_DIGITAL, CpsInp001+0, "p1 right"},
	{"P1 Shot1"      , BIT_DIGITAL, CpsInp001+4, "p1 fire 1"},
	{"P1 Shot2"      , BIT_DIGITAL, CpsInp001+5, "p1 fire 2"},
	{"P1 Shot3"      , BIT_DIGITAL, CpsInp001+6, "p1 fire 3"},

	{"P2 Coin"       , BIT_DIGITAL, CpsInp020+5, "p2 coin"},

	{"Reset"         , BIT_DIGITAL, &CpsReset  , "reset"},
	{"Diagnostic"    , BIT_DIGITAL, CpsInp021+1, "diag"},
	{"Service"       , BIT_DIGITAL, CpsInp021+2, "service"},
};

STDINPUTINFO(choko)


// Cyberbots
static struct BurnInputInfo cybotsInputList[] =
{
	{"P1 Coin"       , BIT_DIGITAL, CpsInp020+4, "p1 coin"},
	{"P1 Start"      , BIT_DIGITAL, CpsInp020+0, "p1 start"},
	{"P1 Up"         , BIT_DIGITAL, CpsInp001+3, "p1 up"},
	{"P1 Down"       , BIT_DIGITAL, CpsInp001+2, "p1 down"},
	{"P1 Left"       , BIT_DIGITAL, CpsInp001+1, "p1 left"},
	{"P1 Right"      , BIT_DIGITAL, CpsInp001+0, "p1 right"},
	{"P1 Low Attack" , BIT_DIGITAL, CpsInp001+4, "p1 fire 1"},
	{"P1 High Attack", BIT_DIGITAL, CpsInp001+5, "p1 fire 2"},
	{"P1 Boost"      , BIT_DIGITAL, CpsInp001+6, "p1 fire 3"},
	{"P1 Weapon"     , BIT_DIGITAL, CpsInp001+7, "p1 fire 4"},

	{"P2 Coin"       , BIT_DIGITAL, CpsInp020+5, "p2 coin"},
	{"P2 Start"      , BIT_DIGITAL, CpsInp020+1, "p2 start"},
	{"P2 Up"         , BIT_DIGITAL, CpsInp000+3, "p2 up"},
	{"P2 Down"       , BIT_DIGITAL, CpsInp000+2, "p2 down"},
	{"P2 Left"       , BIT_DIGITAL, CpsInp000+1, "p2 left"},
	{"P2 Right"      , BIT_DIGITAL, CpsInp000+0, "p2 right"},
	{"P2 Low Attack" , BIT_DIGITAL, CpsInp000+4, "p2 fire 1"},
	{"P2 High Attack", BIT_DIGITAL, CpsInp000+5, "p2 fire 2"},
	{"P2 Boost"      , BIT_DIGITAL, CpsInp000+6, "p2 fire 3"},
	{"P2 Weapon"     , BIT_DIGITAL, CpsInp000+7, "p2 fire 4"},

	{"Reset"         , BIT_DIGITAL, &CpsReset   , "reset"},
	{"Diagnostic"    , BIT_DIGITAL, CpsInp021+1, "diag"},
	{"Service"       , BIT_DIGITAL, CpsInp021+2, "service"},
};

STDINPUTINFO(cybots)


// Dungeons and Dragons
static struct BurnInputInfo ddsomInputList[] =
{
	{"P1 Coin"       , BIT_DIGITAL, CpsInp020+4, "p1 coin"  },
	{"P1 Start"      , BIT_DIGITAL, CpsInp020+0, "p1 start" },
	{"P1 Up"         , BIT_DIGITAL, CpsInp001+3, "p1 up"    },
	{"P1 Down"       , BIT_DIGITAL, CpsInp001+2, "p1 down"  },
	{"P1 Left"       , BIT_DIGITAL, CpsInp001+1, "p1 left"  },
	{"P1 Right"      , BIT_DIGITAL, CpsInp001+0, "p1 right" },
	{"P1 Attack"     , BIT_DIGITAL, CpsInp001+4, "p1 fire 1"},
	{"P1 Jump"       , BIT_DIGITAL, CpsInp001+5, "p1 fire 2"},
	{"P1 Use"        , BIT_DIGITAL, CpsInp001+6, "p1 fire 3"},
	{"P1 Select"     , BIT_DIGITAL, CpsInp001+7, "p1 fire 4"},

	{"P2 Coin"       , BIT_DIGITAL, CpsInp020+5, "p2 coin"  },
	{"P2 Start"      , BIT_DIGITAL, CpsInp020+1, "p2 start" },
	{"P2 Up"         , BIT_DIGITAL, CpsInp000+3, "p2 up"    },
	{"P2 Down"       , BIT_DIGITAL, CpsInp000+2, "p2 down"  },
	{"P2 Left"       , BIT_DIGITAL, CpsInp000+1, "p2 left"  },
	{"P2 Right"      , BIT_DIGITAL, CpsInp000+0, "p2 right" },
	{"P2 Attack"     , BIT_DIGITAL, CpsInp000+4, "p2 fire 1"},
	{"P2 Jump"       , BIT_DIGITAL, CpsInp000+5, "p2 fire 2"},
	{"P2 Use"        , BIT_DIGITAL, CpsInp000+6, "p2 fire 3"},
	{"P2 Select"     , BIT_DIGITAL, CpsInp000+7, "p2 fire 4"},

	{"P3 Coin"       , BIT_DIGITAL, CpsInp020+6, "p3 coin"  },
	{"P3 Start"      , BIT_DIGITAL, CpsInp020+2, "p3 start" },
	{"P3 Up"         , BIT_DIGITAL, CpsInp011+3, "p3 up"    },
	{"P3 Down"       , BIT_DIGITAL, CpsInp011+2, "p3 down"  },
	{"P3 Left"       , BIT_DIGITAL, CpsInp011+1, "p3 left"  },
	{"P3 Right"      , BIT_DIGITAL, CpsInp011+0, "p3 right" },
	{"P3 Attack"     , BIT_DIGITAL, CpsInp011+4, "p3 fire 1"},
	{"P3 Jump"       , BIT_DIGITAL, CpsInp011+5, "p3 fire 2"},
	{"P3 Use"        , BIT_DIGITAL, CpsInp011+6, "p3 fire 3"},
	{"P3 Select"     , BIT_DIGITAL, CpsInp011+7, "p3 fire 4"},

	{"P4 Coin"       , BIT_DIGITAL, CpsInp020+7, "p4 coin"  },
	{"P4 Start"      , BIT_DIGITAL, CpsInp020+3, "p4 start" },
	{"P4 Up"         , BIT_DIGITAL, CpsInp010+3, "p4 up"    },
	{"P4 Down"       , BIT_DIGITAL, CpsInp010+2, "p4 down"  },
	{"P4 Left"       , BIT_DIGITAL, CpsInp010+1, "p4 left"  },
	{"P4 Right"      , BIT_DIGITAL, CpsInp010+0, "p4 right" },
	{"P4 Attack"     , BIT_DIGITAL, CpsInp010+4, "p4 fire 1"},
	{"P4 Jump"       , BIT_DIGITAL, CpsInp010+5, "p4 fire 2"},
	{"P4 Use"        , BIT_DIGITAL, CpsInp010+6, "p4 fire 3"},
	{"P4 Select"     , BIT_DIGITAL, CpsInp010+7, "p4 fire 4"},

	{"Reset"         , BIT_DIGITAL, &CpsReset,   "reset"    },
	{"Diagnostic"    , BIT_DIGITAL, CpsInp021+1, "diag"     },
	{"Service"       , BIT_DIGITAL, CpsInp021+2, "service"  },
};

STDINPUTINFO(ddsom)


// Dimahoo
static struct BurnInputInfo dimahooInputList[] =
{
	{"P1 Coin"       , BIT_DIGITAL, CpsInp020+4, "p1 coin"  },
	{"P1 Start"      , BIT_DIGITAL, CpsInp020+0, "p1 start" },
	{"P1 Up"         , BIT_DIGITAL, CpsInp001+3, "p1 up"    },
	{"P1 Down"       , BIT_DIGITAL, CpsInp001+2, "p1 down"  },
	{"P1 Left"       , BIT_DIGITAL, CpsInp001+1, "p1 left"  },
	{"P1 Right"      , BIT_DIGITAL, CpsInp001+0, "p1 right" },
	{"P1 Shot"       , BIT_DIGITAL, CpsInp001+4, "p1 fire 1"},
	{"P1 Bomb"       , BIT_DIGITAL, CpsInp001+5, "p1 fire 2"},
	{"P1 Shot (auto)", BIT_DIGITAL, CpsInp001+6, "p1 fire 3"},

	{"P2 Coin"       , BIT_DIGITAL, CpsInp020+5, "p2 coin"  },
	{"P2 Start"      , BIT_DIGITAL, CpsInp020+1, "p2 start" },
	{"P2 Up"         , BIT_DIGITAL, CpsInp000+3, "p2 up"    },
	{"P2 Down"       , BIT_DIGITAL, CpsInp000+2, "p2 down"  },
	{"P2 Left"       , BIT_DIGITAL, CpsInp000+1, "p2 left"  },
	{"P2 Right"      , BIT_DIGITAL, CpsInp000+0, "p2 right" },
	{"P2 Shot"       , BIT_DIGITAL, CpsInp000+4, "p2 fire 1"},
	{"P2 Bomb"       , BIT_DIGITAL, CpsInp000+5, "p2 fire 2"},
	{"P2 Shot (auto)", BIT_DIGITAL, CpsInp000+6, "p2 fire 3"},

	{"Reset"         , BIT_DIGITAL, &CpsReset  , "reset"    },
	{"Diagnostic"    , BIT_DIGITAL, CpsInp021+1, "diag"     },
	{"Service"       , BIT_DIGITAL, CpsInp021+2, "service"  },
};

STDINPUTINFO(dimahoo)


// Eco Fighters
static struct BurnInputInfo ecofghtrInputList[] =
{
	{"P1 Coin"       , BIT_DIGITAL, CpsInp020+4, "p1 coin"  },
	{"P1 Start"      , BIT_DIGITAL, CpsInp020+0, "p1 start" },
	{"P1 Up"         , BIT_DIGITAL, CpsInp001+3, "p1 up"    },
	{"P1 Down"       , BIT_DIGITAL, CpsInp001+2, "p1 down"  },
	{"P1 Left"       , BIT_DIGITAL, CpsInp001+1, "p1 left"  },
	{"P1 Right"      , BIT_DIGITAL, CpsInp001+0, "p1 right" },
	{"P1 Turn 1"     , BIT_DIGITAL, CpsInp001+4, "p1 fire 1"},
	{"P1 Attack"     , BIT_DIGITAL, CpsInp001+5, "p1 fire 2"},
	{"P1 Turn 2"     , BIT_DIGITAL, CpsInp001+6, "p1 fire 3"},

	{"P2 Coin"       , BIT_DIGITAL, CpsInp020+5, "p2 coin"  },
	{"P2 Start"      , BIT_DIGITAL, CpsInp020+1, "p2 start" },
	{"P2 Up"         , BIT_DIGITAL, CpsInp000+3, "p2 up"    },
	{"P2 Down"       , BIT_DIGITAL, CpsInp000+2, "p2 down"  },
	{"P2 Left"       , BIT_DIGITAL, CpsInp000+1, "p2 left"  },
	{"P2 Right"      , BIT_DIGITAL, CpsInp000+0, "p2 right" },
	{"P2 Turn 1"     , BIT_DIGITAL, CpsInp000+4, "p2 fire 1"},
	{"P2 Attack"     , BIT_DIGITAL, CpsInp000+5, "p2 fire 2"},
	{"P2 Turn 2"     , BIT_DIGITAL, CpsInp000+6, "p2 fire 3"},

	{"Reset"         , BIT_DIGITAL, &CpsReset  , "reset"    },
	{"Diagnostic"    , BIT_DIGITAL, CpsInp021+1, "diag"     },
	{"Service"       , BIT_DIGITAL, CpsInp021+2, "service"  },
};

STDINPUTINFO(ecofghtr)


// Jyangokushi
static struct BurnInputInfo jyangokuInputList[] =
{
	{"P1 Coin"       , BIT_DIGITAL, CpsInp020+4, "p1 coin"},
	{"P1 Start"      , BIT_DIGITAL, CpsInp020+0, "p1 start"},
	{"P1 Up"         , BIT_DIGITAL, CpsInp001+3, "p1 up"},
	{"P1 Down"       , BIT_DIGITAL, CpsInp001+2, "p1 down"},
	{"P1 Left"       , BIT_DIGITAL, CpsInp001+1, "p1 left"},
	{"P1 Right"      , BIT_DIGITAL, CpsInp001+0, "p1 right"},
	{"P1 Shot1"      , BIT_DIGITAL, CpsInp001+4, "p1 fire 1"},
	{"P1 Shot2"      , BIT_DIGITAL, CpsInp001+5, "p1 fire 2"},

	{"Reset"         , BIT_DIGITAL, &CpsReset  , "reset"},
	{"Diagnostic"    , BIT_DIGITAL, CpsInp021+1, "diag"},
	{"Service"       , BIT_DIGITAL, CpsInp021+2, "service"},
};

STDINPUTINFO(jyangoku)


// Megaman 2
static struct BurnInputInfo megamanInputList[] =
{
	{"P1 Coin"       , BIT_DIGITAL, CpsInp020 + 4, "p1 coin"   },
	{"P1 Start"      , BIT_DIGITAL, CpsInp020 + 0, "p1 start"  },
	{"P1 Up"         , BIT_DIGITAL, CpsInp001 + 3, "p1 up"     },
	{"P1 Down"       , BIT_DIGITAL, CpsInp001 + 2, "p1 down"   },
	{"P1 Left"       , BIT_DIGITAL, CpsInp001 + 1, "p1 left"   },
	{"P1 Right"      , BIT_DIGITAL, CpsInp001 + 0, "p1 right"  },
	{"P1 Attack"     , BIT_DIGITAL, CpsInp001 + 4, "p1 fire 1" },
	{"P1 Jump"       , BIT_DIGITAL, CpsInp001 + 5, "p1 fire 2" },
	{"P1 Select"     , BIT_DIGITAL, CpsInp001 + 6, "p1 fire 3" },

	{"P2 Coin"       , BIT_DIGITAL, CpsInp020 + 5, "p2 coin"   },
	{"P2 Start"      , BIT_DIGITAL, CpsInp020 + 1, "p2 start"  },
	{"P2 Up"         , BIT_DIGITAL, CpsInp000 + 3, "p2 up"     },
	{"P2 Down"       , BIT_DIGITAL, CpsInp000 + 2, "p2 down"   },
	{"P2 Left"       , BIT_DIGITAL, CpsInp000 + 1, "p2 left"   },
	{"P2 Right"      , BIT_DIGITAL, CpsInp000 + 0, "p2 right"  },
	{"P2 Attack"     , BIT_DIGITAL, CpsInp000 + 4, "p2 fire 1" },
	{"P2 Jump"       , BIT_DIGITAL, CpsInp000 + 5, "p2 fire 2" },
	{"P2 Select"     , BIT_DIGITAL, CpsInp000 + 6, "p2 fire 3" },

	{"Reset"         , BIT_DIGITAL, &CpsReset    , "reset"     },
	{"Diagnostic"    , BIT_DIGITAL, CpsInp021 + 1, "diag"      },
	{"Service"       , BIT_DIGITAL, CpsInp021 + 2, "service"   },
};

STDINPUTINFO(megaman)


// Mighty Pang!
static struct BurnInputInfo mpangInputList[] =
{
	{"P1 Coin"       , BIT_DIGITAL, CpsInp020+4, "p1 coin"},
	{"P1 Start"      , BIT_DIGITAL, CpsInp020+0, "p1 start"},
	{"P1 Up"         , BIT_DIGITAL, CpsInp001+3, "p1 up"},
	{"P1 Down"       , BIT_DIGITAL, CpsInp001+2, "p1 down"},
	{"P1 Left"       , BIT_DIGITAL, CpsInp001+1, "p1 left"},
	{"P1 Right"      , BIT_DIGITAL, CpsInp001+0, "p1 right"},
	{"P1 Shot1"      , BIT_DIGITAL, CpsInp001+4, "p1 fire 1"},
	{"P1 Shot2"      , BIT_DIGITAL, CpsInp001+5, "p1 fire 2"},

	{"P2 Coin"       , BIT_DIGITAL, CpsInp020+5, "p2 coin"},
	{"P2 Start"      , BIT_DIGITAL, CpsInp020+1, "p2 start"},
	{"P2 Up"         , BIT_DIGITAL, CpsInp000+3, "p2 up"},
	{"P2 Down"       , BIT_DIGITAL, CpsInp000+2, "p2 down"},
	{"P2 Left"       , BIT_DIGITAL, CpsInp000+1, "p2 left"},
	{"P2 Right"      , BIT_DIGITAL, CpsInp000+0, "p2 right"},
	{"P2 Shot1"      , BIT_DIGITAL, CpsInp000+4, "p2 fire 1"},
	{"P2 Shot2"      , BIT_DIGITAL, CpsInp000+5, "p2 fire 2"},

	{"Reset"         , BIT_DIGITAL, &CpsReset  , "reset"},
	{"Diagnostic"    , BIT_DIGITAL, CpsInp021+1, "diag"},
	{"Service"       , BIT_DIGITAL, CpsInp021+2, "service"},
};

STDINPUTINFO(mpang)


// Progear
static struct BurnInputInfo progearInputList[] =
{
	{"P1 Coin"       , BIT_DIGITAL, CpsInp020+4, "p1 coin"},
	{"P1 Start"      , BIT_DIGITAL, CpsInp020+0, "p1 start"},
	{"P1 Up"         , BIT_DIGITAL, CpsInp001+3, "p1 up"},
	{"P1 Down"       , BIT_DIGITAL, CpsInp001+2, "p1 down"},
	{"P1 Left"       , BIT_DIGITAL, CpsInp001+1, "p1 left"},
	{"P1 Right"      , BIT_DIGITAL, CpsInp001+0, "p1 right"},
	{"P1 Shot"       , BIT_DIGITAL, CpsInp001+4, "p1 fire 1"},
	{"P1 Bomb"       , BIT_DIGITAL, CpsInp001+5, "p1 fire 2"},
	{"P1 Auto"       , BIT_DIGITAL, CpsInp001+6, "p1 fire 3"},

	{"P2 Coin"       , BIT_DIGITAL, CpsInp020+5, "p2 coin"},
	{"P2 Start"      , BIT_DIGITAL, CpsInp020+1, "p2 start"},
	{"P2 Up"         , BIT_DIGITAL, CpsInp000+3, "p2 up"},
	{"P2 Down"       , BIT_DIGITAL, CpsInp000+2, "p2 down"},
	{"P2 Left"       , BIT_DIGITAL, CpsInp000+1, "p2 left"},
	{"P2 Right"      , BIT_DIGITAL, CpsInp000+0, "p2 right"},
	{"P2 Shot"       , BIT_DIGITAL, CpsInp000+4, "p2 fire 1"},
	{"P2 Bomb"       , BIT_DIGITAL, CpsInp000+5, "p2 fire 2"},
	{"P2 Auto"       , BIT_DIGITAL, CpsInp000+6, "p2 fire 3"},

	{"Reset"         , BIT_DIGITAL, &CpsReset  , "reset"},
	{"Diagnostic"    , BIT_DIGITAL, CpsInp021+1, "diag"},
	{"Service"       , BIT_DIGITAL, CpsInp021+2, "service"},
};

STDINPUTINFO(progear)

// Puzzle Loop 2
static struct BurnInputInfo pzloop2InputList[] = {
	{"P1 Coin"       , BIT_DIGITAL, CpsInp020+4, "p1 coin"},
	{"P1 Start"      , BIT_DIGITAL, CpsInp020+0, "p1 start"},
	{"P1 Up"         , BIT_DIGITAL, CpsInp001+3, "p1 up"},
	{"P1 Down"       , BIT_DIGITAL, CpsInp001+2, "p1 down"},
	{"P1 Left"       , BIT_DIGITAL, CpsInp001+1, "p1 left"},
	{"P1 Right"      , BIT_DIGITAL, CpsInp001+0, "p1 right"},
	{"P1 Shot"       , BIT_DIGITAL, CpsInp001+4, "p1 fire 1"},

	{"P2 Coin"       , BIT_DIGITAL, CpsInp020+5, "p2 coin"},
	{"P2 Start"      , BIT_DIGITAL, CpsInp020+1, "p2 start"},
	{"P2 Up"         , BIT_DIGITAL, CpsInp000+3, "p2 up"},
	{"P2 Down"       , BIT_DIGITAL, CpsInp000+2, "p2 down"},
	{"P2 Left"       , BIT_DIGITAL, CpsInp000+1, "p2 left"},
	{"P2 Right"      , BIT_DIGITAL, CpsInp000+0, "p2 right"},
	{"P2 Shot"       , BIT_DIGITAL, CpsInp000+4, "p2 fire 1"},

	{"Reset"         , BIT_DIGITAL, &CpsReset  , "reset"},
	{"Diagnostic"    , BIT_DIGITAL, CpsInp021+1, "diag"},
	{"Service"       , BIT_DIGITAL, CpsInp021+2, "service"},
};

STDINPUTINFO(pzloop2)


// Quiz Nanairo Dreams
static struct BurnInputInfo qndreamInputList[] =
{
	{"P1 Coin"       , BIT_DIGITAL, CpsInp020+4, "p1 coin"},
	{"P1 Start"      , BIT_DIGITAL, CpsInp020+0, "p1 start"},
	{"P1 Answer 1"   , BIT_DIGITAL, CpsInp001+4, "p1 fire 1"},
	{"P1 Answer 2"   , BIT_DIGITAL, CpsInp001+5, "p1 fire 2"},
	{"P1 Answer 3"   , BIT_DIGITAL, CpsInp001+6, "p1 fire 3"},
	{"P1 Answer 4"   , BIT_DIGITAL, CpsInp001+7, "p1 fire 4"},

	{"P2 Coin"       , BIT_DIGITAL, CpsInp020+5, "p2 coin"},
	{"P2 Start"      , BIT_DIGITAL, CpsInp020+1, "p2 start"},
	{"P2 Answer 1"   , BIT_DIGITAL, CpsInp000+4, "p2 fire 1"},
	{"P2 Answer 2"   , BIT_DIGITAL, CpsInp000+5, "p2 fire 2"},
	{"P2 Answer 3"   , BIT_DIGITAL, CpsInp000+6, "p2 fire 3"},
	{"P2 Answer 4"   , BIT_DIGITAL, CpsInp000+7, "p2 fire 4"},

	{"Reset"         , BIT_DIGITAL, &CpsReset,   "reset"},
	{"Diagnostic"    , BIT_DIGITAL, CpsInp021+1, "diag"},
	{"Service"       , BIT_DIGITAL, CpsInp021+2, "service"},
};

STDINPUTINFO(qndream)


// Ring of Destruction / slammasters II
static struct BurnInputInfo ringdestInputList[] =
{
	{"P1 Coin"        , BIT_DIGITAL, CpsInp020+4, "p1 coin"},
	{"P1 Start"       , BIT_DIGITAL, CpsInp020+0, "p1 start"},
	{"P1 Up"          , BIT_DIGITAL, CpsInp001+3, "p1 up"},
	{"P1 Down"        , BIT_DIGITAL, CpsInp001+2, "p1 down"},
	{"P1 Left"        , BIT_DIGITAL, CpsInp001+1, "p1 left"},
	{"P1 Right"       , BIT_DIGITAL, CpsInp001+0, "p1 right"},
	{"P1 Hold"        , BIT_DIGITAL, CpsInp001+4, "p1 fire 1"},
	{"P1 Weak punch"  , BIT_DIGITAL, CpsInp001+5, "p1 fire 2"},
	{"P1 Strong punch", BIT_DIGITAL, CpsInp001+6, "p1 fire 3"},
	{"P1 Weak kick"   , BIT_DIGITAL, CpsInp011+1, "p1 fire 5"},
	{"P1 Strong kick" , BIT_DIGITAL, CpsInp011+2, "p1 fire 6"},

	{"P2 Coin"        , BIT_DIGITAL, CpsInp020+5, "p2 coin"},
	{"P2 Start"       , BIT_DIGITAL, CpsInp020+1, "p2 start"},
	{"P2 Up"          , BIT_DIGITAL, CpsInp000+3, "p2 up"},
	{"P2 Down"        , BIT_DIGITAL, CpsInp000+2, "p2 down"},
	{"P2 Left"        , BIT_DIGITAL, CpsInp000+1, "p2 left"},
	{"P2 Right"       , BIT_DIGITAL, CpsInp000+0, "p2 right"},
	{"P2 Hold"        , BIT_DIGITAL, CpsInp000+4, "p2 fire 1"},
	{"P2 Weak punch"  , BIT_DIGITAL, CpsInp000+5, "p2 fire 2"},
	{"P2 Strong punch", BIT_DIGITAL, CpsInp000+6, "p2 fire 3"},
	{"P2 Weak kick"   , BIT_DIGITAL, CpsInp011+5, "p2 fire 5"},
	{"P2 Strong kick" , BIT_DIGITAL, CpsInp020+6, "p2 fire 6"},

	{"Reset"          , BIT_DIGITAL, &CpsReset   , "reset"},
	{"Diagnostic"     , BIT_DIGITAL, CpsInp021+1, "diag"},
	{"Service"        , BIT_DIGITAL, CpsInp021+2, "service"},
};

STDINPUTINFO(ringdest)


// Super Gem Fighter
static struct BurnInputInfo sgemfInputList[] =
{
	{"P1 Coin",		BIT_DIGITAL, CpsInp020+4, "p1 coin"	},
	{"P1 Start",	BIT_DIGITAL, CpsInp020+0, "p1 start"	},
	{"P1 Up",		BIT_DIGITAL, CpsInp001+3, "p1 up"	},
	{"P1 Down",		BIT_DIGITAL, CpsInp001+2, "p1 down"	},
	{"P1 Left",		BIT_DIGITAL, CpsInp001+1, "p1 left"	},
	{"P1 Right",	BIT_DIGITAL, CpsInp001+0, "p1 right"	},
	{"P1 Punch",	BIT_DIGITAL, CpsInp001+4, "p1 fire 1"	},
	{"P1 Kick",		BIT_DIGITAL, CpsInp001+5, "p1 fire 2"	},
	{"P1 Special",	BIT_DIGITAL, CpsInp001+6, "p1 fire 3"	},

	{"P2 Coin",		BIT_DIGITAL, CpsInp020+5, "p2 coin"	},
	{"P2 Start",	BIT_DIGITAL, CpsInp020+1, "p2 start"	},
	{"P2 Up",		BIT_DIGITAL, CpsInp000+3, "p2 up"	},
	{"P2 Down",		BIT_DIGITAL, CpsInp000+2, "p2 down"	},
	{"P2 Left",		BIT_DIGITAL, CpsInp000+1, "p2 left"	},
	{"P2 Right",	BIT_DIGITAL, CpsInp000+0, "p2 right"	},
	{"P2 Punch",	BIT_DIGITAL, CpsInp000+4, "p2 fire 1"	},
	{"P2 Kick",		BIT_DIGITAL, CpsInp000+5, "p2 fire 2"	},
	{"P2 Special",	BIT_DIGITAL, CpsInp000+6, "p2 fire 3"	},

	{"Reset",		BIT_DIGITAL, &CpsReset,   "reset"	},
	{"Diagnostic",	BIT_DIGITAL, CpsInp021+1, "diag"	},
	{"Service",		BIT_DIGITAL, CpsInp021+2, "service"	},
};

STDINPUTINFO(sgemf)


// Super Puzzle Fighter II
struct BurnInputInfo spf2xInputList[] =
{
	{"P1 Coin",			BIT_DIGITAL, CpsInp020+4, "p1 coin"	},
	{"P1 Start",		BIT_DIGITAL, CpsInp020+0, "p1 start"	},
	{"P1 Up",			BIT_DIGITAL, CpsInp001+3, "p1 up"	},
	{"P1 Down",			BIT_DIGITAL, CpsInp001+2, "p1 down"	},
	{"P1 Left" ,		BIT_DIGITAL, CpsInp001+1, "p1 left"	},
	{"P1 Right",		BIT_DIGITAL, CpsInp001+0, "p1 right"	},
	{"P1 Rotate Left" ,	BIT_DIGITAL, CpsInp001+4, "p1 fire 1"	},
	{"P1 Rotate Right",	BIT_DIGITAL, CpsInp001+5, "p1 fire 2"	},

	{"P2 Coin",			BIT_DIGITAL, CpsInp020+5, "p2 coin"	},
	{"P2 Start",		BIT_DIGITAL, CpsInp020+1, "p2 start"	},
	{"P2 Up",			BIT_DIGITAL, CpsInp000+3, "p2 up"	},
	{"P2 Down",			BIT_DIGITAL, CpsInp000+2, "p2 down"	},
	{"P2 Left",			BIT_DIGITAL, CpsInp000+1, "p2 left"	},
	{"P2 Right",		BIT_DIGITAL, CpsInp000+0, "p2 right"	},
	{"P2 Rotate Left",	BIT_DIGITAL, CpsInp000+4, "p2 fire 1"	},
	{"P2 Rotate Right",	BIT_DIGITAL, CpsInp000+5, "p2 fire 2"	},

	{"Reset",			BIT_DIGITAL, &CpsReset,   "reset"	},
	{"Diagnostic",		BIT_DIGITAL, CpsInp021+1, "diag"	},
	{"Service",			BIT_DIGITAL, CpsInp021+2, "service"	},
};

STDINPUTINFO(spf2x)


// Inputs common to all Cps2 Fighter Style games (3 x Punch,3 x Kick)
struct BurnInputInfo DrvInputList[] = {
	{"P1 Coin",			BIT_DIGITAL, CpsInp020+4, "p1 coin"  },	// 0x00
	{"P1 Start",		BIT_DIGITAL, CpsInp020+0, "p1 start" },

	{"P1 Up",			BIT_DIGITAL, CpsInp001+3, "p1 up"    },	// 0x02
	{"P1 Down",			BIT_DIGITAL, CpsInp001+2, "p1 down"  },
	{"P1 Left",			BIT_DIGITAL, CpsInp001+1, "p1 left"  },
	{"P1 Right",		BIT_DIGITAL, CpsInp001+0, "p1 right" },

	{"P1 Weak punch",	BIT_DIGITAL, CpsInp001+4, "p1 fire 1"},	// 0x06
	{"P1 Medium punch",	BIT_DIGITAL, CpsInp001+5, "p1 fire 2"},
	{"P1 Strong punch",	BIT_DIGITAL, CpsInp001+6, "p1 fire 3"},
	{"P1 Weak kick",	BIT_DIGITAL, CpsInp011+0, "p1 fire 4"},
	{"P1 Medium kick",	BIT_DIGITAL, CpsInp011+1, "p1 fire 5"},
	{"P1 Strong kick",	BIT_DIGITAL, CpsInp011+2, "p1 fire 6"},

	{"P2 Coin",			BIT_DIGITAL, CpsInp020+5, "p2 coin"  },	// 0x0C
	{"P2 Start",		BIT_DIGITAL, CpsInp020+1, "p2 start" },

	{"P2 Up",			BIT_DIGITAL, CpsInp000+3, "p2 up"    },	// 0x0E
	{"P2 Down",			BIT_DIGITAL, CpsInp000+2, "p2 down"  },
	{"P2 Left",			BIT_DIGITAL, CpsInp000+1, "p2 left"  },
	{"P2 Right",		BIT_DIGITAL, CpsInp000+0, "p2 right" },

	{"P2 Weak punch",	BIT_DIGITAL, CpsInp000+4, "p2 fire 1"},	// 0x12
	{"P2 Medium punch",	BIT_DIGITAL, CpsInp000+5, "p2 fire 2"},
	{"P2 Strong Punch",	BIT_DIGITAL, CpsInp000+6, "p2 fire 3"},
	{"P2 Weak kick",	BIT_DIGITAL, CpsInp011+4, "p2 fire 4"},
	{"P2 Medium kick",	BIT_DIGITAL, CpsInp011+5, "p2 fire 5"},
	{"P2 Strong kick",	BIT_DIGITAL, CpsInp020+6, "p2 fire 6"},

	{"Reset",			BIT_DIGITAL, &CpsReset  , "reset"    },	// 0x18
	{"Diagnostic",		BIT_DIGITAL, CpsInp021+1, "diag"     },
	{"Service",			BIT_DIGITAL, CpsInp021+2, "service"  },
};

STDINPUTINFO(Drv)


//-----------------------------------------------------------------------------
// FBA Combo - extra players input hack
static unsigned char DummyInp[0x1B - 0x03] = { 0, };

struct BurnInputInfo Drv4pInputList[] = {
	{"P1 Coin",			BIT_DIGITAL, CpsInp020+4,   "p1 coin"  },	// 0x00
	{"P1 Start",		BIT_DIGITAL, CpsInp020+0,   "p1 start" },

	{"P1 Up",			BIT_DIGITAL, CpsInp001+3,   "p1 up"    },	// 0x02
	{"P1 Down",			BIT_DIGITAL, CpsInp001+2,   "p1 down"  },
	{"P1 Left",			BIT_DIGITAL, CpsInp001+1,   "p1 left"  },
	{"P1 Right",		BIT_DIGITAL, CpsInp001+0,   "p1 right" },

	{"P1 Weak punch",	BIT_DIGITAL, CpsInp001+4,   "p1 fire 1"},	// 0x06
	{"P1 Medium punch",	BIT_DIGITAL, CpsInp001+5,   "p1 fire 2"},
	{"P1 Strong punch",	BIT_DIGITAL, CpsInp001+6,   "p1 fire 3"},
	{"P1 Weak kick",	BIT_DIGITAL, CpsInp011+0,   "p1 fire 4"},
	{"P1 Medium kick",	BIT_DIGITAL, CpsInp011+1,   "p1 fire 5"},
	{"P1 Strong kick",	BIT_DIGITAL, CpsInp011+2,   "p1 fire 6"},

	{"P2 Coin",			BIT_DIGITAL, DummyInp+0x00, "p2 coin"  },	// 0x0C
	{"P2 Start",		BIT_DIGITAL, DummyInp+0x01, "p2 start" },

	{"P2 Up",			BIT_DIGITAL, DummyInp+0x02, "p2 up"    },	// 0x0E
	{"P2 Down",			BIT_DIGITAL, DummyInp+0x03, "p2 down"  },
	{"P2 Left",			BIT_DIGITAL, DummyInp+0x04, "p2 left"  },
	{"P2 Right",		BIT_DIGITAL, DummyInp+0x05, "p2 right" },

	{"P2 Weak punch",	BIT_DIGITAL, DummyInp+0x06, "p2 fire 1"},	// 0x12
	{"P2 Medium punch",	BIT_DIGITAL, DummyInp+0x07, "p2 fire 2"},
	{"P2 Strong Punch",	BIT_DIGITAL, DummyInp+0x08, "p2 fire 3"},
	{"P2 Weak kick",	BIT_DIGITAL, DummyInp+0x09, "p2 fire 4"},
	{"P2 Medium kick",	BIT_DIGITAL, DummyInp+0x0A, "p2 fire 5"},
	{"P2 Strong kick",	BIT_DIGITAL, DummyInp+0x0B, "p2 fire 6"},

	{"P3 Coin",			BIT_DIGITAL, CpsInp020+5,   "p3 coin"  },	// 0x18
	{"P3 Start",		BIT_DIGITAL, CpsInp020+1,   "p3 start" },

	{"P3 Up",			BIT_DIGITAL, CpsInp000+3,   "p3 up"    },	// 0x1A
	{"P3 Down",			BIT_DIGITAL, CpsInp000+2,   "p3 down"  },
	{"P3 Left",			BIT_DIGITAL, CpsInp000+1,   "p3 left"  },
	{"P3 Right",		BIT_DIGITAL, CpsInp000+0,   "p3 right" },

	{"P3 Weak punch",	BIT_DIGITAL, CpsInp000+4,   "p3 fire 1"},	// 0x1E
	{"P3 Medium punch",	BIT_DIGITAL, CpsInp000+5,   "p3 fire 2"},
	{"P3 Strong Punch",	BIT_DIGITAL, CpsInp000+6,   "p3 fire 3"},
	{"P3 Weak kick",	BIT_DIGITAL, CpsInp011+4,   "p3 fire 4"},
	{"P3 Medium kick",	BIT_DIGITAL, CpsInp011+5,   "p3 fire 5"},
	{"P3 Strong kick",	BIT_DIGITAL, CpsInp020+6,   "p3 fire 6"},

	{"P4 Coin",			BIT_DIGITAL, DummyInp+0x0C, "p4 coin"  },	// 0x24
	{"P4 Start",		BIT_DIGITAL, DummyInp+0x0D, "p4 start" },

	{"P4 Up",			BIT_DIGITAL, DummyInp+0x0E, "p4 up"    },	// 0x26
	{"P4 Down",			BIT_DIGITAL, DummyInp+0x0F, "p4 down"  },
	{"P4 Left",			BIT_DIGITAL, DummyInp+0x10, "p4 left"  },
	{"P4 Right",		BIT_DIGITAL, DummyInp+0x11, "p4 right" },

	{"P4 Weak punch",	BIT_DIGITAL, DummyInp+0x12, "p4 fire 1"},	// 0x2A
	{"P4 Medium punch",	BIT_DIGITAL, DummyInp+0x13, "p4 fire 2"},
	{"P4 Strong Punch",	BIT_DIGITAL, DummyInp+0x14, "p4 fire 3"},
	{"P4 Weak kick",	BIT_DIGITAL, DummyInp+0x15, "p4 fire 4"},
	{"P4 Medium kick",	BIT_DIGITAL, DummyInp+0x16, "p4 fire 5"},
	{"P4 Strong kick",	BIT_DIGITAL, DummyInp+0x17, "p4 fire 6"},

	{"Reset",			BIT_DIGITAL, &CpsReset  ,   "reset"    },	// 0x30
	{"Diagnostic",		BIT_DIGITAL, CpsInp021+1,   "diag"     },
	{"Service",			BIT_DIGITAL, CpsInp021+2,   "service"  },	// 0x32
};

STDINPUTINFO(Drv4p)


// FBA Combo - extra players input hack
#ifndef SN_TARGET_PS3
static void CpsDrv4pSwap(unsigned char nInputSwap)
{
	unsigned int nOffset1, nOffset2;

	if (nInputSwap & 0x02) {
		for (nOffset1 = 0x00, nOffset2 = 0x0C; nOffset1 < 0x0C; nOffset1++, nOffset2++) {
			*(Drv4pInputList[nOffset1].pVal) = *(Drv4pInputList[nOffset2].pVal);
		}
	}

	if (nInputSwap & 0x08) {
		for (nOffset1 = 0x18, nOffset2 = 0x24; nOffset1 < 0x24; nOffset1++, nOffset2++) {
			*(Drv4pInputList[nOffset1].pVal) = *(Drv4pInputList[nOffset2].pVal);
		}
	}

#ifdef _DEBUG
	{
		static unsigned char nPrevVal = nInputSwap;
		if (nInputSwap != nPrevVal) {
			printf ("input swapped - ");
			if (nInputSwap == 0x00) {
				printf ("p1 controls p1 - p3 controls p2\n");
			} else if (nInputSwap == 0x02) {
				printf ("p2 controls p1 - p3 controls p2\n");
			} else if (nInputSwap == 0x08) {
				printf ("p1 controls p1 - p4 controls p2\n");
			} else {
				printf ("p2 controls p1 - p4 controls p2\n");
			}
			nPrevVal = nInputSwap;
		}
	}
#endif
}
#endif
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
// PhoenixInit
void __fastcall PhoenixOutputWriteByte(unsigned int a, unsigned char d)
{
	if (a >= 0xfffff0 && a <= 0xfffffb) {
		CpsFrg[a & 0x0f] = d;
		return;
	}

	if (a >= 0xff0000 && a <= 0xffffff) {
		CpsRamFF[(a - 0xff0000) ^ 1] = d;
		return;
	}
}

void __fastcall PhoenixSpriteWriteByte(unsigned int a, unsigned char d)
{
//	bprintf(PRINT_NORMAL, _T("Byte %x, %x\n"), a, d);
}

void __fastcall PhoenixSpriteWriteWord(unsigned int a, unsigned short d)
{
	unsigned short *Ram = (unsigned short*)CpsRam708;
	int Offset = (a - 0x700000) >> 1;

	Ram[Offset + 0x0000] = d;
	Ram[Offset + 0x4000] = d;
}

static int PhoenixInit()
{
	int nRet = Cps2Init();

	SekOpen(0);
	SekMapHandler(3, 0xFF0000, 0xFFFFFF, SM_WRITE);
	SekSetWriteByteHandler(3, PhoenixOutputWriteByte);
	SekMapHandler(4, 0x700000, 0x701fff, SM_WRITE);
	SekSetWriteByteHandler(4, PhoenixSpriteWriteByte);
	SekSetWriteWordHandler(4, PhoenixSpriteWriteWord);
	SekClose();

	return nRet;
}


//-----------------------------------------------------------------------------
// Drivers


// 1944: The Loop Master (USA 000620)

static struct BurnRomInfo nffRomDesc[] = {
	{ "nffu.03",      0x080000, 0x9693CF8F, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "nff.04",       0x080000, 0xDBA1C66E, 1 | BRF_ESS | BRF_PRG },
	{ "nffu.05",      0x080000, 0xEA813EB7, 1 | BRF_ESS | BRF_PRG },

	{ "nff.13m",      0x400000, 0xC9FCA741, 3 | BRF_GRA },
	{ "nff.15m",      0x400000, 0xF809D898, 3 | BRF_GRA },
	{ "nff.17m",      0x400000, 0x15BA4507, 3 | BRF_GRA },
	{ "nff.19m",      0x400000, 0x3DD41B8C, 3 | BRF_GRA },
	{ "nff.14m",      0x100000, 0x3FE3A54B, 3 | BRF_GRA },
	{ "nff.16m",      0x100000, 0x565CD231, 3 | BRF_GRA },
	{ "nff.18m",      0x100000, 0x63CA5988, 3 | BRF_GRA },
	{ "nff.20m",      0x100000, 0x21EB8F3B, 3 | BRF_GRA },

	{ "nff.01",       0x020000, 0xD2E44318, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "nff.11m",      0x400000, 0x243E4E05, 5 | BRF_SND },
	{ "nff.12m",      0x400000, 0x4FCF1600, 5 | BRF_SND },
};

STD_ROM_PICK(nff) STD_ROM_FN(nff)

struct BurnDriver BurnDrvCps1944 = {
	"1944", NULL, NULL, "2000",
	"1944: The Loop Master (USA 000620)\0", NULL, "Capcom / 8ing / Raizing", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING, 2, HARDWARE_CAPCOM_CPS2,
	NULL, nffRomInfo, nffRomName, gwingInputInfo, NULL,
	Cps2Init, CpsExit, Cps2Frame, Cps2Redraw, CpsAreaScan,
	&CpsRecalcPal, 384, 224, 4, 3
};


// 1944: The Loop Master (Japan 000620)

static struct BurnRomInfo nffjRomDesc[] = {
	{ "nffj.03",      0x080000, 0x247521EF, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "nff.04",       0x080000, 0xDBA1C66E, 1 | BRF_ESS | BRF_PRG },
	{ "nffj.05",      0x080000, 0x7F20C2EF, 1 | BRF_ESS | BRF_PRG },

	{ "nff.13m",      0x400000, 0xC9FCA741, 3 | BRF_GRA },
	{ "nff.15m",      0x400000, 0xF809D898, 3 | BRF_GRA },
	{ "nff.17m",      0x400000, 0x15BA4507, 3 | BRF_GRA },
	{ "nff.19m",      0x400000, 0x3DD41B8C, 3 | BRF_GRA },
	{ "nff.14m",      0x100000, 0x3FE3A54B, 3 | BRF_GRA },
	{ "nff.16m",      0x100000, 0x565CD231, 3 | BRF_GRA },
	{ "nff.18m",      0x100000, 0x63CA5988, 3 | BRF_GRA },
	{ "nff.20m",      0x100000, 0x21EB8F3B, 3 | BRF_GRA },

	{ "nff.01",       0x020000, 0xD2E44318, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "nff.11m",      0x400000, 0x243E4E05, 5 | BRF_SND },
	{ "nff.12m",      0x400000, 0x4FCF1600, 5 | BRF_SND },
};

STD_ROM_PICK(nffj) STD_ROM_FN(nffj)

struct BurnDriver BurnDrvCps1944j = {
	"1944j", "1944", NULL, "2000",
	"1944: The Loop Master (Japan 000620)\0", NULL, "Capcom / 8ing / Raizing", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE, 2, HARDWARE_CAPCOM_CPS2,
	NULL, nffjRomInfo, nffjRomName, gwingInputInfo, NULL,
	Cps2Init, CpsExit, Cps2Frame, Cps2Redraw, CpsAreaScan,
	&CpsRecalcPal, 384, 224, 4, 3
};


// 1944 - The Loop Master (USA 000620, Phoenix Edition)

static struct BurnRomInfo nffdRomDesc[] = {
	{ "nffud.03",     0x080000, 0x28E8AAE4, 1 | BRF_ESS | BRF_PRG },
	{ "nff.04",       0x080000, 0xDBA1C66E, 1 | BRF_ESS | BRF_PRG },
	{ "nffu.05",      0x080000, 0xEA813EB7, 1 | BRF_ESS | BRF_PRG },

	{ "nff.13m",      0x400000, 0xC9FCA741, 3 | BRF_GRA },
	{ "nff.15m",      0x400000, 0xF809D898, 3 | BRF_GRA },
	{ "nff.17m",      0x400000, 0x15BA4507, 3 | BRF_GRA },
	{ "nff.19m",      0x400000, 0x3DD41B8C, 3 | BRF_GRA },
	{ "nff.14m",      0x100000, 0x3FE3A54B, 3 | BRF_GRA },
	{ "nff.16m",      0x100000, 0x565CD231, 3 | BRF_GRA },
	{ "nff.18m",      0x100000, 0x63CA5988, 3 | BRF_GRA },
	{ "nff.20m",      0x100000, 0x21EB8F3B, 3 | BRF_GRA },

	{ "nff.01",       0x020000, 0xD2E44318, 4 | BRF_ESS | BRF_PRG },

	{ "nff.11m",      0x400000, 0x243E4E05, 5 | BRF_SND },
	{ "nff.12m",      0x400000, 0x4FCF1600, 5 | BRF_SND },
};

STD_ROM_PICK(nffd) STD_ROM_FN(nffd)

struct BurnDriver BurnDrvCps1944d = {
	"1944d", "1944", NULL, "2000",
	"1944 - The Loop Master (USA 000620, Phoenix Edition)\0", NULL, "Capcom / 8ing / Raizing", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE | BDF_BOOTLEG, 2, HARDWARE_CAPCOM_CPS2,
	NULL, nffdRomInfo, nffdRomName, gwingInputInfo, NULL,
	PhoenixInit, CpsExit, Cps2Frame, Cps2Redraw, CpsAreaScan,
	&CpsRecalcPal, 384, 224, 4, 3
};


// 19XX: The War Against Destiny (USA 951207)

static struct BurnRomInfo NinexxRomDesc[] = {
	{ "19xu.03",      0x080000, 0x05955268, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "19xu.04",      0x080000, 0x3111ab7f, 1 | BRF_ESS | BRF_PRG },
	{ "19xu.05",      0x080000, 0x38df4a63, 1 | BRF_ESS | BRF_PRG },
	{ "19xu.06",      0x080000, 0x5c7e60d3, 1 | BRF_ESS | BRF_PRG },
	{ "19x.07",       0x080000, 0x61c0296c, 1 | BRF_ESS | BRF_PRG },

	{ "19x.13m",      0x080000, 0x427aeb18, 3 | BRF_GRA },
	{ "19x.15m",      0x080000, 0x63bdbf54, 3 | BRF_GRA },
	{ "19x.17m",      0x080000, 0x2dfe18b5, 3 | BRF_GRA },
	{ "19x.19m",      0x080000, 0xcbef9579, 3 | BRF_GRA },
	{ "19x.14m",      0x200000, 0xe916967c, 3 | BRF_GRA },
	{ "19x.16m",      0x200000, 0x6e75f3db, 3 | BRF_GRA },
	{ "19x.18m",      0x200000, 0x2213e798, 3 | BRF_GRA },
	{ "19x.20m",      0x200000, 0xab9d5b96, 3 | BRF_GRA },

	{ "19x.01",       0x020000, 0xef55195e, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "19x.11m",      0x200000, 0xd38beef3, 5 | BRF_SND },
	{ "19x.12m",      0x200000, 0xd47c96e2, 5 | BRF_SND },
};

STD_ROM_PICK(Ninexx) STD_ROM_FN(Ninexx)

struct BurnDriver BurnDrvCps19xx = {
	"19xx", NULL, NULL, "1995",
	"19XX: The War Against Destiny (USA 951207)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_ORIENTATION_VERTICAL, 2, HARDWARE_CAPCOM_CPS2,
	NULL, NinexxRomInfo, NinexxRomName, gwingInputInfo, NULL,
	Cps2Init,CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,224,384,3,4
};


// 19XX: The War Against Destiny (Japan 951225)

static struct BurnRomInfo NinexxjRomDesc[] = {
	{ "19xj.03a",     0x080000, 0xed08bdd1, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "19xj.04a",     0x080000, 0xfb8e3f29, 1 | BRF_ESS | BRF_PRG },
	{ "19xj.05a",     0x080000, 0xaa508ac4, 1 | BRF_ESS | BRF_PRG },
	{ "19xj.06a",     0x080000, 0xff2d785b, 1 | BRF_ESS | BRF_PRG },
	{ "19x.07",       0x080000, 0x61c0296c, 1 | BRF_ESS | BRF_PRG },

	{ "19x.13m",      0x080000, 0x427aeb18, 3 | BRF_GRA },
	{ "19x.15m",      0x080000, 0x63bdbf54, 3 | BRF_GRA },
	{ "19x.17m",      0x080000, 0x2dfe18b5, 3 | BRF_GRA },
	{ "19x.19m",      0x080000, 0xcbef9579, 3 | BRF_GRA },
	{ "19x.14m",      0x200000, 0xe916967c, 3 | BRF_GRA },
	{ "19x.16m",      0x200000, 0x6e75f3db, 3 | BRF_GRA },
	{ "19x.18m",      0x200000, 0x2213e798, 3 | BRF_GRA },
	{ "19x.20m",      0x200000, 0xab9d5b96, 3 | BRF_GRA },

	{ "19x.01",       0x020000, 0xef55195e, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "19x.11m",      0x200000, 0xd38beef3, 5 | BRF_SND },
	{ "19x.12m",      0x200000, 0xd47c96e2, 5 | BRF_SND },
};

STD_ROM_PICK(Ninexxj) STD_ROM_FN(Ninexxj)

struct BurnDriver BurnDrvCps19xxj = {
	"19xxj", "19xx", NULL, "1995",
	"19XX: The War Against Destiny (Japan 951225)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE | BDF_ORIENTATION_VERTICAL, 2, HARDWARE_CAPCOM_CPS2,
	NULL, NinexxjRomInfo, NinexxjRomName, gwingInputInfo, NULL,
	Cps2Init,CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,224,384,3,4
};


// 19XX: The War Against Destiny (Japan 951207)

static struct BurnRomInfo Ninexxjr1RomDesc[] = {
	{ "19xj.03",      0x080000, 0x26a381ed, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "19xj.04",      0x080000, 0x30100cca, 1 | BRF_ESS | BRF_PRG },
	{ "19xj.05",      0x080000, 0xde67e938, 1 | BRF_ESS | BRF_PRG },
	{ "19xj.06",      0x080000, 0x39f9a409, 1 | BRF_ESS | BRF_PRG },
	{ "19x.07",       0x080000, 0x61c0296c, 1 | BRF_ESS | BRF_PRG },

	{ "19x.13m",      0x080000, 0x427aeb18, 3 | BRF_GRA },
	{ "19x.15m",      0x080000, 0x63bdbf54, 3 | BRF_GRA },
	{ "19x.17m",      0x080000, 0x2dfe18b5, 3 | BRF_GRA },
	{ "19x.19m",      0x080000, 0xcbef9579, 3 | BRF_GRA },
	{ "19x.14m",      0x200000, 0xe916967c, 3 | BRF_GRA },
	{ "19x.16m",      0x200000, 0x6e75f3db, 3 | BRF_GRA },
	{ "19x.18m",      0x200000, 0x2213e798, 3 | BRF_GRA },
	{ "19x.20m",      0x200000, 0xab9d5b96, 3 | BRF_GRA },

	{ "19x.01",       0x020000, 0xef55195e, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "19x.11m",      0x200000, 0xd38beef3, 5 | BRF_SND },
	{ "19x.12m",      0x200000, 0xd47c96e2, 5 | BRF_SND },
};

STD_ROM_PICK(Ninexxjr1) STD_ROM_FN(Ninexxjr1)

struct BurnDriver BurnDrvCps19xxjr1 = {
	"19xxjr1", "19xx", NULL, "1995",
	"19XX: The War Against Destiny (Japan 951207)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE | BDF_ORIENTATION_VERTICAL, 2, HARDWARE_CAPCOM_CPS2,
	NULL, Ninexxjr1RomInfo, Ninexxjr1RomName, gwingInputInfo, NULL,
	Cps2Init,CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,224,384,3,4
};


// 19XX: The War Against Destiny (Asia 951207)

static struct BurnRomInfo NinexxaRomDesc[] = {
	{ "19xa.03",      0x080000, 0x0c20fd50, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "19xa.04",      0x080000, 0x1fc37508, 1 | BRF_ESS | BRF_PRG },
	{ "19xa.05",      0x080000, 0x6c9cc4ed, 1 | BRF_ESS | BRF_PRG },
	{ "19xa.06",      0x080000, 0xca5b9f76, 1 | BRF_ESS | BRF_PRG },
	{ "19x.07",       0x080000, 0x61c0296c, 1 | BRF_ESS | BRF_PRG },

	{ "19x.13m",      0x080000, 0x427aeb18, 3 | BRF_GRA },
	{ "19x.15m",      0x080000, 0x63bdbf54, 3 | BRF_GRA },
	{ "19x.17m",      0x080000, 0x2dfe18b5, 3 | BRF_GRA },
	{ "19x.19m",      0x080000, 0xcbef9579, 3 | BRF_GRA },
	{ "19x.14m",      0x200000, 0xe916967c, 3 | BRF_GRA },
	{ "19x.16m",      0x200000, 0x6e75f3db, 3 | BRF_GRA },
	{ "19x.18m",      0x200000, 0x2213e798, 3 | BRF_GRA },
	{ "19x.20m",      0x200000, 0xab9d5b96, 3 | BRF_GRA },

	{ "19x.01",       0x020000, 0xef55195e, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "19x.11m",      0x200000, 0xd38beef3, 5 | BRF_SND },
	{ "19x.12m",      0x200000, 0xd47c96e2, 5 | BRF_SND },
};

STD_ROM_PICK(Ninexxa) STD_ROM_FN(Ninexxa)

struct BurnDriver BurnDrvCps19xxa = {
	"19xxa", "19xx", NULL, "1995",
	"19XX: The War Against Destiny (Asia 951207)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE | BDF_ORIENTATION_VERTICAL, 2, HARDWARE_CAPCOM_CPS2,
	NULL, NinexxaRomInfo, NinexxaRomName, gwingInputInfo, NULL,
	Cps2Init,CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,224,384,3,4
};


// 19XX: The War Against Destiny (Hispanic 951218)

static struct BurnRomInfo NinexxhRomDesc[] = {
	{ "19xh.03a",     0x080000, 0x357be2ac, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "19xh.04a",     0x080000, 0xbb13ea3b, 1 | BRF_ESS | BRF_PRG },
	{ "19xh.05a",     0x080000, 0xcbd76601, 1 | BRF_ESS | BRF_PRG },
	{ "19xh.06a",     0x080000, 0xb362de8b, 1 | BRF_ESS | BRF_PRG },
	{ "19x.07",       0x080000, 0x61c0296c, 1 | BRF_ESS | BRF_PRG },

	{ "19x.13m",      0x080000, 0x427aeb18, 3 | BRF_GRA },
	{ "19x.15m",      0x080000, 0x63bdbf54, 3 | BRF_GRA },
	{ "19x.17m",      0x080000, 0x2dfe18b5, 3 | BRF_GRA },
	{ "19x.19m",      0x080000, 0xcbef9579, 3 | BRF_GRA },
	{ "19x.14m",      0x200000, 0xe916967c, 3 | BRF_GRA },
	{ "19x.16m",      0x200000, 0x6e75f3db, 3 | BRF_GRA },
	{ "19x.18m",      0x200000, 0x2213e798, 3 | BRF_GRA },
	{ "19x.20m",      0x200000, 0xab9d5b96, 3 | BRF_GRA },

	{ "19x.01",       0x020000, 0xef55195e, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "19x.11m",      0x200000, 0xd38beef3, 5 | BRF_SND },
	{ "19x.12m",      0x200000, 0xd47c96e2, 5 | BRF_SND },
};

STD_ROM_PICK(Ninexxh) STD_ROM_FN(Ninexxh)

struct BurnDriver BurnDrvCps19xxh = {
	"19xxh", "19xx", NULL, "1995",
	"19XX: The War Against Destiny (Hispanic 951218)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE | BDF_ORIENTATION_VERTICAL, 2, HARDWARE_CAPCOM_CPS2,
	NULL, NinexxhRomInfo, NinexxhRomName, gwingInputInfo, NULL,
	Cps2Init,CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,224,384,3,4
};


// 19XX: The War Against Destiny (Brazil 951218)

static struct BurnRomInfo NinexxbRomDesc[] = {
	{ "19xb.03a",     0x080000, 0x341bdf4a, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "19xb.04a",     0x080000, 0xdff8069e, 1 | BRF_ESS | BRF_PRG },
	{ "19xb.05a",     0x080000, 0xa47a92a8, 1 | BRF_ESS | BRF_PRG },
	{ "19xb.06a",     0x080000, 0xc52df10d, 1 | BRF_ESS | BRF_PRG },
	{ "19x.07",       0x080000, 0x61c0296c, 1 | BRF_ESS | BRF_PRG },

	{ "19x.13m",      0x080000, 0x427aeb18, 3 | BRF_GRA },
	{ "19x.15m",      0x080000, 0x63bdbf54, 3 | BRF_GRA },
	{ "19x.17m",      0x080000, 0x2dfe18b5, 3 | BRF_GRA },
	{ "19x.19m",      0x080000, 0xcbef9579, 3 | BRF_GRA },
	{ "19x.14m",      0x200000, 0xe916967c, 3 | BRF_GRA },
	{ "19x.16m",      0x200000, 0x6e75f3db, 3 | BRF_GRA },
	{ "19x.18m",      0x200000, 0x2213e798, 3 | BRF_GRA },
	{ "19x.20m",      0x200000, 0xab9d5b96, 3 | BRF_GRA },

	{ "19x.01",       0x020000, 0xef55195e, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "19x.11m",      0x200000, 0xd38beef3, 5 | BRF_SND },
	{ "19x.12m",      0x200000, 0xd47c96e2, 5 | BRF_SND },
};

STD_ROM_PICK(Ninexxb) STD_ROM_FN(Ninexxb)

struct BurnDriver BurnDrvCps19xxb = {
	"19xxb", "19xx", NULL, "1995",
	"19XX: The War Against Destiny (Brazil 951218)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE | BDF_ORIENTATION_VERTICAL, 2, HARDWARE_CAPCOM_CPS2,
	NULL, NinexxbRomInfo, NinexxbRomName, gwingInputInfo, NULL,
	Cps2Init,CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,224,384,3,4
};


// 19XX: The War Against Destiny (USA 951207, Phoenix Edition)

static struct BurnRomInfo NinexxdRomDesc[] = {
	{ "19xud.03",      0x80000, 0xf81b60e5, 1 | BRF_ESS | BRF_PRG },
	{ "19xud.04",      0x80000, 0xcc44638c, 1 | BRF_ESS | BRF_PRG },
	{ "19xud.05",      0x80000, 0x33a168de, 1 | BRF_ESS | BRF_PRG },
	{ "19xud.06",      0x80000, 0xe0111282, 1 | BRF_ESS | BRF_PRG },
	{ "19x.07",        0x80000, 0x61c0296c, 1 | BRF_ESS | BRF_PRG },

	{ "19x.13m",      0x080000, 0x427aeb18, 3 | BRF_GRA },
	{ "19x.15m",      0x080000, 0x63bdbf54, 3 | BRF_GRA },
	{ "19x.17m",      0x080000, 0x2dfe18b5, 3 | BRF_GRA },
	{ "19x.19m",      0x080000, 0xcbef9579, 3 | BRF_GRA },
	{ "19x.14m",      0x200000, 0xe916967c, 3 | BRF_GRA },
	{ "19x.16m",      0x200000, 0x6e75f3db, 3 | BRF_GRA },
	{ "19x.18m",      0x200000, 0x2213e798, 3 | BRF_GRA },
	{ "19x.20m",      0x200000, 0xab9d5b96, 3 | BRF_GRA },

	{ "19x.01",       0x020000, 0xef55195e, 4 | BRF_ESS | BRF_PRG },

	{ "19x.11m",      0x200000, 0xd38beef3, 5 | BRF_SND },
	{ "19x.12m",      0x200000, 0xd47c96e2, 5 | BRF_SND },
};

STD_ROM_PICK(Ninexxd) STD_ROM_FN(Ninexxd)

struct BurnDriver BurnDrvCps19xxd = {
	"19xxd", "19xx", NULL, "1995",
	"19XX: The War Against Destiny (USA 951207, Phoenix Edition)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE | BDF_ORIENTATION_VERTICAL | BDF_BOOTLEG, 1, HARDWARE_CAPCOM_CPS2,
	NULL, NinexxdRomInfo, NinexxdRomName, gwingInputInfo, NULL,
	PhoenixInit,CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,224,384,3,4
};


// Armored Warriors (Euro 941024)

static struct BurnRomInfo ArmwarRomDesc[] = {
	{ "pwge.03c",     0x080000, 0x31f74931, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "pwge.04c",     0x080000, 0x16f34f5f, 1 | BRF_ESS | BRF_PRG },
	{ "pwge.05b",     0x080000, 0x4403ed08, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.06",       0x080000, 0x87a60ce8, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.07",       0x080000, 0xf7b148df, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.08",       0x080000, 0xcc62823e, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.09a",      0x080000, 0x4c26baee, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.10",       0x080000, 0x07c4fb28, 1 | BRF_ESS | BRF_PRG },

	{ "pwg.13m",      0x400000, 0xae8fe08e, 3 | BRF_GRA },
	{ "pwg.15m",      0x400000, 0xdb560f58, 3 | BRF_GRA },
	{ "pwg.17m",      0x400000, 0xbc475b94, 3 | BRF_GRA },
	{ "pwg.19m",      0x400000, 0x07439ff7, 3 | BRF_GRA },
	{ "pwg.14m",      0x100000, 0xc3f9ba63, 3 | BRF_GRA },
	{ "pwg.16m",      0x100000, 0x815b0e7b, 3 | BRF_GRA },
	{ "pwg.18m",      0x100000, 0x0109c71b, 3 | BRF_GRA },
	{ "pwg.20m",      0x100000, 0xeb75ffbe, 3 | BRF_GRA },

	{ "pwg.01",       0x020000, 0x18a5c0e4, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "pwg.02",       0x020000, 0xc9dfffa6, 4 | BRF_ESS | BRF_PRG },

	{ "pwg.11m",      0x200000, 0xa78f7433, 5 | BRF_SND },
	{ "pwg.12m",      0x200000, 0x77438ed0, 5 | BRF_SND },
};

STD_ROM_PICK(Armwar) STD_ROM_FN(Armwar)

struct BurnDriver BurnDrvCpsArmwar = {
	"armwar", NULL, NULL, "1994",
	"Armored Warriors (Euro 941024)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING,3,HARDWARE_CAPCOM_CPS2,
	NULL, ArmwarRomInfo, ArmwarRomName, armwarInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Armored Warriors (Euro 941011)

static struct BurnRomInfo Armwarr1RomDesc[] = {
	{ "pwge.03b",     0x080000, 0xe822e3e9, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "pwge.04b",     0x080000, 0x4f89de39, 1 | BRF_ESS | BRF_PRG },
	{ "pwge.05a",     0x080000, 0x83df24e5, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.06",       0x080000, 0x87a60ce8, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.07",       0x080000, 0xf7b148df, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.08",       0x080000, 0xcc62823e, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.09",       0x080000, 0xddc85ca6, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.10",       0x080000, 0x07c4fb28, 1 | BRF_ESS | BRF_PRG },

	{ "pwg.13m",      0x400000, 0xae8fe08e, 3 | BRF_GRA },
	{ "pwg.15m",      0x400000, 0xdb560f58, 3 | BRF_GRA },
	{ "pwg.17m",      0x400000, 0xbc475b94, 3 | BRF_GRA },
	{ "pwg.19m",      0x400000, 0x07439ff7, 3 | BRF_GRA },
	{ "pwg.14m",      0x100000, 0xc3f9ba63, 3 | BRF_GRA },
	{ "pwg.16m",      0x100000, 0x815b0e7b, 3 | BRF_GRA },
	{ "pwg.18m",      0x100000, 0x0109c71b, 3 | BRF_GRA },
	{ "pwg.20m",      0x100000, 0xeb75ffbe, 3 | BRF_GRA },

	{ "pwg.01",       0x020000, 0x18a5c0e4, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "pwg.02",       0x020000, 0xc9dfffa6, 4 | BRF_ESS | BRF_PRG },

	{ "pwg.11m",      0x200000, 0xa78f7433, 5 | BRF_SND },
	{ "pwg.12m",      0x200000, 0x77438ed0, 5 | BRF_SND },
};

STD_ROM_PICK(Armwarr1) STD_ROM_FN(Armwarr1)

struct BurnDriver BurnDrvCpsArmwarr1 = {
	"armwarr1", "armwar", NULL, "1994",
	"Armored Warriors (Euro 941011)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,3,HARDWARE_CAPCOM_CPS2,
	NULL, Armwarr1RomInfo, Armwarr1RomName, armwarInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Armored Warriors (Euro 941011, Phoenix Edition)

static struct BurnRomInfo Armwar1dRomDesc[] = {
	{ "pwged.03b",    0x080000, 0x496bd483, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "pwged.04b",    0x080000, 0x9bd6a38f, 1 | BRF_ESS | BRF_PRG },
	{ "pwged.05a",    0x080000, 0x4c11d30f, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.06",       0x080000, 0x87a60ce8, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.07",       0x080000, 0xf7b148df, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.08",       0x080000, 0xcc62823e, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.09",       0x080000, 0xddc85ca6, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.10",       0x080000, 0x07c4fb28, 1 | BRF_ESS | BRF_PRG },

	{ "pwg.13m",      0x400000, 0xae8fe08e, 3 | BRF_GRA },
	{ "pwg.15m",      0x400000, 0xdb560f58, 3 | BRF_GRA },
	{ "pwg.17m",      0x400000, 0xbc475b94, 3 | BRF_GRA },
	{ "pwg.19m",      0x400000, 0x07439ff7, 3 | BRF_GRA },
	{ "pwg.14m",      0x100000, 0xc3f9ba63, 3 | BRF_GRA },
	{ "pwg.16m",      0x100000, 0x815b0e7b, 3 | BRF_GRA },
	{ "pwg.18m",      0x100000, 0x0109c71b, 3 | BRF_GRA },
	{ "pwg.20m",      0x100000, 0xeb75ffbe, 3 | BRF_GRA },

	{ "pwg.01",       0x020000, 0x18a5c0e4, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "pwg.02",       0x020000, 0xc9dfffa6, 4 | BRF_ESS | BRF_PRG },

	{ "pwg.11m",      0x200000, 0xa78f7433, 5 | BRF_SND },
	{ "pwg.12m",      0x200000, 0x77438ed0, 5 | BRF_SND },
};

STD_ROM_PICK(Armwar1d) STD_ROM_FN(Armwar1d)

struct BurnDriver BurnDrvCpsArmwar1d = {
	"armwar1d", "armwar", NULL, "1994",
	"Armored Warriors (Euro 941011, Phoenix Edition)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE | BDF_BOOTLEG,3,HARDWARE_CAPCOM_CPS2,
	NULL, Armwar1dRomInfo, Armwar1dRomName, armwarInputInfo, NULL,
	PhoenixInit, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Armored Warriors (USA 941024)

static struct BurnRomInfo ArmwaruRomDesc[] = {
	{ "pwgu.03b",     0x080000, 0x8b95497a, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "pwgu.04b",     0x080000, 0x29eb5661, 1 | BRF_ESS | BRF_PRG },
	{ "pwgu.05b",     0x080000, 0xa54e9e44, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.06",       0x080000, 0x87a60ce8, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.07",       0x080000, 0xf7b148df, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.08",       0x080000, 0xcc62823e, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.09a",      0x080000, 0x4c26baee, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.10",       0x080000, 0x07c4fb28, 1 | BRF_ESS | BRF_PRG },

	{ "pwg.13m",      0x400000, 0xae8fe08e, 3 | BRF_GRA },
	{ "pwg.15m",      0x400000, 0xdb560f58, 3 | BRF_GRA },
	{ "pwg.17m",      0x400000, 0xbc475b94, 3 | BRF_GRA },
	{ "pwg.19m",      0x400000, 0x07439ff7, 3 | BRF_GRA },
	{ "pwg.14m",      0x100000, 0xc3f9ba63, 3 | BRF_GRA },
	{ "pwg.16m",      0x100000, 0x815b0e7b, 3 | BRF_GRA },
	{ "pwg.18m",      0x100000, 0x0109c71b, 3 | BRF_GRA },
	{ "pwg.20m",      0x100000, 0xeb75ffbe, 3 | BRF_GRA },

	{ "pwg.01",       0x020000, 0x18a5c0e4, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "pwg.02",       0x020000, 0xc9dfffa6, 4 | BRF_ESS | BRF_PRG },

	{ "pwg.11m",      0x200000, 0xa78f7433, 5 | BRF_SND },
	{ "pwg.12m",      0x200000, 0x77438ed0, 5 | BRF_SND },
};

STD_ROM_PICK(Armwaru) STD_ROM_FN(Armwaru)

struct BurnDriver BurnDrvCpsArmwaru = {
	"armwaru", "armwar", NULL, "1994",
	"Armored Warriors (USA 941024)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,3,HARDWARE_CAPCOM_CPS2,
	NULL, ArmwaruRomInfo, ArmwaruRomName, armwarInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Armored Warriors (Euro 940920)

static struct BurnRomInfo Armwaru1RomDesc[] = {
	{ "pwgu.03a",     0x080000, 0x73d397b1, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "pwgu.04a",     0x080000, 0x1f1de215, 1 | BRF_ESS | BRF_PRG },
	{ "pwgu.05a",     0x080000, 0x835fbe73, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.06",       0x080000, 0x87a60ce8, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.07",       0x080000, 0xf7b148df, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.08",       0x080000, 0xcc62823e, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.09",       0x080000, 0xddc85ca6, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.10",       0x080000, 0x07c4fb28, 1 | BRF_ESS | BRF_PRG },

	{ "pwg.13m",      0x400000, 0xae8fe08e, 3 | BRF_GRA },
	{ "pwg.15m",      0x400000, 0xdb560f58, 3 | BRF_GRA },
	{ "pwg.17m",      0x400000, 0xbc475b94, 3 | BRF_GRA },
	{ "pwg.19m",      0x400000, 0x07439ff7, 3 | BRF_GRA },
	{ "pwg.14m",      0x100000, 0xc3f9ba63, 3 | BRF_GRA },
	{ "pwg.16m",      0x100000, 0x815b0e7b, 3 | BRF_GRA },
	{ "pwg.18m",      0x100000, 0x0109c71b, 3 | BRF_GRA },
	{ "pwg.20m",      0x100000, 0xeb75ffbe, 3 | BRF_GRA },

	{ "pwg.01",       0x020000, 0x18a5c0e4, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "pwg.02",       0x020000, 0xc9dfffa6, 4 | BRF_ESS | BRF_PRG },

	{ "pwg.11m",      0x200000, 0xa78f7433, 5 | BRF_SND },
	{ "pwg.12m",      0x200000, 0x77438ed0, 5 | BRF_SND },
};

STD_ROM_PICK(Armwaru1) STD_ROM_FN(Armwaru1)

struct BurnDriver BurnDrvCpsArmwaru1 = {
	"armwaru1", "armwar", NULL, "1994",
	"Armored Warriors (Euro 940920)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,3,HARDWARE_CAPCOM_CPS2,
	NULL, Armwaru1RomInfo, Armwaru1RomName, armwarInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Powered Gear: Strategic Variant Armor Equipment (Japan 941024)

static struct BurnRomInfo PgearRomDesc[] = {
	{ "pwgj.03a",     0x080000, 0xc79c0c02, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "pwgj.04a",     0x080000, 0x167c6ed8, 1 | BRF_ESS | BRF_PRG },
	{ "pwgj.05a",     0x080000, 0xa63fb400, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.06",       0x080000, 0x87a60ce8, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.07",       0x080000, 0xf7b148df, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.08",       0x080000, 0xcc62823e, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.09a",      0x080000, 0x4c26baee, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.10",       0x080000, 0x07c4fb28, 1 | BRF_ESS | BRF_PRG },

	{ "pwg.13m",      0x400000, 0xae8fe08e, 3 | BRF_GRA },
	{ "pwg.15m",      0x400000, 0xdb560f58, 3 | BRF_GRA },
	{ "pwg.17m",      0x400000, 0xbc475b94, 3 | BRF_GRA },
	{ "pwg.19m",      0x400000, 0x07439ff7, 3 | BRF_GRA },
	{ "pwg.14m",      0x100000, 0xc3f9ba63, 3 | BRF_GRA },
	{ "pwg.16m",      0x100000, 0x815b0e7b, 3 | BRF_GRA },
	{ "pwg.18m",      0x100000, 0x0109c71b, 3 | BRF_GRA },
	{ "pwg.20m",      0x100000, 0xeb75ffbe, 3 | BRF_GRA },

	{ "pwg.01",       0x020000, 0x18a5c0e4, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "pwg.02",       0x020000, 0xc9dfffa6, 4 | BRF_ESS | BRF_PRG },

	{ "pwg.11m",      0x200000, 0xa78f7433, 5 | BRF_SND },
	{ "pwg.12m",      0x200000, 0x77438ed0, 5 | BRF_SND },
};

STD_ROM_PICK(Pgear) STD_ROM_FN(Pgear)

struct BurnDriver BurnDrvCpsPgear = {
	"pgear", "armwar", NULL, "1994",
	"Powered Gear: Strategic Variant Armor Equipment (Japan 941024)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,3,HARDWARE_CAPCOM_CPS2,
	NULL, PgearRomInfo, PgearRomName, armwarInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Powered Gear: Strategic Variant Armor Equipment (Japan 940916)

static struct BurnRomInfo Pgearr1RomDesc[] = {
	{ "pwgj.03",      0x080000, 0xf264e74b, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "pwgj.04",      0x080000, 0x23a84983, 1 | BRF_ESS | BRF_PRG },
	{ "pwgj.05",      0x080000, 0xbef58c62, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.06",       0x080000, 0x87a60ce8, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.07",       0x080000, 0xf7b148df, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.08",       0x080000, 0xcc62823e, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.09",       0x080000, 0xddc85ca6, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.10",       0x080000, 0x07c4fb28, 1 | BRF_ESS | BRF_PRG },

	{ "pwg.13m",      0x400000, 0xae8fe08e, 3 | BRF_GRA },
	{ "pwg.15m",      0x400000, 0xdb560f58, 3 | BRF_GRA },
	{ "pwg.17m",      0x400000, 0xbc475b94, 3 | BRF_GRA },
	{ "pwg.19m",      0x400000, 0x07439ff7, 3 | BRF_GRA },
	{ "pwg.14m",      0x100000, 0xc3f9ba63, 3 | BRF_GRA },
	{ "pwg.16m",      0x100000, 0x815b0e7b, 3 | BRF_GRA },
	{ "pwg.18m",      0x100000, 0x0109c71b, 3 | BRF_GRA },
	{ "pwg.20m",      0x100000, 0xeb75ffbe, 3 | BRF_GRA },

	{ "pwg.01",       0x020000, 0x18a5c0e4, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "pwg.02",       0x020000, 0xc9dfffa6, 4 | BRF_ESS | BRF_PRG },

	{ "pwg.11m",      0x200000, 0xa78f7433, 5 | BRF_SND },
	{ "pwg.12m",      0x200000, 0x77438ed0, 5 | BRF_SND },
};

STD_ROM_PICK(Pgearr1) STD_ROM_FN(Pgearr1)

struct BurnDriver BurnDrvCpsPgearr1 = {
	"pgearr1", "armwar", NULL, "1994",
	"Powered Gear: Strategic Variant Armor Equipment (Japan 940916)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,3,HARDWARE_CAPCOM_CPS2,
	NULL, Pgearr1RomInfo, Pgearr1RomName, armwarInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Armored Warriors (Asia 940920)

static struct BurnRomInfo ArmwaraRomDesc[] = {
	{ "pwga.03a",     0x080000, 0x8d474ab1, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "pwga.04a",     0x080000, 0x81b5aec7, 1 | BRF_ESS | BRF_PRG },
	{ "pwga.05a",     0x080000, 0x2618e819, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.06",       0x080000, 0x87a60ce8, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.07",       0x080000, 0xf7b148df, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.08",       0x080000, 0xcc62823e, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.09",       0x080000, 0xddc85ca6, 1 | BRF_ESS | BRF_PRG },
	{ "pwg.10",       0x080000, 0x07c4fb28, 1 | BRF_ESS | BRF_PRG },

	{ "pwg.13m",      0x400000, 0xae8fe08e, 3 | BRF_GRA },
	{ "pwg.15m",      0x400000, 0xdb560f58, 3 | BRF_GRA },
	{ "pwg.17m",      0x400000, 0xbc475b94, 3 | BRF_GRA },
	{ "pwg.19m",      0x400000, 0x07439ff7, 3 | BRF_GRA },
	{ "pwg.14m",      0x100000, 0xc3f9ba63, 3 | BRF_GRA },
	{ "pwg.16m",      0x100000, 0x815b0e7b, 3 | BRF_GRA },
	{ "pwg.18m",      0x100000, 0x0109c71b, 3 | BRF_GRA },
	{ "pwg.20m",      0x100000, 0xeb75ffbe, 3 | BRF_GRA },

	{ "pwg.01",       0x020000, 0x18a5c0e4, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "pwg.02",       0x020000, 0xc9dfffa6, 4 | BRF_ESS | BRF_PRG },

	{ "pwg.11m",      0x200000, 0xa78f7433, 5 | BRF_SND },
	{ "pwg.12m",      0x200000, 0x77438ed0, 5 | BRF_SND },
};

STD_ROM_PICK(Armwara) STD_ROM_FN(Armwara)

struct BurnDriver BurnDrvCpsArmwara = {
	"armwara", "armwar", NULL, "1994",
	"Armored Warriors (Asia 940920)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,3,HARDWARE_CAPCOM_CPS2,
	NULL, ArmwaraRomInfo, ArmwaraRomName, armwarInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Alien vs Predator (Euro 940520)

static struct BurnRomInfo AvspRomDesc[] = {
	{ "avpe.03d",     0x080000, 0x774334a9, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "avpe.04d",     0x080000, 0x7fa83769, 1 | BRF_ESS | BRF_PRG },
	{ "avp.05d",      0x080000, 0xfbfb5d7a, 1 | BRF_ESS | BRF_PRG },
	{ "avp.06",       0x080000, 0x190b817f, 1 | BRF_ESS | BRF_PRG },

	{ "avp.13m",      0x200000, 0x8f8b5ae4, 3 | BRF_GRA },
	{ "avp.15m",      0x200000, 0xb00280df, 3 | BRF_GRA },
	{ "avp.17m",      0x200000, 0x94403195, 3 | BRF_GRA },
	{ "avp.19m",      0x200000, 0xe1981245, 3 | BRF_GRA },
	{ "avp.14m",      0x200000, 0xebba093e, 3 | BRF_GRA },
	{ "avp.16m",      0x200000, 0xfb228297, 3 | BRF_GRA },
	{ "avp.18m",      0x200000, 0x34fb7232, 3 | BRF_GRA },
	{ "avp.20m",      0x200000, 0xf90baa21, 3 | BRF_GRA },

	{ "avp.01",       0x020000, 0x2d3b4220, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "avp.11m",      0x200000, 0x83499817, 5 | BRF_SND },
	{ "avp.12m",      0x200000, 0xf4110d49, 5 | BRF_SND },
};

STD_ROM_PICK(Avsp) STD_ROM_FN(Avsp)

struct BurnDriver BurnDrvCpsAvsp = {
	"avsp", NULL, NULL, "1994",
	"Alien vs Predator (Euro 940520)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING ,3,HARDWARE_CAPCOM_CPS2,
	NULL, AvspRomInfo, AvspRomName, avspInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Alien vs Predator (USA 940520)

static struct BurnRomInfo AvspuRomDesc[] = {
	{ "avpu.03d",     0x080000, 0x42757950, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "avpu.04d",     0x080000, 0x5abcdee6, 1 | BRF_ESS | BRF_PRG },
	{ "avp.05d",      0x080000, 0xfbfb5d7a, 1 | BRF_ESS | BRF_PRG },
	{ "avp.06",       0x080000, 0x190b817f, 1 | BRF_ESS | BRF_PRG },

	{ "avp.13m",      0x200000, 0x8f8b5ae4, 3 | BRF_GRA },
	{ "avp.15m",      0x200000, 0xb00280df, 3 | BRF_GRA },
	{ "avp.17m",      0x200000, 0x94403195, 3 | BRF_GRA },
	{ "avp.19m",      0x200000, 0xe1981245, 3 | BRF_GRA },
	{ "avp.14m",      0x200000, 0xebba093e, 3 | BRF_GRA },
	{ "avp.16m",      0x200000, 0xfb228297, 3 | BRF_GRA },
	{ "avp.18m",      0x200000, 0x34fb7232, 3 | BRF_GRA },
	{ "avp.20m",      0x200000, 0xf90baa21, 3 | BRF_GRA },

	{ "avp.01",       0x020000, 0x2d3b4220, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "avp.11m",      0x200000, 0x83499817, 5 | BRF_SND },
	{ "avp.12m",      0x200000, 0xf4110d49, 5 | BRF_SND },
};

STD_ROM_PICK(Avspu) STD_ROM_FN(Avspu)

struct BurnDriver BurnDrvCpsAvspu = {
	"avspu", "avsp", NULL, "1994",
	"Alien vs Predator (USA 940520)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,3,HARDWARE_CAPCOM_CPS2,
	NULL, AvspuRomInfo, AvspuRomName, avspInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Alien vs Predator (Japan 940520)

static struct BurnRomInfo AvspjRomDesc[] = {
	{ "avpj.03d",     0x080000, 0x49799119, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "avpj.04d",     0x080000, 0x8cd2bba8, 1 | BRF_ESS | BRF_PRG },
	{ "avp.05d",      0x080000, 0xfbfb5d7a, 1 | BRF_ESS | BRF_PRG },
	{ "avp.06",       0x080000, 0x190b817f, 1 | BRF_ESS | BRF_PRG },

	{ "avp.13m",      0x200000, 0x8f8b5ae4, 3 | BRF_GRA },
	{ "avp.15m",      0x200000, 0xb00280df, 3 | BRF_GRA },
	{ "avp.17m",      0x200000, 0x94403195, 3 | BRF_GRA },
	{ "avp.19m",      0x200000, 0xe1981245, 3 | BRF_GRA },
	{ "avp.14m",      0x200000, 0xebba093e, 3 | BRF_GRA },
	{ "avp.16m",      0x200000, 0xfb228297, 3 | BRF_GRA },
	{ "avp.18m",      0x200000, 0x34fb7232, 3 | BRF_GRA },
	{ "avp.20m",      0x200000, 0xf90baa21, 3 | BRF_GRA },

	{ "avp.01",       0x020000, 0x2d3b4220, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "avp.11m",      0x200000, 0x83499817, 5 | BRF_SND },
	{ "avp.12m",      0x200000, 0xf4110d49, 5 | BRF_SND },
};

STD_ROM_PICK(Avspj) STD_ROM_FN(Avspj)

struct BurnDriver BurnDrvCpsAvspj = {
	"avspj", "avsp", NULL, "1994",
	"Alien vs Predator (Japan 940520)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,3,HARDWARE_CAPCOM_CPS2,
	NULL, AvspjRomInfo, AvspjRomName, avspInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Alien vs Predator (Asia 940520)

static struct BurnRomInfo AvspaRomDesc[] = {
	{ "avpa.03d",     0x080000, 0x6c1c1858, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "avpa.04d",     0x080000, 0x94f50b0c, 1 | BRF_ESS | BRF_PRG },
	{ "avp.05d",      0x080000, 0xfbfb5d7a, 1 | BRF_ESS | BRF_PRG },
	{ "avp.06",       0x080000, 0x190b817f, 1 | BRF_ESS | BRF_PRG },

	{ "avp.13m",      0x200000, 0x8f8b5ae4, 3 | BRF_GRA },
	{ "avp.15m",      0x200000, 0xb00280df, 3 | BRF_GRA },
	{ "avp.17m",      0x200000, 0x94403195, 3 | BRF_GRA },
	{ "avp.19m",      0x200000, 0xe1981245, 3 | BRF_GRA },
	{ "avp.14m",      0x200000, 0xebba093e, 3 | BRF_GRA },
	{ "avp.16m",      0x200000, 0xfb228297, 3 | BRF_GRA },
	{ "avp.18m",      0x200000, 0x34fb7232, 3 | BRF_GRA },
	{ "avp.20m",      0x200000, 0xf90baa21, 3 | BRF_GRA },

	{ "avp.01",       0x020000, 0x2d3b4220, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "avp.11m",      0x200000, 0x83499817, 5 | BRF_SND },
	{ "avp.12m",      0x200000, 0xf4110d49, 5 | BRF_SND },
};

STD_ROM_PICK(Avspa) STD_ROM_FN(Avspa)

struct BurnDriver BurnDrvCpsAvspa = {
	"avspa", "avsp", NULL, "1994",
	"Alien vs Predator (Asia 940520)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE, 3,HARDWARE_CAPCOM_CPS2,
	NULL, AvspaRomInfo, AvspaRomName, avspInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Alien vs Predator (Hispanic 940520)

static struct BurnRomInfo AvsphRomDesc[] = {
	{ "avph.03d",     0x080000, 0x3e440447, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "avph.04d",     0x080000, 0xaf6fc82f, 1 | BRF_ESS | BRF_PRG },
	{ "avp.05d",      0x080000, 0xfbfb5d7a, 1 | BRF_ESS | BRF_PRG },
	{ "avp.06",       0x080000, 0x190b817f, 1 | BRF_ESS | BRF_PRG },

	{ "avp.13m",      0x200000, 0x8f8b5ae4, 3 | BRF_GRA },
	{ "avp.15m",      0x200000, 0xb00280df, 3 | BRF_GRA },
	{ "avp.17m",      0x200000, 0x94403195, 3 | BRF_GRA },
	{ "avp.19m",      0x200000, 0xe1981245, 3 | BRF_GRA },
	{ "avp.14m",      0x200000, 0xebba093e, 3 | BRF_GRA },
	{ "avp.16m",      0x200000, 0xfb228297, 3 | BRF_GRA },
	{ "avp.18m",      0x200000, 0x34fb7232, 3 | BRF_GRA },
	{ "avp.20m",      0x200000, 0xf90baa21, 3 | BRF_GRA },

	{ "avp.01",       0x020000, 0x2d3b4220, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "avp.11m",      0x200000, 0x83499817, 5 | BRF_SND },
	{ "avp.12m",      0x200000, 0xf4110d49, 5 | BRF_SND },
};

STD_ROM_PICK(Avsph) STD_ROM_FN(Avsph)

struct BurnDriver BurnDrvCpsAvsph = {
	"avsph", "avsp", NULL, "1994",
	"Alien vs Predator (Hispanic 940520)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE, 3,HARDWARE_CAPCOM_CPS2,
	NULL, AvsphRomInfo, AvsphRomName, avspInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Alien vs. Predator (Euro 940520, Phoenix Edition)

static struct BurnRomInfo AvspdRomDesc[] = {
	{ "avped.03d",    0x80000,  0x66aa8aad, 1 | BRF_ESS | BRF_PRG },
	{ "avped.04d",    0x80000,  0x579306c2, 1 | BRF_ESS | BRF_PRG },
	{ "avp.05d",      0x80000,  0xfbfb5d7a, 1 | BRF_ESS | BRF_PRG },
	{ "avpd.06",      0x80000,  0x63094539, 1 | BRF_ESS | BRF_PRG },

	{ "avp.13m",      0x200000, 0x8f8b5ae4, 3 | BRF_GRA },
	{ "avp.15m",      0x200000, 0xb00280df, 3 | BRF_GRA },
	{ "avp.17m",      0x200000, 0x94403195, 3 | BRF_GRA },
	{ "avp.19m",      0x200000, 0xe1981245, 3 | BRF_GRA },
	{ "avp.14m",      0x200000, 0xebba093e, 3 | BRF_GRA },
	{ "avp.16m",      0x200000, 0xfb228297, 3 | BRF_GRA },
	{ "avp.18m",      0x200000, 0x34fb7232, 3 | BRF_GRA },
	{ "avp.20m",      0x200000, 0xf90baa21, 3 | BRF_GRA },

	{ "avp.01",       0x020000, 0x2d3b4220, 4 | BRF_ESS | BRF_PRG },

	{ "avp.11m",      0x200000, 0x83499817, 5 | BRF_SND },
	{ "avp.12m",      0x200000, 0xf4110d49, 5 | BRF_SND },
};

STD_ROM_PICK(Avspd) STD_ROM_FN(Avspd)

struct BurnDriver BurnDrvCpsAvspd = {
	"avspd", "avsp", NULL, "1994",
	"Alien vs. Predator (Euro 940520, Phoenix Edition)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE | BDF_BOOTLEG,3,HARDWARE_CAPCOM_CPS2,
	NULL, AvspdRomInfo, AvspdRomName, avspInputInfo, NULL,
	PhoenixInit, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Alien vs. Predator (3 Players for kaillera)

struct BurnDriver BurnDrvCpsAvsp3p = {
	"avsp3p", "avsp", NULL, "1994",
	"Alien vs. Predator (Euro 940520 / 3 Players for kaillera)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,3,HARDWARE_CAPCOM_CPS2,
	NULL, AvspRomInfo, AvspRomName, avspInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};

struct BurnDriver BurnDrvCpsAvspu3p = {
	"avspu3p", "avsp", "avspu", "1994",
	"Alien vs. Predator (USA 940520 / 3 Players for kaillera)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,3,HARDWARE_CAPCOM_CPS2,
	NULL, AvspuRomInfo, AvspuRomName, avspInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};

struct BurnDriver BurnDrvCpsAvspj3p = {
	"avspj3p", "avsp", "avspj", "1994",
	"Alien vs. Predator (Japan 940520 / 3 Players for kaillera)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,3,HARDWARE_CAPCOM_CPS2,
	NULL, AvspjRomInfo, AvspjRomName, avspInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};

struct BurnDriver BurnDrvCpsAvspa3p = {
	"avspa3p", "avsp", "avspa", "1994",
	"Alien vs. Predator (Asia 940520 / 3 Players for kaillera)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE, 3,HARDWARE_CAPCOM_CPS2,
	NULL, AvspaRomInfo, AvspaRomName, avspInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Battle Circuit (Euro 970319)

static struct BurnRomInfo BatcirRomDesc[] = {
	{ "btce.03",      0x080000, 0xbc60484b, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "btce.04",      0x080000, 0x457d55f6, 1 | BRF_ESS | BRF_PRG },
	{ "btce.05",      0x080000, 0xe86560d7, 1 | BRF_ESS | BRF_PRG },
	{ "btce.06",      0x080000, 0xf778e61b, 1 | BRF_ESS | BRF_PRG },
	{ "btc.07",       0x080000, 0x7322d5db, 1 | BRF_ESS | BRF_PRG },
	{ "btc.08",       0x080000, 0x6aac85ab, 1 | BRF_ESS | BRF_PRG },
	{ "btc.09",       0x080000, 0x1203db08, 1 | BRF_ESS | BRF_PRG },

	{ "btc.13m",      0x400000, 0xdc705bad, 3 | BRF_GRA },
	{ "btc.15m",      0x400000, 0xe5779a3c, 3 | BRF_GRA },
	{ "btc.17m",      0x400000, 0xb33f4112, 3 | BRF_GRA },
	{ "btc.19m",      0x400000, 0xa6fcdb7e, 3 | BRF_GRA },

	{ "btc.01",       0x020000, 0x1e194310, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "btc.02",       0x020000, 0x01aeb8e6, 4 | BRF_ESS | BRF_PRG },

	{ "btc.11m",      0x200000, 0xc27f2229, 5 | BRF_SND },
	{ "btc.12m",      0x200000, 0x418a2e33, 5 | BRF_SND },
};

STD_ROM_PICK(Batcir) STD_ROM_FN(Batcir)

struct BurnDriver BurnDrvCpsBatcir = {
	"batcir", NULL, NULL, "1997",
	"Battle Circuit (Euro 970319)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING,4,HARDWARE_CAPCOM_CPS2,
	NULL, BatcirRomInfo, BatcirRomName, batcirInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Battle Circuit (Japan 970319)

static struct BurnRomInfo BatcirjRomDesc[] = {
	{ "btcj.03",      0x080000, 0x6b7e168d, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "btcj.04",      0x080000, 0x46ba3467, 1 | BRF_ESS | BRF_PRG },
	{ "btcj.05",      0x080000, 0x0e23a859, 1 | BRF_ESS | BRF_PRG },
	{ "btcj.06",      0x080000, 0xa853b59c, 1 | BRF_ESS | BRF_PRG },
	{ "btc.07",       0x080000, 0x7322d5db, 1 | BRF_ESS | BRF_PRG },
	{ "btc.08",       0x080000, 0x6aac85ab, 1 | BRF_ESS | BRF_PRG },
	{ "btc.09",       0x080000, 0x1203db08, 1 | BRF_ESS | BRF_PRG },

	{ "btc.13m",      0x400000, 0xdc705bad, 3 | BRF_GRA },
	{ "btc.15m",      0x400000, 0xe5779a3c, 3 | BRF_GRA },
	{ "btc.17m",      0x400000, 0xb33f4112, 3 | BRF_GRA },
	{ "btc.19m",      0x400000, 0xa6fcdb7e, 3 | BRF_GRA },

	{ "btc.01",       0x020000, 0x1e194310, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "btc.02",       0x020000, 0x01aeb8e6, 4 | BRF_ESS | BRF_PRG },

	{ "btc.11m",      0x200000, 0xc27f2229, 5 | BRF_SND },
	{ "btc.12m",      0x200000, 0x418a2e33, 5 | BRF_SND },
};

STD_ROM_PICK(Batcirj) STD_ROM_FN(Batcirj)

struct BurnDriver BurnDrvCpsBatcirj = {
	"batcirj", "batcir", NULL, "1997",
	"Battle Circuit (Japan 970319)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,4,HARDWARE_CAPCOM_CPS2,
	NULL, BatcirjRomInfo, BatcirjRomName, batcirInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Battle Circuit (Asia 970319)

static struct BurnRomInfo BatciraRomDesc[] = {
	{ "btca.03",      0x080000, 0x1ad20d87, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "btca.04",      0x080000, 0x2b3f4dbe, 1 | BRF_ESS | BRF_PRG },
	{ "btca.05",      0x080000, 0x8238a3d9, 1 | BRF_ESS | BRF_PRG },
	{ "btca.06",      0x080000, 0x446c7c02, 1 | BRF_ESS | BRF_PRG },
	{ "btc.07",       0x080000, 0x7322d5db, 1 | BRF_ESS | BRF_PRG },
	{ "btc.08",       0x080000, 0x6aac85ab, 1 | BRF_ESS | BRF_PRG },
	{ "btc.09",       0x080000, 0x1203db08, 1 | BRF_ESS | BRF_PRG },

	{ "btc.13m",      0x400000, 0xdc705bad, 3 | BRF_GRA },
	{ "btc.15m",      0x400000, 0xe5779a3c, 3 | BRF_GRA },
	{ "btc.17m",      0x400000, 0xb33f4112, 3 | BRF_GRA },
	{ "btc.19m",      0x400000, 0xa6fcdb7e, 3 | BRF_GRA },

	{ "btc.01",       0x020000, 0x1e194310, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "btc.02",       0x020000, 0x01aeb8e6, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "btc.11m",      0x200000, 0xc27f2229, 5 | BRF_SND },
	{ "btc.12m",      0x200000, 0x418a2e33, 5 | BRF_SND },
};

STD_ROM_PICK(Batcira) STD_ROM_FN(Batcira)

struct BurnDriver BurnDrvCpsBatcira = {
	"batcira", "batcir", NULL, "1997",
	"Battle Circuit (Asia 970319)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,4,HARDWARE_CAPCOM_CPS2,
	NULL, BatciraRomInfo, BatciraRomName, batcirInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Battle Circuit (Euro 970319, Phoenix Edition)

static struct BurnRomInfo BatcirdRomDesc[] = {
	{ "btced.03",      0x80000, 0x0737db6d, 1 | BRF_ESS | BRF_PRG },
	{ "btced.04",      0x80000, 0xef1a8823, 1 | BRF_ESS | BRF_PRG },
	{ "btced.05",      0x80000, 0x20bdbb14, 1 | BRF_ESS | BRF_PRG },
	{ "btced.06",      0x80000, 0xb4d8f5bc, 1 | BRF_ESS | BRF_PRG },
	{ "btc.07",        0x80000, 0x7322d5db, 1 | BRF_ESS | BRF_PRG },
	{ "btc.08",        0x80000, 0x6aac85ab, 1 | BRF_ESS | BRF_PRG },
	{ "btc.09",        0x80000, 0x1203db08, 1 | BRF_ESS | BRF_PRG },

	{ "btc.13m",      0x400000, 0xdc705bad, 3 | BRF_GRA },
	{ "btc.15m",      0x400000, 0xe5779a3c, 3 | BRF_GRA },
	{ "btc.17m",      0x400000, 0xb33f4112, 3 | BRF_GRA },
	{ "btc.19m",      0x400000, 0xa6fcdb7e, 3 | BRF_GRA },

	{ "btc.01",       0x020000, 0x1e194310, 4 | BRF_ESS | BRF_PRG },
	{ "btc.02",       0x020000, 0x01aeb8e6, 4 | BRF_ESS | BRF_PRG },

	{ "btc.11m",      0x200000, 0xc27f2229, 5 | BRF_SND },
	{ "btc.12m",      0x200000, 0x418a2e33, 5 | BRF_SND },
};

STD_ROM_PICK(Batcird) STD_ROM_FN(Batcird)

struct BurnDriver BurnDrvCpsBatcird = {
	"batcird", "batcir", NULL, "1997",
	"Battle Circuit (Euro 970319, Phoenix Edition)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE | BDF_BOOTLEG,4,HARDWARE_CAPCOM_CPS2,
	NULL, BatcirdRomInfo, BatcirdRomName, batcirInputInfo, NULL,
	PhoenixInit, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Battle Circuit (4 Players for kaillera)

struct BurnDriver BurnDrvCpsBatcir4p = {
	"batcir4p", "batcir", NULL, "1997",
	"Battle Circuit (Euro 970319 / 4 Players for kaillera)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,4,HARDWARE_CAPCOM_CPS2,
	NULL, BatcirRomInfo, BatcirRomName, batcirInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};

struct BurnDriver BurnDrvCpsBatcirj4p = {
	"btcirj4p", "batcir", "batcirj", "1997",
	"Battle Circuit (Japan 970319 / 4 Players for kaillera)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,4,HARDWARE_CAPCOM_CPS2,
	NULL, BatcirjRomInfo, BatcirjRomName, batcirInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Choko (Japan 010820)

static struct BurnRomInfo chokoRomDesc[] = {
	{ "tkoj.03",       0x080000, 0x11f5452f,  1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "tkoj.04",       0x080000, 0x68655378,  1 | BRF_ESS | BRF_PRG },

	{ "tkoj1_d.simm1", 0x200000, 0x6933377d, 11 | BRF_GRA },
	{ "tkoj1_c.simm1", 0x200000, 0x7f668950, 11 | BRF_GRA },
	{ "tkoj1_b.simm1", 0x200000, 0xcfb68ca9, 11 | BRF_GRA },
	{ "tkoj1_a.simm1", 0x200000, 0x437e21c5, 11 | BRF_GRA },
	{ "tkoj3_d.simm3", 0x200000, 0xa9e32b57, 11 | BRF_GRA },
	{ "tkoj3_c.simm3", 0x200000, 0xb7ab9338, 11 | BRF_GRA },
	{ "tkoj3_b.simm3", 0x200000, 0x4d3f919a, 11 | BRF_GRA },
	{ "tkoj3_a.simm3", 0x200000, 0xcfef17ab, 11 | BRF_GRA },

	{ "tko.01",        0x020000, 0x6eda50c2,  4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "tkoj5_a.simm5", 0x200000, 0xab45d509, 15 | BRF_SND },
	{ "tkoj5_b.simm5", 0x200000, 0xfa905c3d, 15 | BRF_SND },
};

STD_ROM_PICK(choko) STD_ROM_FN(choko)

struct BurnDriver BurnDrvCpschoko = {
	"choko", NULL, NULL, "2001",
	"Janpai Puzzle Choukou (Japan 010820)\0", NULL, "Mitchell", "CPS2",
	 L"\u9577\u6C5F (010820 Japan)\0", NULL, NULL, NULL,
	BDF_GAME_WORKING, 2, HARDWARE_CAPCOM_CPS2 | HARDWARE_CAPCOM_CPS2_SIMM,
	NULL, chokoRomInfo, chokoRomName, chokoInputInfo, NULL,
	Cps2Init,CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Capcom Sports Club (Euro 971017)

static struct BurnRomInfo CsclubRomDesc[] = {
	{ "csce.03a",    0x080000, 0x824082be, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "csce.04a",    0x080000, 0x74e6a4fe, 1 | BRF_ESS | BRF_PRG },
	{ "csce.05a",    0x080000, 0x8ae0df19, 1 | BRF_ESS | BRF_PRG },
	{ "csce.06a",    0x080000, 0x51f2f0d3, 1 | BRF_ESS | BRF_PRG },
	{ "csce.07a",    0x080000, 0x003968fd, 1 | BRF_ESS | BRF_PRG },

	{ "csc.73",      0x080000, 0x335f07c3, 6 | BRF_GRA },
	{ "csc.74",      0x080000, 0xab215357, 6 | BRF_GRA },
	{ "csc.75",      0x080000, 0xa2367381, 6 | BRF_GRA },
	{ "csc.76",      0x080000, 0x728aac1f, 6 | BRF_GRA },
	{ "csc.63",      0x080000, 0x3711b8ca, 6 | BRF_GRA },
	{ "csc.64",      0x080000, 0x828a06d8, 6 | BRF_GRA },
	{ "csc.65",      0x080000, 0x86ee4569, 6 | BRF_GRA },
	{ "csc.66",      0x080000, 0xc24f577f, 6 | BRF_GRA },
	{ "csc.83",      0x080000, 0x0750d12a, 6 | BRF_GRA },
	{ "csc.84",      0x080000, 0x90a92f39, 6 | BRF_GRA },
	{ "csc.85",      0x080000, 0xd08ab012, 6 | BRF_GRA },
	{ "csc.86",      0x080000, 0x41652583, 6 | BRF_GRA },
	{ "csc.93",      0x080000, 0xa756c7f7, 6 | BRF_GRA },
	{ "csc.94",      0x080000, 0xfb7ccc73, 6 | BRF_GRA },
	{ "csc.95",      0x080000, 0x4d014297, 6 | BRF_GRA },
	{ "csc.96",      0x080000, 0x6754b1ef, 6 | BRF_GRA },

	{ "csc.01",      0x020000, 0xee162111, 4 | BRF_ESS | BRF_PRG },

	{ "csc.51",      0x080000, 0x5a52afd5, 5 | BRF_SND },
	{ "csc.52",      0x080000, 0x1408a811, 5 | BRF_SND },
	{ "csc.53",      0x080000, 0x4fb9f57c, 5 | BRF_SND },
	{ "csc.54",      0x080000, 0x9a8f40ec, 5 | BRF_SND },
	{ "csc.55",      0x080000, 0x91529a91, 5 | BRF_SND },
	{ "csc.56",      0x080000, 0x9a345334, 5 | BRF_SND },
	{ "csc.57",      0x080000, 0xaedc27f2, 5 | BRF_SND },
	{ "csc.58",      0x080000, 0x2300b7b3, 5 | BRF_SND },
};

STD_ROM_PICK(Csclub) STD_ROM_FN(Csclub)

struct BurnDriver BurnDrvCpsCsclub = {
	"csclub", NULL, NULL, "1997",
	"Capcom Sports Club (Euro 971017)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING,2,HARDWARE_CAPCOM_CPS2,
	NULL, CsclubRomInfo, CsclubRomName, csclubInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Capcom Sports Club (Euro 970722)

static struct BurnRomInfo Csclub1RomDesc[] = {
	{ "csce.03",      0x080000, 0xf2c852ef, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "csce.04",      0x080000, 0x1184530f, 1 | BRF_ESS | BRF_PRG },
	{ "csce.05",      0x080000, 0x804e2b6b, 1 | BRF_ESS | BRF_PRG },
	{ "csce.06",      0x080000, 0x09277cb9, 1 | BRF_ESS | BRF_PRG },
	{ "csc.07",       0x080000, 0x01b05caa, 1 | BRF_ESS | BRF_PRG },

	{ "csc.14m",      0x200000, 0xe8904afa, 3 | BRF_GRA },
	{ "csc.16m",      0x200000, 0xc98c8079, 3 | BRF_GRA },
	{ "csc.18m",      0x200000, 0xc030df5a, 3 | BRF_GRA },
	{ "csc.20m",      0x200000, 0xb4e55863, 3 | BRF_GRA },

	{ "csc.01",       0x020000, 0xee162111, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "csc.11m",      0x200000, 0xa027b827, 5 | BRF_SND },
	{ "csc.12m",      0x200000, 0xcb7f6e55, 5 | BRF_SND },
};

STD_ROM_PICK(Csclub1) STD_ROM_FN(Csclub1)

struct BurnDriver BurnDrvCpsCsclub1 = {
	"csclub1", "csclub", NULL, "1997",
	"Capcom Sports Club (Euro 970722)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Csclub1RomInfo, Csclub1RomName, csclubInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Capcom Sports Club (Japan 970722)

static struct BurnRomInfo CsclubjRomDesc[] = {
	{ "cscj.03",      0x080000, 0xec4ddaa2, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "cscj.04",      0x080000, 0x60c632bb, 1 | BRF_ESS | BRF_PRG },
	{ "cscj.05",      0x080000, 0xad042003, 1 | BRF_ESS | BRF_PRG },
	{ "cscj.06",      0x080000, 0x169e4d40, 1 | BRF_ESS | BRF_PRG },
	{ "csc.07",       0x080000, 0x01b05caa, 1 | BRF_ESS | BRF_PRG },

	{ "csc.14m",      0x200000, 0xe8904afa, 3 | BRF_GRA },
	{ "csc.16m",      0x200000, 0xc98c8079, 3 | BRF_GRA },
	{ "csc.18m",      0x200000, 0xc030df5a, 3 | BRF_GRA },
	{ "csc.20m",      0x200000, 0xb4e55863, 3 | BRF_GRA },

	{ "csc.01",       0x020000, 0xee162111, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "csc.11m",      0x200000, 0xa027b827, 5 | BRF_SND },
	{ "csc.12m",      0x200000, 0xcb7f6e55, 5 | BRF_SND },
};

STD_ROM_PICK(Csclubj) STD_ROM_FN(Csclubj)

struct BurnDriver BurnDrvCpsCsclubj = {
	"csclubj", "csclub", NULL, "1997",
	"Capcom Sports Club (Japan 970722)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, CsclubjRomInfo, CsclubjRomName, csclubInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Capcom Sports Club (Asia 970722)

static struct BurnRomInfo CsclubaRomDesc[] = {
	{ "csca.03",      0x080000, 0xb6acd708, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "csca.04",      0x080000, 0xd44ae35f, 1 | BRF_ESS | BRF_PRG },
	{ "csca.05",      0x080000, 0x8da76aec, 1 | BRF_ESS | BRF_PRG },
	{ "csca.06",      0x080000, 0xa1b7b1ee, 1 | BRF_ESS | BRF_PRG },
	{ "csc.07",       0x080000, 0x01b05caa, 1 | BRF_ESS | BRF_PRG },

	{ "csc.14m",      0x200000, 0xe8904afa, 3 | BRF_GRA },
	{ "csc.16m",      0x200000, 0xc98c8079, 3 | BRF_GRA },
	{ "csc.18m",      0x200000, 0xc030df5a, 3 | BRF_GRA },
	{ "csc.20m",      0x200000, 0xb4e55863, 3 | BRF_GRA },

	{ "csc.01",       0x020000, 0xee162111, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "csc.11m",      0x200000, 0xa027b827, 5 | BRF_SND },
	{ "csc.12m",      0x200000, 0xcb7f6e55, 5 | BRF_SND },
};

STD_ROM_PICK(Cscluba) STD_ROM_FN(Cscluba)

struct BurnDriver BurnDrvCpsCscluba = {
	"cscluba", "csclub", NULL, "1997",
	"Capcom Sports Club (Asia 970722)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, CsclubaRomInfo, CsclubaRomName, csclubInputInfo, NULL,
	Cps2Init,CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};

// Capcom Sports Club (Hispanic 970722)

static struct BurnRomInfo csclubhRomDesc[] = {
	{ "csch.03",      0x080000, 0x0dd7e46d, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "csch.04",      0x080000, 0x486e8143, 1 | BRF_ESS | BRF_PRG },
	{ "csch.05",      0x080000, 0x9e509dfb, 1 | BRF_ESS | BRF_PRG },
	{ "csch.06",      0x080000, 0x817ba313, 1 | BRF_ESS | BRF_PRG },
	{ "csc.07",       0x080000, 0x01b05caa, 1 | BRF_ESS | BRF_PRG },

	{ "csc.14m",      0x200000, 0xe8904afa, 3 | BRF_GRA },
	{ "csc.16m",      0x200000, 0xc98c8079, 3 | BRF_GRA },
	{ "csc.18m",      0x200000, 0xc030df5a, 3 | BRF_GRA },
	{ "csc.20m",      0x200000, 0xb4e55863, 3 | BRF_GRA },

	{ "csc.01",       0x020000, 0xee162111, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "csc.11m",      0x200000, 0xa027b827, 5 | BRF_SND },
	{ "csc.12m",      0x200000, 0xcb7f6e55, 5 | BRF_SND },
};

STD_ROM_PICK(csclubh) STD_ROM_FN(csclubh)

struct BurnDriver BurnDrvCpscsclubh = {
	"csclubh", "csclub", NULL, "1997",
	"Capcom Sports Club (Hispanic 970722)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, csclubhRomInfo,csclubhRomName, csclubInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Cyberbots: Fullmetal Madness (Euro 950424)

static struct BurnRomInfo CybotsRomDesc[] = {
	{ "cybe.03",      0x080000, 0x234381cd, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "cybe.04",      0x080000, 0x80691061, 1 | BRF_ESS | BRF_PRG },
	{ "cyb.05",       0x080000, 0xec40408e, 1 | BRF_ESS | BRF_PRG },
	{ "cyb.06",       0x080000, 0x1ad0bed2, 1 | BRF_ESS | BRF_PRG },
	{ "cyb.07",       0x080000, 0x6245a39a, 1 | BRF_ESS | BRF_PRG },
	{ "cyb.08",       0x080000, 0x4b48e223, 1 | BRF_ESS | BRF_PRG },
	{ "cyb.09",       0x080000, 0xe15238f6, 1 | BRF_ESS | BRF_PRG },
	{ "cyb.10",       0x080000, 0x75f4003b, 1 | BRF_ESS | BRF_PRG },

	{ "cyb.13m",      0x400000, 0xf0dce192, 3 | BRF_GRA },
	{ "cyb.15m",      0x400000, 0x187aa39c, 3 | BRF_GRA },
	{ "cyb.17m",      0x400000, 0x8a0e4b12, 3 | BRF_GRA },
	{ "cyb.19m",      0x400000, 0x34b62612, 3 | BRF_GRA },
	{ "cyb.14m",      0x400000, 0xc1537957, 3 | BRF_GRA },
	{ "cyb.16m",      0x400000, 0x15349e86, 3 | BRF_GRA },
	{ "cyb.18m",      0x400000, 0xd83e977d, 3 | BRF_GRA },
	{ "cyb.20m",      0x400000, 0x77cdad5c, 3 | BRF_GRA },

	{ "cyb.01",       0x020000, 0x9c0fb079, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "cyb.02",       0x020000, 0x51cb0c4e, 4 | BRF_ESS | BRF_PRG },

	{ "cyb.11m",      0x200000, 0x362ccab2, 5 | BRF_SND },
	{ "cyb.12m",      0x200000, 0x7066e9cc, 5 | BRF_SND },
};

STD_ROM_PICK(Cybots) STD_ROM_FN(Cybots)

struct BurnDriver BurnDrvCpsCybots = {
	"cybots", NULL, NULL, "1995",
	"Cyberbots: Fullmetal Madness (Euro 950424)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING,2,HARDWARE_CAPCOM_CPS2,
	NULL, CybotsRomInfo, CybotsRomName, cybotsInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Cyberbots: Fullmetal Madness (USA 950424)

static struct BurnRomInfo CybotsuRomDesc[] = {
	{ "cybu.03",      0x080000, 0xdb4da8f4, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "cybu.04",      0x080000, 0x1eec68ac, 1 | BRF_ESS | BRF_PRG },
	{ "cyb.05",       0x080000, 0xec40408e, 1 | BRF_ESS | BRF_PRG },
	{ "cyb.06",       0x080000, 0x1ad0bed2, 1 | BRF_ESS | BRF_PRG },
	{ "cyb.07",       0x080000, 0x6245a39a, 1 | BRF_ESS | BRF_PRG },
	{ "cyb.08",       0x080000, 0x4b48e223, 1 | BRF_ESS | BRF_PRG },
	{ "cyb.09",       0x080000, 0xe15238f6, 1 | BRF_ESS | BRF_PRG },
	{ "cyb.10",       0x080000, 0x75f4003b, 1 | BRF_ESS | BRF_PRG },

	{ "cyb.13m",      0x400000, 0xf0dce192, 3 | BRF_GRA },
	{ "cyb.15m",      0x400000, 0x187aa39c, 3 | BRF_GRA },
	{ "cyb.17m",      0x400000, 0x8a0e4b12, 3 | BRF_GRA },
	{ "cyb.19m",      0x400000, 0x34b62612, 3 | BRF_GRA },
	{ "cyb.14m",      0x400000, 0xc1537957, 3 | BRF_GRA },
	{ "cyb.16m",      0x400000, 0x15349e86, 3 | BRF_GRA },
	{ "cyb.18m",      0x400000, 0xd83e977d, 3 | BRF_GRA },
	{ "cyb.20m",      0x400000, 0x77cdad5c, 3 | BRF_GRA },

	{ "cyb.01",       0x020000, 0x9c0fb079, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "cyb.02",       0x020000, 0x51cb0c4e, 4 | BRF_ESS | BRF_PRG },

	{ "cyb.11m",      0x200000, 0x362ccab2, 5 | BRF_SND },
	{ "cyb.12m",      0x200000, 0x7066e9cc, 5 | BRF_SND },
};

STD_ROM_PICK(Cybotsu) STD_ROM_FN(Cybotsu)

struct BurnDriver BurnDrvCpsCybotsu = {
	"cybotsu", "cybots", NULL, "1995",
	"Cyberbots: Fullmetal Madness (USA 950424)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, CybotsuRomInfo, CybotsuRomName, cybotsInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Cyberbots: Fullmetal Madness (Japan 950420)

static struct BurnRomInfo CybotsjRomDesc[] = {
	{ "cybj.03",      0x080000, 0x6096eada, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "cybj.04",      0x080000, 0x7b0ffaa9, 1 | BRF_ESS | BRF_PRG },
	{ "cyb.05",       0x080000, 0xec40408e, 1 | BRF_ESS | BRF_PRG },
	{ "cyb.06",       0x080000, 0x1ad0bed2, 1 | BRF_ESS | BRF_PRG },
	{ "cyb.07",       0x080000, 0x6245a39a, 1 | BRF_ESS | BRF_PRG },
	{ "cyb.08",       0x080000, 0x4b48e223, 1 | BRF_ESS | BRF_PRG },
	{ "cyb.09",       0x080000, 0xe15238f6, 1 | BRF_ESS | BRF_PRG },
	{ "cyb.10",       0x080000, 0x75f4003b, 1 | BRF_ESS | BRF_PRG },

	{ "cyb.13m",      0x400000, 0xf0dce192, 3 | BRF_GRA },
	{ "cyb.15m",      0x400000, 0x187aa39c, 3 | BRF_GRA },
	{ "cyb.17m",      0x400000, 0x8a0e4b12, 3 | BRF_GRA },
	{ "cyb.19m",      0x400000, 0x34b62612, 3 | BRF_GRA },
	{ "cyb.14m",      0x400000, 0xc1537957, 3 | BRF_GRA },
	{ "cyb.16m",      0x400000, 0x15349e86, 3 | BRF_GRA },
	{ "cyb.18m",      0x400000, 0xd83e977d, 3 | BRF_GRA },
	{ "cyb.20m",      0x400000, 0x77cdad5c, 3 | BRF_GRA },

	{ "cyb.01",       0x020000, 0x9c0fb079, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "cyb.02",       0x020000, 0x51cb0c4e, 4 | BRF_ESS | BRF_PRG },

	{ "cyb.11m",      0x200000, 0x362ccab2, 5 | BRF_SND },
	{ "cyb.12m",      0x200000, 0x7066e9cc, 5 | BRF_SND },
};

STD_ROM_PICK(Cybotsj) STD_ROM_FN(Cybotsj)

struct BurnDriver BurnDrvCpsCybotsj = {
	"cybotsj", "cybots", NULL, "1995",
	"Cyberbots: Fullmetal Madness (Japan 950420)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, CybotsjRomInfo, CybotsjRomName, cybotsInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Dungeons & Dragons: Tower of Doom (Euro 940412)

static struct BurnRomInfo DdtodRomDesc[] = {
	{ "dade.03c",     0x080000, 0x8e73533d, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "dade.04c",     0x080000, 0x00c2e82e, 1 | BRF_ESS | BRF_PRG },
	{ "dade.05c",     0x080000, 0xea996008, 1 | BRF_ESS | BRF_PRG },
	{ "dad.06a",      0x080000, 0x6225495a, 1 | BRF_ESS | BRF_PRG },
	{ "dad.07a",      0x080000, 0xb3480ec3, 1 | BRF_ESS | BRF_PRG },

	{ "dad.13m",      0x200000, 0xda3cb7d6, 3 | BRF_GRA },
	{ "dad.15m",      0x200000, 0x92b63172, 3 | BRF_GRA },
	{ "dad.17m",      0x200000, 0xb98757f5, 3 | BRF_GRA },
	{ "dad.19m",      0x200000, 0x8121ce46, 3 | BRF_GRA },
	{ "dad.14m",      0x100000, 0x837e6f3f, 3 | BRF_GRA },
	{ "dad.16m",      0x100000, 0xf0916bdb, 3 | BRF_GRA },
	{ "dad.18m",      0x100000, 0xcef393ef, 3 | BRF_GRA },
	{ "dad.20m",      0x100000, 0x8953fe9e, 3 | BRF_GRA },

	{ "dad.01",       0x020000, 0x3f5e2424, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "dad.11m",      0x200000, 0x0c499b67, 5 | BRF_SND },
	{ "dad.12m",      0x200000, 0x2f0b5a4e, 5 | BRF_SND },
};

STD_ROM_PICK(Ddtod) STD_ROM_FN(Ddtod)

struct BurnDriver BurnDrvCpsDdtod = {
	"ddtod", NULL, NULL, "1994",
	"Dungeons & Dragons: Tower of Doom (Euro 940412)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING,4,HARDWARE_CAPCOM_CPS2,
	NULL, DdtodRomInfo, DdtodRomName, ddsomInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Dungeons & Dragons: Tower of Doom (Euro 940113)

static struct BurnRomInfo ddtodr1RomDesc[] = {
	{ "dade.03a",     0x080000, 0x665a035e, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "dade.04a",     0x080000, 0x02613207, 1 | BRF_ESS | BRF_PRG },
	{ "dade.05a",     0x080000, 0x36845996, 1 | BRF_ESS | BRF_PRG },
	{ "dad.06",       0x080000, 0x13aa3e56, 1 | BRF_ESS | BRF_PRG },
	{ "dad.07",       0x080000, 0x431cb6dd, 1 | BRF_ESS | BRF_PRG },

	{ "dad.13m",      0x200000, 0xda3cb7d6, 3 | BRF_GRA },
	{ "dad.15m",      0x200000, 0x92b63172, 3 | BRF_GRA },
	{ "dad.17m",      0x200000, 0xb98757f5, 3 | BRF_GRA },
	{ "dad.19m",      0x200000, 0x8121ce46, 3 | BRF_GRA },
	{ "dad.14m",      0x100000, 0x837e6f3f, 3 | BRF_GRA },
	{ "dad.16m",      0x100000, 0xf0916bdb, 3 | BRF_GRA },
	{ "dad.18m",      0x100000, 0xcef393ef, 3 | BRF_GRA },
	{ "dad.20m",      0x100000, 0x8953fe9e, 3 | BRF_GRA },

	{ "dad.01",       0x020000, 0x3f5e2424, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "dad.11m",      0x200000, 0x0c499b67, 5 | BRF_SND },
	{ "dad.12m",      0x200000, 0x2f0b5a4e, 5 | BRF_SND },
};

STD_ROM_PICK(ddtodr1) STD_ROM_FN(ddtodr1)

struct BurnDriver BurnDrvCpsddtodr1 = {
	"ddtodr1", "ddtod", NULL, "1994",
	"Dungeons & Dragons: Tower of Doom (Euro 940113)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,4,HARDWARE_CAPCOM_CPS2,
	NULL, ddtodr1RomInfo, ddtodr1RomName, ddsomInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Dungeons & Dragons: Tower of Doom (USA 940125)

static struct BurnRomInfo DdtoduRomDesc[] = {
	{ "dadu.03b",     0x080000, 0xa519905f, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "dadu.04b",     0x080000, 0x52562d38, 1 | BRF_ESS | BRF_PRG },
	{ "dadu.05b",     0x080000, 0xee1cfbfe, 1 | BRF_ESS | BRF_PRG },
	{ "dad.06",       0x080000, 0x13aa3e56, 1 | BRF_ESS | BRF_PRG },
	{ "dad.07",       0x080000, 0x431cb6dd, 1 | BRF_ESS | BRF_PRG },

	{ "dad.13m",      0x200000, 0xda3cb7d6, 3 | BRF_GRA },
	{ "dad.15m",      0x200000, 0x92b63172, 3 | BRF_GRA },
	{ "dad.17m",      0x200000, 0xb98757f5, 3 | BRF_GRA },
	{ "dad.19m",      0x200000, 0x8121ce46, 3 | BRF_GRA },
	{ "dad.14m",      0x100000, 0x837e6f3f, 3 | BRF_GRA },
	{ "dad.16m",      0x100000, 0xf0916bdb, 3 | BRF_GRA },
	{ "dad.18m",      0x100000, 0xcef393ef, 3 | BRF_GRA },
	{ "dad.20m",      0x100000, 0x8953fe9e, 3 | BRF_GRA },

	{ "dad.01",       0x020000, 0x3f5e2424, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "dad.11m",      0x200000, 0x0c499b67, 5 | BRF_SND },
	{ "dad.12m",      0x200000, 0x2f0b5a4e, 5 | BRF_SND },
};

STD_ROM_PICK(Ddtodu) STD_ROM_FN(Ddtodu)

struct BurnDriver BurnDrvCpsDdtodu = {
	"ddtodu", "ddtod", NULL, "1994",
	"Dungeons & Dragons: Tower of Doom (USA 940125)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,4,HARDWARE_CAPCOM_CPS2,
	NULL, DdtoduRomInfo, DdtoduRomName, ddsomInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Dungeons & Dragons: Tower of Doom (USA 940113)

static struct BurnRomInfo Ddtodur1RomDesc[] = {
	{ "dadu.03a",     0x080000, 0x4413f177, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "dadu.04a",     0x080000, 0x168de230, 1 | BRF_ESS | BRF_PRG },
	{ "dadu.05a",     0x080000, 0x03d39e91, 1 | BRF_ESS | BRF_PRG },
	{ "dad.06",       0x080000, 0x13aa3e56, 1 | BRF_ESS | BRF_PRG },
	{ "dad.07",       0x080000, 0x431cb6dd, 1 | BRF_ESS | BRF_PRG },

	{ "dad.13m",      0x200000, 0xda3cb7d6, 3 | BRF_GRA },
	{ "dad.15m",      0x200000, 0x92b63172, 3 | BRF_GRA },
	{ "dad.17m",      0x200000, 0xb98757f5, 3 | BRF_GRA },
	{ "dad.19m",      0x200000, 0x8121ce46, 3 | BRF_GRA },
	{ "dad.14m",      0x100000, 0x837e6f3f, 3 | BRF_GRA },
	{ "dad.16m",      0x100000, 0xf0916bdb, 3 | BRF_GRA },
	{ "dad.18m",      0x100000, 0xcef393ef, 3 | BRF_GRA },
	{ "dad.20m",      0x100000, 0x8953fe9e, 3 | BRF_GRA },

	{ "dad.01",       0x020000, 0x3f5e2424, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "dad.11m",      0x200000, 0x0c499b67, 5 | BRF_SND },
	{ "dad.12m",      0x200000, 0x2f0b5a4e, 5 | BRF_SND },
};

STD_ROM_PICK(Ddtodur1) STD_ROM_FN(Ddtodur1)

struct BurnDriver BurnDrvCpsDdtodur1 = {
	"ddtodur1", "ddtod", NULL, "1994",
	"Dungeons & Dragons: Tower of Doom (USA 940113)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,4,HARDWARE_CAPCOM_CPS2,
	NULL, Ddtodur1RomInfo, Ddtodur1RomName, ddsomInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Dungeons & Dragons: Tower of Doom (Japan 940412)

static struct BurnRomInfo DdtodjRomDesc[] = {
	{ "dadj.03c",     0x080000, 0x0b1b5798, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "dadj.04c",     0x080000, 0xc6a2fbc8, 1 | BRF_ESS | BRF_PRG },
	{ "dadj.05c",     0x080000, 0x189b15fe, 1 | BRF_ESS | BRF_PRG },
	{ "dad.06a",      0x080000, 0x6225495a, 1 | BRF_ESS | BRF_PRG },
	{ "dad.07a",      0x080000, 0xb3480ec3, 1 | BRF_ESS | BRF_PRG },

	{ "dad.13m",      0x200000, 0xda3cb7d6, 3 | BRF_GRA },
	{ "dad.15m",      0x200000, 0x92b63172, 3 | BRF_GRA },
	{ "dad.17m",      0x200000, 0xb98757f5, 3 | BRF_GRA },
	{ "dad.19m",      0x200000, 0x8121ce46, 3 | BRF_GRA },
	{ "dad.14m",      0x100000, 0x837e6f3f, 3 | BRF_GRA },
	{ "dad.16m",      0x100000, 0xf0916bdb, 3 | BRF_GRA },
	{ "dad.18m",      0x100000, 0xcef393ef, 3 | BRF_GRA },
	{ "dad.20m",      0x100000, 0x8953fe9e, 3 | BRF_GRA },

	{ "dad.01",       0x020000, 0x3f5e2424, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "dad.11m",      0x200000, 0x0c499b67, 5 | BRF_SND },
	{ "dad.12m",      0x200000, 0x2f0b5a4e, 5 | BRF_SND },
};

STD_ROM_PICK(Ddtodj) STD_ROM_FN(Ddtodj)

struct BurnDriver BurnDrvCpsDdtodj = {
	"ddtodj", "ddtod", NULL, "1994",
	"Dungeons & Dragons: Tower of Doom (Japan 940412)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,4,HARDWARE_CAPCOM_CPS2,
	NULL, DdtodjRomInfo, DdtodjRomName, ddsomInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Dungeons & Dragons: Tower of Doom (Japan 940125)

static struct BurnRomInfo Ddtodjr1RomDesc[] = {
	{ "dadj.03b",     0x080000, 0x87606b85, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "dadj.04b",     0x080000, 0x24d49575, 1 | BRF_ESS | BRF_PRG },
	{ "dadj.05b",     0x080000, 0x56ce51f7, 1 | BRF_ESS | BRF_PRG },
	{ "dad.06",       0x080000, 0x13aa3e56, 1 | BRF_ESS | BRF_PRG },
	{ "dad.07",       0x080000, 0x431cb6dd, 1 | BRF_ESS | BRF_PRG },

	{ "dad.13m",      0x200000, 0xda3cb7d6, 3 | BRF_GRA },
	{ "dad.15m",      0x200000, 0x92b63172, 3 | BRF_GRA },
	{ "dad.17m",      0x200000, 0xb98757f5, 3 | BRF_GRA },
	{ "dad.19m",      0x200000, 0x8121ce46, 3 | BRF_GRA },
	{ "dad.14m",      0x100000, 0x837e6f3f, 3 | BRF_GRA },
	{ "dad.16m",      0x100000, 0xf0916bdb, 3 | BRF_GRA },
	{ "dad.18m",      0x100000, 0xcef393ef, 3 | BRF_GRA },
	{ "dad.20m",      0x100000, 0x8953fe9e, 3 | BRF_GRA },

	{ "dad.01",       0x020000, 0x3f5e2424, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "dad.11m",      0x200000, 0x0c499b67, 5 | BRF_SND },
	{ "dad.12m",      0x200000, 0x2f0b5a4e, 5 | BRF_SND },
};

STD_ROM_PICK(Ddtodjr1) STD_ROM_FN(Ddtodjr1)

struct BurnDriver BurnDrvCpsDdtodjr1 = {
	"ddtodjr1", "ddtod", NULL, "1994",
	"Dungeons & Dragons: Tower of Doom (Japan 940125)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,4,HARDWARE_CAPCOM_CPS2,
	NULL, Ddtodjr1RomInfo, Ddtodjr1RomName, ddsomInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Dungeons & Dragons: Tower of Doom (Japan 940113)

static struct BurnRomInfo Ddtodjr2RomDesc[] = {
	{ "dadj.03a",     0x080000, 0x711638dc, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "dadj.04a",     0x080000, 0x4869639c, 1 | BRF_ESS | BRF_PRG },
	{ "dadj.05a",     0x080000, 0x484c0efa, 1 | BRF_ESS | BRF_PRG },
	{ "dad.06",       0x080000, 0x13aa3e56, 1 | BRF_ESS | BRF_PRG },
	{ "dad.07",       0x080000, 0x431cb6dd, 1 | BRF_ESS | BRF_PRG },

	{ "dad.13m",      0x200000, 0xda3cb7d6, 3 | BRF_GRA },
	{ "dad.15m",      0x200000, 0x92b63172, 3 | BRF_GRA },
	{ "dad.17m",      0x200000, 0xb98757f5, 3 | BRF_GRA },
	{ "dad.19m",      0x200000, 0x8121ce46, 3 | BRF_GRA },
	{ "dad.14m",      0x100000, 0x837e6f3f, 3 | BRF_GRA },
	{ "dad.16m",      0x100000, 0xf0916bdb, 3 | BRF_GRA },
	{ "dad.18m",      0x100000, 0xcef393ef, 3 | BRF_GRA },
	{ "dad.20m",      0x100000, 0x8953fe9e, 3 | BRF_GRA },

	{ "dad.01",       0x020000, 0x3f5e2424, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "dad.11m",      0x200000, 0x0c499b67, 5 | BRF_SND },
	{ "dad.12m",      0x200000, 0x2f0b5a4e, 5 | BRF_SND },
};

STD_ROM_PICK(Ddtodjr2) STD_ROM_FN(Ddtodjr2)

struct BurnDriver BurnDrvCpsDdtodjr2 = {
	"ddtodjr2", "ddtod", NULL, "1994",
	"Dungeons & Dragons: Tower of Doom (Japan 940113)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,4,HARDWARE_CAPCOM_CPS2,
	NULL, Ddtodjr2RomInfo, Ddtodjr2RomName, ddsomInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Dungeons & Dragons: Tower of Doom (Asia 940113)

static struct BurnRomInfo DdtodaRomDesc[] = {
	{ "dada.03a",     0x080000, 0xfc6f2dd7, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "dada.04a",     0x080000, 0xd4be4009, 1 | BRF_ESS | BRF_PRG },
	{ "dada.05a",     0x080000, 0x6712d1cf, 1 | BRF_ESS | BRF_PRG },
	{ "dad.06",       0x080000, 0x13aa3e56, 1 | BRF_ESS | BRF_PRG },
	{ "dad.07",       0x080000, 0x431cb6dd, 1 | BRF_ESS | BRF_PRG },

	{ "dad.13m",      0x200000, 0xda3cb7d6, 3 | BRF_GRA },
	{ "dad.15m",      0x200000, 0x92b63172, 3 | BRF_GRA },
	{ "dad.17m",      0x200000, 0xb98757f5, 3 | BRF_GRA },
	{ "dad.19m",      0x200000, 0x8121ce46, 3 | BRF_GRA },
	{ "dad.14m",      0x100000, 0x837e6f3f, 3 | BRF_GRA },
	{ "dad.16m",      0x100000, 0xf0916bdb, 3 | BRF_GRA },
	{ "dad.18m",      0x100000, 0xcef393ef, 3 | BRF_GRA },
	{ "dad.20m",      0x100000, 0x8953fe9e, 3 | BRF_GRA },

	{ "dad.01",       0x020000, 0x3f5e2424, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "dad.11m",      0x200000, 0x0c499b67, 5 | BRF_SND },
	{ "dad.12m",      0x200000, 0x2f0b5a4e, 5 | BRF_SND },
};

STD_ROM_PICK(Ddtoda) STD_ROM_FN(Ddtoda)

struct BurnDriver BurnDrvCpsDdtoda = {
	"ddtoda", "ddtod", NULL, "1994",
	"Dungeons & Dragons: Tower of Doom (Asia 940113)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,4,HARDWARE_CAPCOM_CPS2,
	NULL, DdtodaRomInfo, DdtodaRomName, ddsomInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Dungeons & Dragons: Tower of Doom (Hispanic 940412)

static struct BurnRomInfo DdtodhRomDesc[] = {
	{ "dadh.03c",     0x080000, 0x5750a861, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "dadh.04c",     0x080000, 0xcfbf1b56, 1 | BRF_ESS | BRF_PRG },
	{ "dadh.05c",     0x080000, 0xa6e562ba, 1 | BRF_ESS | BRF_PRG },
	{ "dad.06a",      0x080000, 0x6225495a, 1 | BRF_ESS | BRF_PRG },
	{ "dad.07a",      0x080000, 0xb3480ec3, 1 | BRF_ESS | BRF_PRG },

	{ "dad.13m",      0x200000, 0xda3cb7d6, 3 | BRF_GRA },
	{ "dad.15m",      0x200000, 0x92b63172, 3 | BRF_GRA },
	{ "dad.17m",      0x200000, 0xb98757f5, 3 | BRF_GRA },
	{ "dad.19m",      0x200000, 0x8121ce46, 3 | BRF_GRA },
	{ "dad.14m",      0x100000, 0x837e6f3f, 3 | BRF_GRA },
	{ "dad.16m",      0x100000, 0xf0916bdb, 3 | BRF_GRA },
	{ "dad.18m",      0x100000, 0xcef393ef, 3 | BRF_GRA },
	{ "dad.20m",      0x100000, 0x8953fe9e, 3 | BRF_GRA },

	{ "dad.01",       0x020000, 0x3f5e2424, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "dad.11m",      0x200000, 0x0c499b67, 5 | BRF_SND },
	{ "dad.12m",      0x200000, 0x2f0b5a4e, 5 | BRF_SND },
};

STD_ROM_PICK(Ddtodh) STD_ROM_FN(Ddtodh)

struct BurnDriver BurnDrvCpsDdtodh = {
	"ddtodh", "ddtod", NULL, "1994",
	"Dungeons & Dragons: Tower of Doom (Hispanic 940412)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,4,HARDWARE_CAPCOM_CPS2,
	NULL, DdtodhRomInfo, DdtodhRomName, ddsomInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};



// Dungeons & Dragons: Tower of Doom (Hispanic 940125)

static struct BurnRomInfo Ddtodhr1RomDesc[] = {
	{ "dadh.03b",     0x080000, 0xae0cb98e, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "dadh.04b",     0x080000, 0xb5774363, 1 | BRF_ESS | BRF_PRG },
	{ "dadh.05b",     0x080000, 0x6ce2a485, 1 | BRF_ESS | BRF_PRG },
	{ "dad.06",       0x080000, 0x13aa3e56, 1 | BRF_ESS | BRF_PRG },
	{ "dad.07",       0x080000, 0x431cb6dd, 1 | BRF_ESS | BRF_PRG },

	{ "dad.13m",      0x200000, 0xda3cb7d6, 3 | BRF_GRA },
	{ "dad.15m",      0x200000, 0x92b63172, 3 | BRF_GRA },
	{ "dad.17m",      0x200000, 0xb98757f5, 3 | BRF_GRA },
	{ "dad.19m",      0x200000, 0x8121ce46, 3 | BRF_GRA },
	{ "dad.14m",      0x100000, 0x837e6f3f, 3 | BRF_GRA },
	{ "dad.16m",      0x100000, 0xf0916bdb, 3 | BRF_GRA },
	{ "dad.18m",      0x100000, 0xcef393ef, 3 | BRF_GRA },
	{ "dad.20m",      0x100000, 0x8953fe9e, 3 | BRF_GRA },

	{ "dad.01",       0x020000, 0x3f5e2424, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "dad.11m",      0x200000, 0x0c499b67, 5 | BRF_SND },
	{ "dad.12m",      0x200000, 0x2f0b5a4e, 5 | BRF_SND },
};

STD_ROM_PICK(Ddtodhr1) STD_ROM_FN(Ddtodhr1)

struct BurnDriver BurnDrvCpsDdtodhr1 = {
	"ddtodhr1", "ddtod", NULL, "1994",
	"Dungeons & Dragons: Tower of Doom (Hispanic 940125)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,4,HARDWARE_CAPCOM_CPS2,
	NULL, Ddtodhr1RomInfo, Ddtodhr1RomName, ddsomInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Dungeons & Dragons: Tower of Doom (Euro 940412, Phoenix Edition)

static struct BurnRomInfo DdtoddRomDesc[] = {
	{ "daded.03c",     0x80000, 0x843330f4, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "daded.04c",     0x80000, 0x306f14fc, 1 | BRF_ESS | BRF_PRG },
	{ "daded.05c",     0x80000, 0x8c6b8328, 1 | BRF_ESS | BRF_PRG },
	{ "dad.06a",       0x80000, 0x6225495a, 1 | BRF_ESS | BRF_PRG },
	{ "dadd.07a",      0x80000, 0x0f0df6cc, 1 | BRF_ESS | BRF_PRG },

	{ "dad.13m",      0x200000, 0xda3cb7d6, 3 | BRF_GRA },
	{ "dad.15m",      0x200000, 0x92b63172, 3 | BRF_GRA },
	{ "dad.17m",      0x200000, 0xb98757f5, 3 | BRF_GRA },
	{ "dad.19m",      0x200000, 0x8121ce46, 3 | BRF_GRA },
	{ "dad.14m",      0x100000, 0x837e6f3f, 3 | BRF_GRA },
	{ "dad.16m",      0x100000, 0xf0916bdb, 3 | BRF_GRA },
	{ "dad.18m",      0x100000, 0xcef393ef, 3 | BRF_GRA },
	{ "dad.20m",      0x100000, 0x8953fe9e, 3 | BRF_GRA },

	{ "dad.01",       0x020000, 0x3f5e2424, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "dad.11m",      0x200000, 0x0c499b67, 5 | BRF_SND },
	{ "dad.12m",      0x200000, 0x2f0b5a4e, 5 | BRF_SND },
};

STD_ROM_PICK(Ddtodd) STD_ROM_FN(Ddtodd)

struct BurnDriver BurnDrvCpsDdtodd = {
	"ddtodd", "ddtod", NULL, "1994",
	"Dungeons & Dragons: Tower of Doom (Euro 940412, Phoenix Edition)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE | BDF_BOOTLEG,4,HARDWARE_CAPCOM_CPS2,
	NULL, DdtoddRomInfo, DdtoddRomName, ddsomInputInfo, NULL,
	PhoenixInit, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Dungeons & Dragons: Shadow over Mystara (Euro 960619)

static struct BurnRomInfo DdsomRomDesc[] = {
	{ "dd2e.03e",     0x080000, 0x449361AF, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "dd2e.04e",     0x080000, 0x5B7052B6, 1 | BRF_ESS | BRF_PRG },
	{ "dd2e.05e",     0x080000, 0x788D5F60, 1 | BRF_ESS | BRF_PRG },
	{ "dd2e.06e",     0x080000, 0xE0807E1E, 1 | BRF_ESS | BRF_PRG },
	{ "dd2e.07",      0x080000, 0xbb777a02, 1 | BRF_ESS | BRF_PRG },
	{ "dd2e.08",      0x080000, 0x30970890, 1 | BRF_ESS | BRF_PRG },
	{ "dd2e.09",      0x080000, 0x99e2194d, 1 | BRF_ESS | BRF_PRG },
	{ "dd2e.10",      0x080000, 0xe198805e, 1 | BRF_ESS | BRF_PRG },

	{ "dd2.13m",      0x400000, 0xa46b4e6e, 3 | BRF_GRA },
	{ "dd2.15m",      0x400000, 0xd5fc50fc, 3 | BRF_GRA },
	{ "dd2.17m",      0x400000, 0x837c0867, 3 | BRF_GRA },
	{ "dd2.19m",      0x400000, 0xbb0ec21c, 3 | BRF_GRA },
	{ "dd2.14m",      0x200000, 0x6d824ce2, 3 | BRF_GRA },
	{ "dd2.16m",      0x200000, 0x79682ae5, 3 | BRF_GRA },
	{ "dd2.18m",      0x200000, 0xacddd149, 3 | BRF_GRA },
	{ "dd2.20m",      0x200000, 0x117fb0c0, 3 | BRF_GRA },

	{ "dd2.01",       0x020000, 0x99d657e5, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "dd2.02",       0x020000, 0x117a3824, 4 | BRF_ESS | BRF_PRG },

	{ "dd2.11m",      0x200000, 0x98d0c325, 5 | BRF_SND },
	{ "dd2.12m",      0x200000, 0x5ea2e7fa, 5 | BRF_SND },
};

STD_ROM_PICK(Ddsom) STD_ROM_FN(Ddsom)

struct BurnDriver BurnDrvCpsDdsom = {
	"ddsom", NULL, NULL, "1996",
	"Dungeons & Dragons: Shadow over Mystara (Euro 960619)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING,4,HARDWARE_CAPCOM_CPS2,
	NULL, DdsomRomInfo, DdsomRomName, ddsomInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Dungeons & Dragons: Shadow over Mystara (Euro 960223)

static struct BurnRomInfo Ddsomr1RomDesc[] = {
	{ "dd2e.03d",     0x080000, 0x6c084ab5, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "dd2e.04d",     0x080000, 0x9b94a947, 1 | BRF_ESS | BRF_PRG },
	{ "dd2e.05d",     0x080000, 0x5d6a63c6, 1 | BRF_ESS | BRF_PRG },
	{ "dd2e.06d",     0x080000, 0x31bde8ee, 1 | BRF_ESS | BRF_PRG },
	{ "dd2e.07",      0x080000, 0xbb777a02, 1 | BRF_ESS | BRF_PRG },
	{ "dd2e.08",      0x080000, 0x30970890, 1 | BRF_ESS | BRF_PRG },
	{ "dd2e.09",      0x080000, 0x99e2194d, 1 | BRF_ESS | BRF_PRG },
	{ "dd2e.10",      0x080000, 0xe198805e, 1 | BRF_ESS | BRF_PRG },

	{ "dd2.13m",      0x400000, 0xa46b4e6e, 3 | BRF_GRA },
	{ "dd2.15m",      0x400000, 0xd5fc50fc, 3 | BRF_GRA },
	{ "dd2.17m",      0x400000, 0x837c0867, 3 | BRF_GRA },
	{ "dd2.19m",      0x400000, 0xbb0ec21c, 3 | BRF_GRA },
	{ "dd2.14m",      0x200000, 0x6d824ce2, 3 | BRF_GRA },
	{ "dd2.16m",      0x200000, 0x79682ae5, 3 | BRF_GRA },
	{ "dd2.18m",      0x200000, 0xacddd149, 3 | BRF_GRA },
	{ "dd2.20m",      0x200000, 0x117fb0c0, 3 | BRF_GRA },

	{ "dd2.01",       0x020000, 0x99d657e5, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "dd2.02",       0x020000, 0x117a3824, 4 | BRF_ESS | BRF_PRG },

	{ "dd2.11m",      0x200000, 0x98d0c325, 5 | BRF_SND },
	{ "dd2.12m",      0x200000, 0x5ea2e7fa, 5 | BRF_SND },
};

STD_ROM_PICK(Ddsomr1) STD_ROM_FN(Ddsomr1)

struct BurnDriver BurnDrvCpsDdsomr1 = {
	"ddsomr1", "ddsom", NULL, "1996",
	"Dungeons & Dragons: Shadow over Mystara (Euro 960223)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,4,HARDWARE_CAPCOM_CPS2,
	NULL, Ddsomr1RomInfo, Ddsomr1RomName, ddsomInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Dungeons & Dragons: Shadow over Mystara (Euro 960209)

static struct BurnRomInfo Ddsomr2RomDesc[] = {
	{ "dd2e.03b",     0x080000, 0xcd2deb66, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "dd2e.04b",     0x080000, 0xbfee43cc, 1 | BRF_ESS | BRF_PRG },
	{ "dd2e.05b",     0x080000, 0x049ab19d, 1 | BRF_ESS | BRF_PRG },
	{ "dd2e.06d",     0x080000, 0x3994fb8b, 1 | BRF_ESS | BRF_PRG },
	{ "dd2e.07",      0x080000, 0xbb777a02, 1 | BRF_ESS | BRF_PRG },
	{ "dd2e.08",      0x080000, 0x30970890, 1 | BRF_ESS | BRF_PRG },
	{ "dd2e.09",      0x080000, 0x99e2194d, 1 | BRF_ESS | BRF_PRG },
	{ "dd2e.10",      0x080000, 0xe198805e, 1 | BRF_ESS | BRF_PRG },

	{ "dd2.13m",      0x400000, 0xa46b4e6e, 3 | BRF_GRA },
	{ "dd2.15m",      0x400000, 0xd5fc50fc, 3 | BRF_GRA },
	{ "dd2.17m",      0x400000, 0x837c0867, 3 | BRF_GRA },
	{ "dd2.19m",      0x400000, 0xbb0ec21c, 3 | BRF_GRA },
	{ "dd2.14m",      0x200000, 0x6d824ce2, 3 | BRF_GRA },
	{ "dd2.16m",      0x200000, 0x79682ae5, 3 | BRF_GRA },
	{ "dd2.18m",      0x200000, 0xacddd149, 3 | BRF_GRA },
	{ "dd2.20m",      0x200000, 0x117fb0c0, 3 | BRF_GRA },

	{ "dd2.01",       0x020000, 0x99d657e5, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "dd2.02",       0x020000, 0x117a3824, 4 | BRF_ESS | BRF_PRG },

	{ "dd2.11m",      0x200000, 0x98d0c325, 5 | BRF_SND },
	{ "dd2.12m",      0x200000, 0x5ea2e7fa, 5 | BRF_SND },
};

STD_ROM_PICK(Ddsomr2) STD_ROM_FN(Ddsomr2)

struct BurnDriver BurnDrvCpsDdsomr2 = {
	"ddsomr2", "ddsom", NULL, "1996",
	"Dungeons & Dragons: Shadow over Mystara (Euro 960209)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,4,HARDWARE_CAPCOM_CPS2,
	NULL, Ddsomr2RomInfo, Ddsomr2RomName, ddsomInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Dungeons & Dragons: Shadow over Mystara (Euro 960208)

static struct BurnRomInfo ddsomr3RomDesc[] = {
	{ "dd2e.03a",     0x080000, 0x6de67678, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "dd2e.04a",     0x080000, 0x0e45739a, 1 | BRF_ESS | BRF_PRG },
	{ "dd2e.05a",     0x080000, 0x3dce8025, 1 | BRF_ESS | BRF_PRG },
	{ "dd2e.06a",     0x080000, 0x51bafbef, 1 | BRF_ESS | BRF_PRG },
	{ "dd2e.07",      0x080000, 0xbb777a02, 1 | BRF_ESS | BRF_PRG },
	{ "dd2e.08",      0x080000, 0x30970890, 1 | BRF_ESS | BRF_PRG },
	{ "dd2e.09",      0x080000, 0x99e2194d, 1 | BRF_ESS | BRF_PRG },
	{ "dd2e.10",      0x080000, 0xe198805e, 1 | BRF_ESS | BRF_PRG },

	{ "dd2.13m",      0x400000, 0xa46b4e6e, 3 | BRF_GRA },
	{ "dd2.15m",      0x400000, 0xd5fc50fc, 3 | BRF_GRA },
	{ "dd2.17m",      0x400000, 0x837c0867, 3 | BRF_GRA },
	{ "dd2.19m",      0x400000, 0xbb0ec21c, 3 | BRF_GRA },
	{ "dd2.14m",      0x200000, 0x6d824ce2, 3 | BRF_GRA },
	{ "dd2.16m",      0x200000, 0x79682ae5, 3 | BRF_GRA },
	{ "dd2.18m",      0x200000, 0xacddd149, 3 | BRF_GRA },
	{ "dd2.20m",      0x200000, 0x117fb0c0, 3 | BRF_GRA },

	{ "dd2.01",       0x020000, 0x99d657e5, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "dd2.02",       0x020000, 0x117a3824, 4 | BRF_ESS | BRF_PRG },

	{ "dd2.11m",      0x200000, 0x98d0c325, 5 | BRF_SND },
	{ "dd2.12m",      0x200000, 0x5ea2e7fa, 5 | BRF_SND },
};

STD_ROM_PICK(ddsomr3) STD_ROM_FN(ddsomr3)

struct BurnDriver BurnDrvCpsddsomr3 = {
	"ddsomr3", "ddsom", NULL, "1996",
	"Dungeons & Dragons: Shadow over Mystara (Euro 960208)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,4,HARDWARE_CAPCOM_CPS2,
	NULL, ddsomr3RomInfo, ddsomr3RomName, ddsomInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Dungeons & Dragons: Shadow over Mystara (USA 960619)

static struct BurnRomInfo DdsomuRomDesc[] = {
	{ "dd2u.03g",     0x080000, 0xfb089b39, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "dd2u.04g",     0x080000, 0xcd432b73, 1 | BRF_ESS | BRF_PRG },
	{ "dd2.05g",      0x080000, 0x5eb1991c, 1 | BRF_ESS | BRF_PRG },
	{ "dd2.06g",      0x080000, 0xc26b5e55, 1 | BRF_ESS | BRF_PRG },
	{ "dd2.07",       0x080000, 0x909a0b8b, 1 | BRF_ESS | BRF_PRG },
	{ "dd2.08",       0x080000, 0xe53c4d01, 1 | BRF_ESS | BRF_PRG },
	{ "dd2.09",       0x080000, 0x5f86279f, 1 | BRF_ESS | BRF_PRG },
	{ "dd2.10",       0x080000, 0xad954c26, 1 | BRF_ESS | BRF_PRG },

	{ "dd2.13m",      0x400000, 0xa46b4e6e, 3 | BRF_GRA },
	{ "dd2.15m",      0x400000, 0xd5fc50fc, 3 | BRF_GRA },
	{ "dd2.17m",      0x400000, 0x837c0867, 3 | BRF_GRA },
	{ "dd2.19m",      0x400000, 0xbb0ec21c, 3 | BRF_GRA },
	{ "dd2.14m",      0x200000, 0x6d824ce2, 3 | BRF_GRA },
	{ "dd2.16m",      0x200000, 0x79682ae5, 3 | BRF_GRA },
	{ "dd2.18m",      0x200000, 0xacddd149, 3 | BRF_GRA },
	{ "dd2.20m",      0x200000, 0x117fb0c0, 3 | BRF_GRA },

	{ "dd2.01",       0x020000, 0x99d657e5, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "dd2.02",       0x020000, 0x117a3824, 4 | BRF_ESS | BRF_PRG },

	{ "dd2.11m",      0x200000, 0x98d0c325, 5 | BRF_SND },
	{ "dd2.12m",      0x200000, 0x5ea2e7fa, 5 | BRF_SND },
};

STD_ROM_PICK(Ddsomu) STD_ROM_FN(Ddsomu)

struct BurnDriver BurnDrvCpsDdsomu = {
	"ddsomu", "ddsom", NULL, "1996",
	"Dungeons & Dragons: Shadow over Mystara (USA 960619)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,4,HARDWARE_CAPCOM_CPS2,
	NULL, DdsomuRomInfo, DdsomuRomName, ddsomInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Dungeons & Dragons: Shadow over Mystara (USA 960209)

static struct BurnRomInfo Ddsomur1RomDesc[] = {
	{ "dd2u.03d",     0x080000, 0x0f700d84, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "dd2u.04d",     0x080000, 0xb99eb254, 1 | BRF_ESS | BRF_PRG },
	{ "dd2.05d",      0x080000, 0xb23061f3, 1 | BRF_ESS | BRF_PRG },
	{ "dd2.06d",      0x080000, 0x8bf1d8ce, 1 | BRF_ESS | BRF_PRG },
	{ "dd2.07",       0x080000, 0x909a0b8b, 1 | BRF_ESS | BRF_PRG },
	{ "dd2.08",       0x080000, 0xe53c4d01, 1 | BRF_ESS | BRF_PRG },
	{ "dd2.09",       0x080000, 0x5f86279f, 1 | BRF_ESS | BRF_PRG },
	{ "dd2.10",       0x080000, 0xad954c26, 1 | BRF_ESS | BRF_PRG },

	{ "dd2.13m",      0x400000, 0xa46b4e6e, 3 | BRF_GRA },
	{ "dd2.15m",      0x400000, 0xd5fc50fc, 3 | BRF_GRA },
	{ "dd2.17m",      0x400000, 0x837c0867, 3 | BRF_GRA },
	{ "dd2.19m",      0x400000, 0xbb0ec21c, 3 | BRF_GRA },
	{ "dd2.14m",      0x200000, 0x6d824ce2, 3 | BRF_GRA },
	{ "dd2.16m",      0x200000, 0x79682ae5, 3 | BRF_GRA },
	{ "dd2.18m",      0x200000, 0xacddd149, 3 | BRF_GRA },
	{ "dd2.20m",      0x200000, 0x117fb0c0, 3 | BRF_GRA },

	{ "dd2.01",       0x020000, 0x99d657e5, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "dd2.02",       0x020000, 0x117a3824, 4 | BRF_ESS | BRF_PRG },

	{ "dd2.11m",      0x200000, 0x98d0c325, 5 | BRF_SND },
	{ "dd2.12m",      0x200000, 0x5ea2e7fa, 5 | BRF_SND },
};

STD_ROM_PICK(Ddsomur1) STD_ROM_FN(Ddsomur1)

struct BurnDriver BurnDrvCpsDdsomur1 = {
	"ddsomur1", "ddsom", NULL, "1996",
	"Dungeons & Dragons: Shadow over Mystara (USA 960209)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,4,HARDWARE_CAPCOM_CPS2,
	NULL, Ddsomur1RomInfo, Ddsomur1RomName, ddsomInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Dungeons & Dragons: Shadow over Mystara (Japan 960619)

static struct BurnRomInfo DdsomjRomDesc[] = {
	{ "dd2j.03g",     0x080000, 0xe6c8c985, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "dd2j.04g",     0x080000, 0x8386c0bd, 1 | BRF_ESS | BRF_PRG },
	{ "dd2.05g",      0x080000, 0x5eb1991c, 1 | BRF_ESS | BRF_PRG },
	{ "dd2.06g",      0x080000, 0xc26b5e55, 1 | BRF_ESS | BRF_PRG },
	{ "dd2.07",       0x080000, 0x909a0b8b, 1 | BRF_ESS | BRF_PRG },
	{ "dd2.08",       0x080000, 0xe53c4d01, 1 | BRF_ESS | BRF_PRG },
	{ "dd2.09",       0x080000, 0x5f86279f, 1 | BRF_ESS | BRF_PRG },
	{ "dd2.10",       0x080000, 0xad954c26, 1 | BRF_ESS | BRF_PRG },

	{ "dd2.13m",      0x400000, 0xa46b4e6e, 3 | BRF_GRA },
	{ "dd2.15m",      0x400000, 0xd5fc50fc, 3 | BRF_GRA },
	{ "dd2.17m",      0x400000, 0x837c0867, 3 | BRF_GRA },
	{ "dd2.19m",      0x400000, 0xbb0ec21c, 3 | BRF_GRA },
	{ "dd2.14m",      0x200000, 0x6d824ce2, 3 | BRF_GRA },
	{ "dd2.16m",      0x200000, 0x79682ae5, 3 | BRF_GRA },
	{ "dd2.18m",      0x200000, 0xacddd149, 3 | BRF_GRA },
	{ "dd2.20m",      0x200000, 0x117fb0c0, 3 | BRF_GRA },

	{ "dd2.01",       0x020000, 0x99d657e5, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "dd2.02",       0x020000, 0x117a3824, 4 | BRF_ESS | BRF_PRG },

	{ "dd2.11m",      0x200000, 0x98d0c325, 5 | BRF_SND },
	{ "dd2.12m",      0x200000, 0x5ea2e7fa, 5 | BRF_SND },
};

STD_ROM_PICK(Ddsomj) STD_ROM_FN(Ddsomj)

struct BurnDriver BurnDrvCpsDdsomj = {
	"ddsomj", "ddsom", NULL, "1996",
	"Dungeons & Dragons: Shadow over Mystara (Japan 960619)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,4,HARDWARE_CAPCOM_CPS2,
	NULL, DdsomjRomInfo, DdsomjRomName, ddsomInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Dungeons & Dragons: Shadow over Mystara (Japan 960206)

static struct BurnRomInfo Ddsomjr1RomDesc[] = {
	{ "dd2j.03b",     0x080000, 0x965d74e5, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "dd2j.04b",     0x080000, 0x958eb8f3, 1 | BRF_ESS | BRF_PRG },
	{ "dd2.05b",      0x080000, 0xd38571ca, 1 | BRF_ESS | BRF_PRG },
	{ "dd2.06b",      0x080000, 0x6d5a3bbb, 1 | BRF_ESS | BRF_PRG },
	{ "dd2.07",       0x080000, 0x909a0b8b, 1 | BRF_ESS | BRF_PRG },
	{ "dd2.08",       0x080000, 0xe53c4d01, 1 | BRF_ESS | BRF_PRG },
	{ "dd2.09",       0x080000, 0x5f86279f, 1 | BRF_ESS | BRF_PRG },
	{ "dd2.10",       0x080000, 0xad954c26, 1 | BRF_ESS | BRF_PRG },

	{ "dd2.13m",      0x400000, 0xa46b4e6e, 3 | BRF_GRA },
	{ "dd2.15m",      0x400000, 0xd5fc50fc, 3 | BRF_GRA },
	{ "dd2.17m",      0x400000, 0x837c0867, 3 | BRF_GRA },
	{ "dd2.19m",      0x400000, 0xbb0ec21c, 3 | BRF_GRA },
	{ "dd2.14m",      0x200000, 0x6d824ce2, 3 | BRF_GRA },
	{ "dd2.16m",      0x200000, 0x79682ae5, 3 | BRF_GRA },
	{ "dd2.18m",      0x200000, 0xacddd149, 3 | BRF_GRA },
	{ "dd2.20m",      0x200000, 0x117fb0c0, 3 | BRF_GRA },

	{ "dd2.01",       0x020000, 0x99d657e5, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "dd2.02",       0x020000, 0x117a3824, 4 | BRF_ESS | BRF_PRG },

	{ "dd2.11m",      0x200000, 0x98d0c325, 5 | BRF_SND },
	{ "dd2.12m",      0x200000, 0x5ea2e7fa, 5 | BRF_SND },
};

STD_ROM_PICK(Ddsomjr1) STD_ROM_FN(Ddsomjr1)

struct BurnDriver BurnDrvCpsDdsomjr1 = {
	"ddsomjr1", "ddsom", NULL, "1996",
	"Dungeons & Dragons: Shadow over Mystara (Japan 960206)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,4,HARDWARE_CAPCOM_CPS2,
	NULL, Ddsomjr1RomInfo, Ddsomjr1RomName, ddsomInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Dungeons & Dragons: Shadow over Mystara (Asia 960619)

static struct BurnRomInfo DdsomaRomDesc[] = {
	{ "dd2a.03g",     0x080000, 0x0b4fec22, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "dd2a.04g",     0x080000, 0x055b7019, 1 | BRF_ESS | BRF_PRG },
	{ "dd2.05g",      0x080000, 0x5eb1991c, 1 | BRF_ESS | BRF_PRG },
	{ "dd2.06g",      0x080000, 0xc26b5e55, 1 | BRF_ESS | BRF_PRG },
	{ "dd2.07",       0x080000, 0x909a0b8b, 1 | BRF_ESS | BRF_PRG },
	{ "dd2.08",       0x080000, 0xe53c4d01, 1 | BRF_ESS | BRF_PRG },
	{ "dd2.09",       0x080000, 0x5f86279f, 1 | BRF_ESS | BRF_PRG },
	{ "dd2.10",       0x080000, 0xad954c26, 1 | BRF_ESS | BRF_PRG },

	{ "dd2.13m",      0x400000, 0xa46b4e6e, 3 | BRF_GRA },
	{ "dd2.15m",      0x400000, 0xd5fc50fc, 3 | BRF_GRA },
	{ "dd2.17m",      0x400000, 0x837c0867, 3 | BRF_GRA },
	{ "dd2.19m",      0x400000, 0xbb0ec21c, 3 | BRF_GRA },
	{ "dd2.14m",      0x200000, 0x6d824ce2, 3 | BRF_GRA },
	{ "dd2.16m",      0x200000, 0x79682ae5, 3 | BRF_GRA },
	{ "dd2.18m",      0x200000, 0xacddd149, 3 | BRF_GRA },
	{ "dd2.20m",      0x200000, 0x117fb0c0, 3 | BRF_GRA },

	{ "dd2.01",       0x020000, 0x99d657e5, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "dd2.02",       0x020000, 0x117a3824, 4 | BRF_ESS | BRF_PRG },

	{ "dd2.11m",      0x200000, 0x98d0c325, 5 | BRF_SND },
	{ "dd2.12m",      0x200000, 0x5ea2e7fa, 5 | BRF_SND },
};

STD_ROM_PICK(Ddsoma) STD_ROM_FN(Ddsoma)

struct BurnDriver BurnDrvCpsDdsoma = {
	"ddsoma", "ddsom", NULL, "1996",
	"Dungeons & Dragons: Shadow over Mystara (Asia 960619)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,4,HARDWARE_CAPCOM_CPS2,
	NULL, DdsomaRomInfo, DdsomaRomName, ddsomInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Dungeons & Dragons: Shadow over Mystara (Hispanic 960223)

static struct BurnRomInfo ddsomhRomDesc[] = {
	{ "dd2h.03a",     0x080000, 0xe472c9f3, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "dd2h.04a",     0x080000, 0x315a7706, 1 | BRF_ESS | BRF_PRG },
	{ "dd2h.05a",     0x080000, 0x9b2534eb, 1 | BRF_ESS | BRF_PRG },
	{ "dd2h.06a",     0x080000, 0x3b21ba59, 1 | BRF_ESS | BRF_PRG },
	{ "dd2h.07a",     0x080000, 0xfce2558d, 1 | BRF_ESS | BRF_PRG },
	{ "dd2e.08",      0x080000, 0x30970890, 1 | BRF_ESS | BRF_PRG },
	{ "dd2e.09",      0x080000, 0x99e2194d, 1 | BRF_ESS | BRF_PRG },
	{ "dd2e.10",      0x080000, 0xe198805e, 1 | BRF_ESS | BRF_PRG },

	{ "dd2.13m",      0x400000, 0xa46b4e6e, 3 | BRF_GRA },
	{ "dd2.15m",      0x400000, 0xd5fc50fc, 3 | BRF_GRA },
	{ "dd2.17m",      0x400000, 0x837c0867, 3 | BRF_GRA },
	{ "dd2.19m",      0x400000, 0xbb0ec21c, 3 | BRF_GRA },
	{ "dd2.14m",      0x200000, 0x6d824ce2, 3 | BRF_GRA },
	{ "dd2.16m",      0x200000, 0x79682ae5, 3 | BRF_GRA },
	{ "dd2.18m",      0x200000, 0xacddd149, 3 | BRF_GRA },
	{ "dd2.20m",      0x200000, 0x117fb0c0, 3 | BRF_GRA },

	{ "dd2.01",       0x020000, 0x99d657e5, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "dd2.02",       0x020000, 0x117a3824, 4 | BRF_ESS | BRF_PRG },

	{ "dd2.11m",      0x200000, 0x98d0c325, 5 | BRF_SND },
	{ "dd2.12m",      0x200000, 0x5ea2e7fa, 5 | BRF_SND },
};

STD_ROM_PICK(ddsomh) STD_ROM_FN(ddsomh)

struct BurnDriver BurnDrvCpsddsomh = {
	"ddsomh", "ddsom", NULL, "1996",
	"Dungeons & Dragons: Shadow over Mystara (Hispanic 960223)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,4,HARDWARE_CAPCOM_CPS2,
	NULL, ddsomhRomInfo, ddsomhRomName, ddsomInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Dungeons & Dragons: Shadow over Mystara (Brazil 960223)

static struct BurnRomInfo ddsombRomDesc[] = {
	{ "dd2b.03a",     0x080000, 0xe8ce7fbb, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "dd2b.04a",     0x080000, 0x6b679664, 1 | BRF_ESS | BRF_PRG },
	{ "dd2b.05a",     0x080000, 0x9b2534eb, 1 | BRF_ESS | BRF_PRG },
	{ "dd2b.06a",     0x080000, 0x3b21ba59, 1 | BRF_ESS | BRF_PRG },
	{ "dd2b.07",      0x080000, 0xfce2558d, 1 | BRF_ESS | BRF_PRG },
	{ "dd2e.08",      0x080000, 0x30970890, 1 | BRF_ESS | BRF_PRG },
	{ "dd2e.09",      0x080000, 0x99e2194d, 1 | BRF_ESS | BRF_PRG },
	{ "dd2e.10",      0x080000, 0xe198805e, 1 | BRF_ESS | BRF_PRG },

	{ "dd2.13m",      0x400000, 0xa46b4e6e, 3 | BRF_GRA },
	{ "dd2.15m",      0x400000, 0xd5fc50fc, 3 | BRF_GRA },
	{ "dd2.17m",      0x400000, 0x837c0867, 3 | BRF_GRA },
	{ "dd2.19m",      0x400000, 0xbb0ec21c, 3 | BRF_GRA },
	{ "dd2.14m",      0x200000, 0x6d824ce2, 3 | BRF_GRA },
	{ "dd2.16m",      0x200000, 0x79682ae5, 3 | BRF_GRA },
	{ "dd2.18m",      0x200000, 0xacddd149, 3 | BRF_GRA },
	{ "dd2.20m",      0x200000, 0x117fb0c0, 3 | BRF_GRA },

	{ "dd2.01",       0x020000, 0x99d657e5, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "dd2.02",       0x020000, 0x117a3824, 4 | BRF_ESS | BRF_PRG },

	{ "dd2.11m",      0x200000, 0x98d0c325, 5 | BRF_SND },
	{ "dd2.12m",      0x200000, 0x5ea2e7fa, 5 | BRF_SND },
};

STD_ROM_PICK(ddsomb) STD_ROM_FN(ddsomb)

struct BurnDriver BurnDrvCpsddsomb = {
	"ddsomb", "ddsom", NULL, "1996",
	"Dungeons & Dragons: Shadow over Mystara (Brazil 960223)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,4,HARDWARE_CAPCOM_CPS2,
	NULL, ddsombRomInfo, ddsombRomName, ddsomInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Dungeons & Dragons: Shadow over Mystara (USA 960619, Phoenix Edition)

static struct BurnRomInfo DdsomudRomDesc[] = {
	{ "dd2ud.03g",     0x80000, 0x816f695a, 1 | BRF_ESS | BRF_PRG }, // 68000 code
	{ "dd2ud.04g",     0x80000, 0x7cc81c6b, 1 | BRF_ESS | BRF_PRG },
	{ "dd2.05g",       0x80000, 0x5eb1991c, 1 | BRF_ESS | BRF_PRG },
	{ "dd2.06g",       0x80000, 0xc26b5e55, 1 | BRF_ESS | BRF_PRG },
	{ "dd2.07",        0x80000, 0x909a0b8b, 1 | BRF_ESS | BRF_PRG },
	{ "dd2.08",        0x80000, 0xe53c4d01, 1 | BRF_ESS | BRF_PRG },
	{ "dd2.09",        0x80000, 0x5f86279f, 1 | BRF_ESS | BRF_PRG },
	{ "dd2d.10",       0x80000, 0x0c172f8f, 1 | BRF_ESS | BRF_PRG },

	{ "dd2.13m",      0x400000, 0xa46b4e6e, 3 | BRF_GRA },			 // 8
	{ "dd2.15m",      0x400000, 0xd5fc50fc, 3 | BRF_GRA },
	{ "dd2.17m",      0x400000, 0x837c0867, 3 | BRF_GRA },
	{ "dd2.19m",      0x400000, 0xbb0ec21c, 3 | BRF_GRA },
	{ "dd2.14m",      0x200000, 0x6d824ce2, 3 | BRF_GRA },
	{ "dd2.16m",      0x200000, 0x79682ae5, 3 | BRF_GRA },
	{ "dd2.18m",      0x200000, 0xacddd149, 3 | BRF_GRA },
	{ "dd2.20m",      0x200000, 0x117fb0c0, 3 | BRF_GRA },

	{ "dd2.01",       0x020000, 0x99d657e5, 4 | BRF_ESS | BRF_PRG }, // 16
	{ "dd2.02",       0x020000, 0x117a3824, 4 | BRF_ESS | BRF_PRG },

	{ "dd2.11m",      0x200000, 0x98d0c325, 5 | BRF_SND },
	{ "dd2.12m",      0x200000, 0x5ea2e7fa, 5 | BRF_SND },
};

STD_ROM_PICK(Ddsomud) STD_ROM_FN(Ddsomud)

struct BurnDriver BurnDrvCpsDdsomud = {
	"ddsomud", "ddsom", NULL, "1996",
	"Dungeons & Dragons: Shadow over Mystara (USA 960619, Phoenix Edition)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE | BDF_BOOTLEG,4,HARDWARE_CAPCOM_CPS2,
	NULL, DdsomudRomInfo, DdsomudRomName, ddsomInputInfo, NULL,
	PhoenixInit, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Dungeons & Dragons: Shadow over Mystara (4 Players for kaillera)

struct BurnDriver BurnDrvCpsDdsom4p = {
	"ddsom4p", "ddsom", NULL, "1996",
	"Dungeons & Dragons: Shadow over Mystara (Euro 960619 / 4 Players for kaillera)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,4,HARDWARE_CAPCOM_CPS2,
	NULL, DdsomRomInfo, DdsomRomName, ddsomInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};

struct BurnDriver BurnDrvCpsDdsomr4p = {
	"ddsomr4p", "ddsom", "ddsomr2", "1996",
	"Dungeons & Dragons: Shadow over Mystara (Euro 960209 / 4 Players for kaillera)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,4,HARDWARE_CAPCOM_CPS2,
	NULL, Ddsomr2RomInfo, Ddsomr2RomName, ddsomInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};

struct BurnDriver BurnDrvCpsDdsomu4p = {
	"ddsomu4p", "ddsom", "ddsomu", "1996",
	"Dungeons & Dragons: Shadow over Mystara (USA 960619 / 4 Players for kaillera)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,4,HARDWARE_CAPCOM_CPS2,
	NULL, DdsomuRomInfo, DdsomuRomName, ddsomInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};

struct BurnDriver BurnDrvCpsDdsmur4p = {
	"ddsmur4p", "ddsom", "ddsomur1", "1996",
	"Dungeons & Dragons: Shadow over Mystara (USA 960209 / 4 Players for kaillera)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,4,HARDWARE_CAPCOM_CPS2,
	NULL, Ddsomur1RomInfo, Ddsomur1RomName, ddsomInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};

struct BurnDriver BurnDrvCpsDdsomj4p = {
	"ddsomj4p", "ddsom", "ddsomj", "1996",
	"Dungeons & Dragons: Shadow over Mystara (Japan 960619 / 4 Players for kaillera)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,4,HARDWARE_CAPCOM_CPS2,
	NULL, DdsomjRomInfo, DdsomjRomName, ddsomInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};

struct BurnDriver BurnDrvCpsDdsmjr4p = {
	"ddsmjr4p", "ddsom", "ddsomjr1", "1996",
	"Dungeons & Dragons: Shadow over Mystara (Japan 960206 / 4 Players for kaillera)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,4,HARDWARE_CAPCOM_CPS2,
	NULL, Ddsomjr1RomInfo, Ddsomjr1RomName, ddsomInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};

struct BurnDriver BurnDrvCpsDdsoma4p = {
	"ddsoma4p", "ddsom", "ddsoma", "1996",
	"Dungeons & Dragons: Shadow over Mystara (Asia 960619 / 4 Players for kaillera)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,4,HARDWARE_CAPCOM_CPS2,
	NULL, DdsomaRomInfo, DdsomaRomName, ddsomInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Dimahoo (Euro 000121)

static struct BurnRomInfo DimahooRomDesc[] = {
	{ "gmde.03",      0x080000, 0x968FCECD, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "gmd.04",       0x080000, 0x37485567, 1 | BRF_ESS | BRF_PRG },
	{ "gmd.05",       0x080000, 0xDA269FFB, 1 | BRF_ESS | BRF_PRG },
	{ "gmd.06",       0x080000, 0x55B483C9, 1 | BRF_ESS | BRF_PRG },

	{ "gmd.13m",      0x400000, 0x80DD19F0, 3 | BRF_GRA },
	{ "gmd.15m",      0x400000, 0xDFD93A78, 3 | BRF_GRA },
	{ "gmd.17m",      0x400000, 0x16356520, 3 | BRF_GRA },
	{ "gmd.19m",      0x400000, 0xDFC33031, 3 | BRF_GRA },

	{ "gmd.01",       0x020000, 0x3F9BC985, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "gmd.02",       0x020000, 0x3FD39DDE, 4 | BRF_ESS | BRF_PRG },

	{ "gmd.11m",      0x400000, 0x06A65542, 5 | BRF_SND },
	{ "gmd.12m",      0x400000, 0x50BC7A31, 5 | BRF_SND },
};

STD_ROM_PICK(Dimahoo) STD_ROM_FN(Dimahoo)

struct BurnDriver BurnDrvCpsDimahoo = {
	"dimahoo", NULL, NULL, "2000",
	"Dimahoo (Euro 000121)\0", NULL, "8ing / Raizing / Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_ORIENTATION_VERTICAL, 2, HARDWARE_CAPCOM_CPS2,
	NULL, DimahooRomInfo, DimahooRomName, dimahooInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,224,384,3,4
};


// Dimahoo (USA 000121)

static struct BurnRomInfo DimahoouRomDesc[] = {
	{ "gmdu.03",      0x080000, 0x43BCB15F, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "gmd.04",       0x080000, 0x37485567, 1 | BRF_ESS | BRF_PRG },
	{ "gmd.05",       0x080000, 0xDA269FFB, 1 | BRF_ESS | BRF_PRG },
	{ "gmd.06",       0x080000, 0x55B483C9, 1 | BRF_ESS | BRF_PRG },

	{ "gmd.13m",      0x400000, 0x80DD19F0, 3 | BRF_GRA },
	{ "gmd.15m",      0x400000, 0xDFD93A78, 3 | BRF_GRA },
	{ "gmd.17m",      0x400000, 0x16356520, 3 | BRF_GRA },
	{ "gmd.19m",      0x400000, 0xDFC33031, 3 | BRF_GRA },

	{ "gmd.01",       0x020000, 0x3F9BC985, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "gmd.02",       0x020000, 0x3FD39DDE, 4 | BRF_ESS | BRF_PRG },

	{ "gmd.11m",      0x400000, 0x06A65542, 5 | BRF_SND },
	{ "gmd.12m",      0x400000, 0x50BC7A31, 5 | BRF_SND },
};

STD_ROM_PICK(Dimahoou) STD_ROM_FN(Dimahoou)

struct BurnDriver BurnDrvCpsDimahoou = {
	"dimahoou", "dimahoo", NULL, "2000",
	"Dimahoo (USA 000121)\0", NULL, "8ing / Raizing / Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE | BDF_ORIENTATION_VERTICAL, 2, HARDWARE_CAPCOM_CPS2,
	NULL, DimahoouRomInfo, DimahoouRomName, dimahooInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,224,384,3,4
};


// Dimahoo (USA 000121, Phoenix Edition)

static struct BurnRomInfo DimahoudRomDesc[] = {
	{ "gmdud.03",     0x080000, 0x12888435, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "gmd.04",       0x080000, 0x37485567, 1 | BRF_ESS | BRF_PRG },
	{ "gmd.05",       0x080000, 0xDA269FFB, 1 | BRF_ESS | BRF_PRG },
	{ "gmdd.06",      0x080000, 0xD825EFDA, 1 | BRF_ESS | BRF_PRG },

	{ "gmd.13m",      0x400000, 0x80DD19F0, 3 | BRF_GRA },
	{ "gmd.15m",      0x400000, 0xDFD93A78, 3 | BRF_GRA },
	{ "gmd.17m",      0x400000, 0x16356520, 3 | BRF_GRA },
	{ "gmd.19m",      0x400000, 0xDFC33031, 3 | BRF_GRA },

	{ "gmd.01",       0x020000, 0x3F9BC985, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "gmd.02",       0x020000, 0x3FD39DDE, 4 | BRF_ESS | BRF_PRG },

	{ "gmd.11m",      0x400000, 0x06A65542, 5 | BRF_SND },
	{ "gmd.12m",      0x400000, 0x50BC7A31, 5 | BRF_SND },
};

STD_ROM_PICK(Dimahoud) STD_ROM_FN(Dimahoud)

struct BurnDriver BurnDrvCpsDimahoud = {
	"dimahoud", "dimahoo", NULL, "2000",
	"Dimahoo (USA 000121, Phoenix Edition)\0", NULL, "8ing / Raizing / Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE | BDF_ORIENTATION_VERTICAL | BDF_BOOTLEG, 2, HARDWARE_CAPCOM_CPS2,
	NULL, DimahoudRomInfo, DimahoudRomName, dimahooInputInfo, NULL,
	PhoenixInit, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,224,384,3,4
};


// Great Mahou Daisakusen (Japan 000121)

static struct BurnRomInfo gmdjRomDesc[] = {
	{ "gmdj.03",      0x080000, 0xCD6979E3, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "gmd.04",       0x080000, 0x37485567, 1 | BRF_ESS | BRF_PRG },
	{ "gmd.05",       0x080000, 0xDA269FFB, 1 | BRF_ESS | BRF_PRG },
	{ "gmd.06",       0x080000, 0x55B483C9, 1 | BRF_ESS | BRF_PRG },

	{ "gmd.13m",      0x400000, 0x80DD19F0, 3 | BRF_GRA },
	{ "gmd.15m",      0x400000, 0xDFD93A78, 3 | BRF_GRA },
	{ "gmd.17m",      0x400000, 0x16356520, 3 | BRF_GRA },
	{ "gmd.19m",      0x400000, 0xDFC33031, 3 | BRF_GRA },

	{ "gmd.01",       0x020000, 0x3F9BC985, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "gmd.02",       0x020000, 0x3FD39DDE, 4 | BRF_ESS | BRF_PRG },

	{ "gmd.11m",      0x400000, 0x06A65542, 5 | BRF_SND },
	{ "gmd.12m",      0x400000, 0x50BC7A31, 5 | BRF_SND },
};


STD_ROM_PICK(gmdj) STD_ROM_FN(gmdj)

struct BurnDriver BurnDrvCpsGreatMahouDaiJ = {
	"gmahou", "dimahoo", NULL, "2000",
	"Great Mahou Daisakusen (Japan 000121)\0", NULL, "8ing / Raizing / Capcom", "CPS2",
	L"\u30B0\u30EC\u30FC\u30C8\u9B54\u6CD5\u5927\u4F5C\u6226 (Great Mahou Daisakusen Japan 000121)\0", NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE | BDF_ORIENTATION_VERTICAL, 2, HARDWARE_CAPCOM_CPS2,
	NULL, gmdjRomInfo, gmdjRomName, dimahooInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,224,384,3,4
};


// Darkstalkers: The Night Warriors (Euro 940705)

static struct BurnRomInfo DstlkRomDesc[] = {
	{ "vame.03a",      0x080000, 0x004c9cff, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "vame.04a",      0x080000, 0xae413ff2, 1 | BRF_ESS | BRF_PRG },
	{ "vame.05a",      0x080000, 0x60678756, 1 | BRF_ESS | BRF_PRG },
	{ "vame.06a",      0x080000, 0x912870b3, 1 | BRF_ESS | BRF_PRG },
	{ "vame.07a",      0x080000, 0xdabae3e8, 1 | BRF_ESS | BRF_PRG },
	{ "vame.08a",      0x080000, 0x2c6e3077, 1 | BRF_ESS | BRF_PRG },
	{ "vame.09a",      0x080000, 0xf16db74b, 1 | BRF_ESS | BRF_PRG },
	{ "vame.10a",      0x080000, 0x701e2147, 1 | BRF_ESS | BRF_PRG },

	{ "vam.13m",       0x400000, 0xc51baf99, 3 | BRF_GRA },
	{ "vam.15m",       0x400000, 0x3ce83c77, 3 | BRF_GRA },
	{ "vam.17m",       0x400000, 0x4f2408e0, 3 | BRF_GRA },
	{ "vam.19m",       0x400000, 0x9ff60250, 3 | BRF_GRA },
	{ "vam.14m",       0x100000, 0xbd87243c, 3 | BRF_GRA },
	{ "vam.16m",       0x100000, 0xafec855f, 3 | BRF_GRA },
	{ "vam.18m",       0x100000, 0x3a033625, 3 | BRF_GRA },
	{ "vam.20m",       0x100000, 0x2bff6a89, 3 | BRF_GRA },

	{ "vam.01",        0x020000, 0x64b685d5, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "vam.02",        0x020000, 0xcf7c97c7, 4 | BRF_ESS | BRF_PRG },

	{ "vam.11m",       0x200000, 0x4a39deb2, 5 | BRF_SND },
	{ "vam.12m",       0x200000, 0x1a3e5c03, 5 | BRF_SND },

};

STD_ROM_PICK(Dstlk) STD_ROM_FN(Dstlk)

struct BurnDriver BurnDrvCpsDstlk = {
	"dstlk", NULL, NULL, "1994",
	"Darkstalkers: The Night Warriors (Euro 940705)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING,2,HARDWARE_CAPCOM_CPS2,
	NULL, DstlkRomInfo, DstlkRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Darkstalkers: The Night Warriors (USA 940818)

static struct BurnRomInfo DstlkuRomDesc[] = {
	{ "vamu.03b",      0x080000, 0x68a6343f, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "vamu.04b",      0x080000, 0x58161453, 1 | BRF_ESS | BRF_PRG },
	{ "vamu.05b",      0x080000, 0xdfc038b8, 1 | BRF_ESS | BRF_PRG },
	{ "vamu.06b",      0x080000, 0xc3842c89, 1 | BRF_ESS | BRF_PRG },
	{ "vamu.07b",      0x080000, 0x25b60b6e, 1 | BRF_ESS | BRF_PRG },
	{ "vamu.08b",      0x080000, 0x2113c596, 1 | BRF_ESS | BRF_PRG },
	{ "vamu.09b",      0x080000, 0x2d1e9ae5, 1 | BRF_ESS | BRF_PRG },
	{ "vamu.10b",      0x080000, 0x81145622, 1 | BRF_ESS | BRF_PRG },

	{ "vam.13m",       0x400000, 0xc51baf99, 3 | BRF_GRA },
	{ "vam.15m",       0x400000, 0x3ce83c77, 3 | BRF_GRA },
	{ "vam.17m",       0x400000, 0x4f2408e0, 3 | BRF_GRA },
	{ "vam.19m",       0x400000, 0x9ff60250, 3 | BRF_GRA },
	{ "vam.14m",       0x100000, 0xbd87243c, 3 | BRF_GRA },
	{ "vam.16m",       0x100000, 0xafec855f, 3 | BRF_GRA },
	{ "vam.18m",       0x100000, 0x3a033625, 3 | BRF_GRA },
	{ "vam.20m",       0x100000, 0x2bff6a89, 3 | BRF_GRA },

	{ "vam.01",        0x020000, 0x64b685d5, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "vam.02",        0x020000, 0xcf7c97c7, 4 | BRF_ESS | BRF_PRG },

	{ "vam.11m",       0x200000, 0x4a39deb2, 5 | BRF_SND },
	{ "vam.12m",       0x200000, 0x1a3e5c03, 5 | BRF_SND },

};

STD_ROM_PICK(Dstlku) STD_ROM_FN(Dstlku)

struct BurnDriver BurnDrvCpsDstlku = {
	"dstlku", "dstlk", NULL, "1994",
	"Darkstalkers: The Night Warriors (USA 940818)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, DstlkuRomInfo, DstlkuRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Darkstalkers: The Night Warriors (USA 940705)

static struct BurnRomInfo Dstlkur1RomDesc[] = {
	{ "vamu.03a",      0x080000, 0x628899f9, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "vamu.04a",      0x080000, 0x696d9b25, 1 | BRF_ESS | BRF_PRG },
	{ "vamu.05a",      0x080000, 0x673ed50a, 1 | BRF_ESS | BRF_PRG },
	{ "vamu.06a",      0x080000, 0xf2377be7, 1 | BRF_ESS | BRF_PRG },
	{ "vamu.07a",      0x080000, 0xd8f498c4, 1 | BRF_ESS | BRF_PRG },
	{ "vamu.08a",      0x080000, 0xe6a8a1a0, 1 | BRF_ESS | BRF_PRG },
	{ "vamu.09a",      0x080000, 0x8dd55b24, 1 | BRF_ESS | BRF_PRG },
	{ "vamu.10a",      0x080000, 0xc1a3d9be, 1 | BRF_ESS | BRF_PRG },

	{ "vam.13m",       0x400000, 0xc51baf99, 3 | BRF_GRA },
	{ "vam.15m",       0x400000, 0x3ce83c77, 3 | BRF_GRA },
	{ "vam.17m",       0x400000, 0x4f2408e0, 3 | BRF_GRA },
	{ "vam.19m",       0x400000, 0x9ff60250, 3 | BRF_GRA },
	{ "vam.14m",       0x100000, 0xbd87243c, 3 | BRF_GRA },
	{ "vam.16m",       0x100000, 0xafec855f, 3 | BRF_GRA },
	{ "vam.18m",       0x100000, 0x3a033625, 3 | BRF_GRA },
	{ "vam.20m",       0x100000, 0x2bff6a89, 3 | BRF_GRA },

	{ "vam.01",        0x020000, 0x64b685d5, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "vam.02",        0x020000, 0xcf7c97c7, 4 | BRF_ESS | BRF_PRG },

	{ "vam.11m",       0x200000, 0x4a39deb2, 5 | BRF_SND },
	{ "vam.12m",       0x200000, 0x1a3e5c03, 5 | BRF_SND },
};

STD_ROM_PICK(Dstlkur1) STD_ROM_FN(Dstlkur1)

struct BurnDriver BurnDrvCpsDstlkur1 = {
	"dstlkur1", "dstlk", NULL, "1994",
	"Darkstalkers: The Night Warriors (USA 940705)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Dstlkur1RomInfo, Dstlkur1RomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Vampire: The Night Warriors (Japan 940705)

static struct BurnRomInfo VampjRomDesc[] = {
	{ "vamj.03a",      0x080000, 0xf55d3722, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "vamj.04b",      0x080000, 0x4d9c43c4, 1 | BRF_ESS | BRF_PRG },
	{ "vamj.05a",      0x080000, 0x6c497e92, 1 | BRF_ESS | BRF_PRG },
	{ "vamj.06a",      0x080000, 0xf1bbecb6, 1 | BRF_ESS | BRF_PRG },
	{ "vamj.07a",      0x080000, 0x1067ad84, 1 | BRF_ESS | BRF_PRG },
	{ "vamj.08a",      0x080000, 0x4b89f41f, 1 | BRF_ESS | BRF_PRG },
	{ "vamj.09a",      0x080000, 0xfc0a4aac, 1 | BRF_ESS | BRF_PRG },
	{ "vamj.10a",      0x080000, 0x9270c26b, 1 | BRF_ESS | BRF_PRG },

	{ "vam.13m",       0x400000, 0xc51baf99, 3 | BRF_GRA },
	{ "vam.15m",       0x400000, 0x3ce83c77, 3 | BRF_GRA },
	{ "vam.17m",       0x400000, 0x4f2408e0, 3 | BRF_GRA },
	{ "vam.19m",       0x400000, 0x9ff60250, 3 | BRF_GRA },
	{ "vam.14m",       0x100000, 0xbd87243c, 3 | BRF_GRA },
	{ "vam.16m",       0x100000, 0xafec855f, 3 | BRF_GRA },
	{ "vam.18m",       0x100000, 0x3a033625, 3 | BRF_GRA },
	{ "vam.20m",       0x100000, 0x2bff6a89, 3 | BRF_GRA },

	{ "vam.01",        0x020000, 0x64b685d5, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "vam.02",        0x020000, 0xcf7c97c7, 4 | BRF_ESS | BRF_PRG },

	{ "vam.11m",       0x200000, 0x4a39deb2, 5 | BRF_SND },
	{ "vam.12m",       0x200000, 0x1a3e5c03, 5 | BRF_SND },

};

STD_ROM_PICK(Vampj) STD_ROM_FN(Vampj)

struct BurnDriver BurnDrvCpsVampj = {
	"vampj", "dstlk", NULL, "1994",
	"Vampire: The Night Warriors (Japan 940705)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, VampjRomInfo, VampjRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Vampire: The Night Warriors (Japan 940705 alt)

static struct BurnRomInfo VampjaRomDesc[] = {
	{ "vamj.03a",      0x080000, 0xf55d3722, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "vamj.04a",      0x080000, 0xfdcbdae3, 1 | BRF_ESS | BRF_PRG },
	{ "vamj.05a",      0x080000, 0x6c497e92, 1 | BRF_ESS | BRF_PRG },
	{ "vamj.06a",      0x080000, 0xf1bbecb6, 1 | BRF_ESS | BRF_PRG },
	{ "vamj.07a",      0x080000, 0x1067ad84, 1 | BRF_ESS | BRF_PRG },
	{ "vamj.08a",      0x080000, 0x4b89f41f, 1 | BRF_ESS | BRF_PRG },
	{ "vamj.09a",      0x080000, 0xfc0a4aac, 1 | BRF_ESS | BRF_PRG },
	{ "vamj.10a",      0x080000, 0x9270c26b, 1 | BRF_ESS | BRF_PRG },

	{ "vam.13m",       0x400000, 0xc51baf99, 3 | BRF_GRA },
	{ "vam.15m",       0x400000, 0x3ce83c77, 3 | BRF_GRA },
	{ "vam.17m",       0x400000, 0x4f2408e0, 3 | BRF_GRA },
	{ "vam.19m",       0x400000, 0x9ff60250, 3 | BRF_GRA },
	{ "vam.14m",       0x100000, 0xbd87243c, 3 | BRF_GRA },
	{ "vam.16m",       0x100000, 0xafec855f, 3 | BRF_GRA },
	{ "vam.18m",       0x100000, 0x3a033625, 3 | BRF_GRA },
	{ "vam.20m",       0x100000, 0x2bff6a89, 3 | BRF_GRA },

	{ "vam.01",        0x020000, 0x64b685d5, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "vam.02",        0x020000, 0xcf7c97c7, 4 | BRF_ESS | BRF_PRG },

	{ "vam.11m",       0x200000, 0x4a39deb2, 5 | BRF_SND },
	{ "vam.12m",       0x200000, 0x1a3e5c03, 5 | BRF_SND },
};

STD_ROM_PICK(Vampja) STD_ROM_FN(Vampja)

struct BurnDriver BurnDrvCpsVampja = {
	"vampja", "dstlk", NULL, "1994",
	"Vampire: The Night Warriors (Japan 940705 alt)\0", "Alternate version", "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, VampjaRomInfo, VampjaRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Vampire: The Night Warriors (Japan 940630)

static struct BurnRomInfo Vampjr1RomDesc[] = {
	{ "vamj.03",       0x080000, 0x8895bf77, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "vamj.04",       0x080000, 0x5027db3d, 1 | BRF_ESS | BRF_PRG },
	{ "vamj.05",       0x080000, 0x97c66fdb, 1 | BRF_ESS | BRF_PRG },
	{ "vamj.06",       0x080000, 0x9b4c3426, 1 | BRF_ESS | BRF_PRG },
	{ "vamj.07",       0x080000, 0x303bc4fd, 1 | BRF_ESS | BRF_PRG },
	{ "vamj.08",       0x080000, 0x3dea3646, 1 | BRF_ESS | BRF_PRG },
	{ "vamj.09",       0x080000, 0xc119a827, 1 | BRF_ESS | BRF_PRG },
	{ "vamj.10",       0x080000, 0x46593b79, 1 | BRF_ESS | BRF_PRG },

	{ "vam.13m",       0x400000, 0xc51baf99, 3 | BRF_GRA },
	{ "vam.15m",       0x400000, 0x3ce83c77, 3 | BRF_GRA },
	{ "vam.17m",       0x400000, 0x4f2408e0, 3 | BRF_GRA },
	{ "vam.19m",       0x400000, 0x9ff60250, 3 | BRF_GRA },
	{ "vam.14m",       0x100000, 0xbd87243c, 3 | BRF_GRA },
	{ "vam.16m",       0x100000, 0xafec855f, 3 | BRF_GRA },
	{ "vam.18m",       0x100000, 0x3a033625, 3 | BRF_GRA },
	{ "vam.20m",       0x100000, 0x2bff6a89, 3 | BRF_GRA },

	{ "vam.01",        0x020000, 0x64b685d5, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "vam.02",        0x020000, 0xcf7c97c7, 4 | BRF_ESS | BRF_PRG },

	{ "vam.11m",       0x200000, 0x4a39deb2, 5 | BRF_SND },
	{ "vam.12m",       0x200000, 0x1a3e5c03, 5 | BRF_SND },
};

STD_ROM_PICK(Vampjr1) STD_ROM_FN(Vampjr1)

struct BurnDriver BurnDrvCpsVampjr1 = {
	"vampjr1", "dstlk", NULL, "1994",
	"Vampire: The Night Warriors (Japan 940630)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Vampjr1RomInfo, Vampjr1RomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Darkstalkers: The Night Warriors (Asia 940705)

static struct BurnRomInfo DstlkaRomDesc[] = {
	{ "vama.03a",      0x080000, 0x294e0bec, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "vama.04a",      0x080000, 0xbc18e128, 1 | BRF_ESS | BRF_PRG },
	{ "vama.05a",      0x080000, 0xe709fa59, 1 | BRF_ESS | BRF_PRG },
	{ "vama.06a",      0x080000, 0x55e4d387, 1 | BRF_ESS | BRF_PRG },
	{ "vama.07a",      0x080000, 0x24e8f981, 1 | BRF_ESS | BRF_PRG },
	{ "vama.08a",      0x080000, 0x743f3a8e, 1 | BRF_ESS | BRF_PRG },
	{ "vama.09a",      0x080000, 0x67fa5573, 1 | BRF_ESS | BRF_PRG },
	{ "vama.10a",      0x080000, 0x5e03d747, 1 | BRF_ESS | BRF_PRG },

	{ "vam.13m",       0x400000, 0xc51baf99, 3 | BRF_GRA },
	{ "vam.15m",       0x400000, 0x3ce83c77, 3 | BRF_GRA },
	{ "vam.17m",       0x400000, 0x4f2408e0, 3 | BRF_GRA },
	{ "vam.19m",       0x400000, 0x9ff60250, 3 | BRF_GRA },
	{ "vam.14m",       0x100000, 0xbd87243c, 3 | BRF_GRA },
	{ "vam.16m",       0x100000, 0xafec855f, 3 | BRF_GRA },
	{ "vam.18m",       0x100000, 0x3a033625, 3 | BRF_GRA },
	{ "vam.20m",       0x100000, 0x2bff6a89, 3 | BRF_GRA },

	{ "vam.01",        0x020000, 0x64b685d5, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "vam.02",        0x020000, 0xcf7c97c7, 4 | BRF_ESS | BRF_PRG },

	{ "vam.11m",       0x200000, 0x4a39deb2, 5 | BRF_SND },
	{ "vam.12m",       0x200000, 0x1a3e5c03, 5 | BRF_SND },
};

STD_ROM_PICK(Dstlka) STD_ROM_FN(Dstlka)

struct BurnDriver BurnDrvCpsDstlka = {
	"dstlka", "dstlk", NULL, "1994",
	"Darkstalkers: The Night Warriors (Asia 940705)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, DstlkaRomInfo, DstlkaRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Darkstalkers: The Night Warriors (Hispanic 940818)

static struct BurnRomInfo DstlkhRomDesc[] = {
	{ "vamh.03c",      0x080000, 0x4d7b9e8f, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "vamh.04c",      0x080000, 0x2217e9a0, 1 | BRF_ESS | BRF_PRG },
	{ "vamh.05c",      0x080000, 0x3a05b13c, 1 | BRF_ESS | BRF_PRG },
	{ "vamh.06c",      0x080000, 0x11d70a1c, 1 | BRF_ESS | BRF_PRG },
	{ "vamh.07c",      0x080000, 0xdb5a8767, 1 | BRF_ESS | BRF_PRG },
	{ "vamh.08c",      0x080000, 0x2a4fd79b, 1 | BRF_ESS | BRF_PRG },
	{ "vamh.09c",      0x080000, 0x15187632, 1 | BRF_ESS | BRF_PRG },
	{ "vamh.10c",      0x080000, 0x192d2d81, 1 | BRF_ESS | BRF_PRG },

	{ "vam.13m",       0x400000, 0xc51baf99, 3 | BRF_GRA },
	{ "vam.15m",       0x400000, 0x3ce83c77, 3 | BRF_GRA },
	{ "vam.17m",       0x400000, 0x4f2408e0, 3 | BRF_GRA },
	{ "vam.19m",       0x400000, 0x9ff60250, 3 | BRF_GRA },
	{ "vam.14m",       0x100000, 0xbd87243c, 3 | BRF_GRA },
	{ "vam.16m",       0x100000, 0xafec855f, 3 | BRF_GRA },
	{ "vam.18m",       0x100000, 0x3a033625, 3 | BRF_GRA },
	{ "vam.20m",       0x100000, 0x2bff6a89, 3 | BRF_GRA },

	{ "vam.01",        0x020000, 0x64b685d5, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "vam.02",        0x020000, 0xcf7c97c7, 4 | BRF_ESS | BRF_PRG },

	{ "vam.11m",       0x200000, 0x4a39deb2, 5 | BRF_SND },
	{ "vam.12m",       0x200000, 0x1a3e5c03, 5 | BRF_SND },
};

STD_ROM_PICK(Dstlkh) STD_ROM_FN(Dstlkh)

struct BurnDriver BurnDrvCpsDstlkh = {
	"dstlkh", "dstlk", NULL, "1994",
	"Darkstalkers: The Night Warriors (Hispanic 940818)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, DstlkhRomInfo, DstlkhRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Darkstalkers: The Night Warriors (USA 940705, Phoenix Edition)

static struct BurnRomInfo Dstlku1dRomDesc[] = {
	{ "vamud.03a",     0x80000,  0x47b7a680, 1 | BRF_ESS | BRF_PRG },
	{ "vamud.04a",     0x80000,  0x3b7a4939, 1 | BRF_ESS | BRF_PRG },
	{ "vamu.05a",      0x80000,  0x673ed50a, 1 | BRF_ESS | BRF_PRG },
	{ "vamu.06a",      0x80000,  0xf2377be7, 1 | BRF_ESS | BRF_PRG },
	{ "vamu.07a",      0x80000,  0xd8f498c4, 1 | BRF_ESS | BRF_PRG },
	{ "vamu.08a",      0x80000,  0xe6a8a1a0, 1 | BRF_ESS | BRF_PRG },
	{ "vamud.09a",     0x80000,  0x8b333a19, 1 | BRF_ESS | BRF_PRG },
	{ "vamu.10a",      0x80000,  0xc1a3d9be, 1 | BRF_ESS | BRF_PRG },

	{ "vam.13m",       0x400000, 0xc51baf99, 3 | BRF_GRA },
	{ "vam.15m",       0x400000, 0x3ce83c77, 3 | BRF_GRA },
	{ "vam.17m",       0x400000, 0x4f2408e0, 3 | BRF_GRA },
	{ "vam.19m",       0x400000, 0x9ff60250, 3 | BRF_GRA },
	{ "vam.14m",       0x100000, 0xbd87243c, 3 | BRF_GRA },
	{ "vam.16m",       0x100000, 0xafec855f, 3 | BRF_GRA },
	{ "vam.18m",       0x100000, 0x3a033625, 3 | BRF_GRA },
	{ "vam.20m",       0x100000, 0x2bff6a89, 3 | BRF_GRA },

	{ "vam.01",        0x020000, 0x64b685d5, 4 | BRF_ESS | BRF_PRG },
	{ "vam.02",        0x020000, 0xcf7c97c7, 4 | BRF_ESS | BRF_PRG },

	{ "vam.11m",       0x200000, 0x4a39deb2, 5 | BRF_SND },
	{ "vam.12m",       0x200000, 0x1a3e5c03, 5 | BRF_SND },
};

STD_ROM_PICK(Dstlku1d) STD_ROM_FN(Dstlku1d)

struct BurnDriver BurnDrvCpsDstlku1d = {
	"dstlku1d", "dstlk", NULL, "1994",
	"Darkstalkers: The Night Warriors (USA 940705, Phoenix Edition)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE | BDF_BOOTLEG,2,HARDWARE_CAPCOM_CPS2,
	NULL, Dstlku1dRomInfo, Dstlku1dRomName, DrvInputInfo, NULL,
	PhoenixInit, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Eco Fighters (World 931203)

static struct BurnRomInfo EcofghtrRomDesc[] = {
	{ "uece.03",      0x080000, 0xec2c1137, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "uece.04",      0x080000, 0xb35f99db, 1 | BRF_ESS | BRF_PRG },
	{ "uece.05",      0x080000, 0xd9d42d31, 1 | BRF_ESS | BRF_PRG },
	{ "uece.06",      0x080000, 0x9d9771cf, 1 | BRF_ESS | BRF_PRG },

	{ "uec.13m",      0x200000, 0xdcaf1436, 3 | BRF_GRA },
	{ "uec.15m",      0x200000, 0x2807df41, 3 | BRF_GRA },
	{ "uec.17m",      0x200000, 0x8a708d02, 3 | BRF_GRA },
	{ "uec.19m",      0x200000, 0xde7be0ef, 3 | BRF_GRA },
	{ "uec.14m",      0x100000, 0x1a003558, 3 | BRF_GRA },
	{ "uec.16m",      0x100000, 0x4ff8a6f9, 3 | BRF_GRA },
	{ "uec.18m",      0x100000, 0xb167ae12, 3 | BRF_GRA },
	{ "uec.20m",      0x100000, 0x1064bdc2, 3 | BRF_GRA },

	{ "uec.01",       0x020000, 0xc235bd15, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "uec.11m",      0x200000, 0x81b25d39, 5 | BRF_SND },
	{ "uec.12m",      0x200000, 0x27729e52, 5 | BRF_SND },
};

STD_ROM_PICK(Ecofghtr) STD_ROM_FN(Ecofghtr)

struct BurnDriver BurnDrvCpsEcofghtr = {
	"ecofghtr", NULL, NULL, "1993",
	"Eco Fighters (World 931203)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING,2,HARDWARE_CAPCOM_CPS2,
	NULL, EcofghtrRomInfo, EcofghtrRomName, ecofghtrInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Eco Fighters (USA 940215)

static struct BurnRomInfo ecofghtruRomDesc[] = {
	{ "uecu.03a",	  0x080000, 0x22d88a4d, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "uecu.04a",	  0x080000, 0x6436cfcd, 1 | BRF_ESS | BRF_PRG },
	{ "uecu.05a",	  0x080000, 0x336f121b, 1 | BRF_ESS | BRF_PRG },
	{ "uecu.06a",	  0x080000, 0x6f99d984, 1 | BRF_ESS | BRF_PRG },

	{ "uec.13m",      0x200000, 0xdcaf1436, 3 | BRF_GRA },
	{ "uec.15m",      0x200000, 0x2807df41, 3 | BRF_GRA },
	{ "uec.17m",      0x200000, 0x8a708d02, 3 | BRF_GRA },
	{ "uec.19m",      0x200000, 0xde7be0ef, 3 | BRF_GRA },
	{ "uec.14m",      0x100000, 0x1a003558, 3 | BRF_GRA },
	{ "uec.16m",      0x100000, 0x4ff8a6f9, 3 | BRF_GRA },
	{ "uec.18m",      0x100000, 0xb167ae12, 3 | BRF_GRA },
	{ "uec.20m",      0x100000, 0x1064bdc2, 3 | BRF_GRA },

	{ "uec.01",       0x020000, 0xc235bd15, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "uec.11m",      0x200000, 0x81b25d39, 5 | BRF_SND },
	{ "uec.12m",      0x200000, 0x27729e52, 5 | BRF_SND },
};

STD_ROM_PICK(ecofghtru) STD_ROM_FN(ecofghtru)

struct BurnDriver BurnDrvCpsecofghtru = {
	"ecofghtru", "ecofghtr", NULL, "1993",
	"Eco Fighters (USA 940215)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, ecofghtruRomInfo, ecofghtruRomName, ecofghtrInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Eco Fighters (USA 931203)

static struct BurnRomInfo ecofghtru1RomDesc[] = {
	{ "uecu.03",	  0x080000, 0x6792480c, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "uecu.04",	  0x080000, 0x95ce69d5, 1 | BRF_ESS | BRF_PRG },
	{ "uecu.05",	  0x080000, 0x3a1e78ad, 1 | BRF_ESS | BRF_PRG },
	{ "uecu.06",	  0x080000, 0xa3e2f3cc, 1 | BRF_ESS | BRF_PRG },

	{ "uec.13m",      0x200000, 0xdcaf1436, 3 | BRF_GRA },
	{ "uec.15m",      0x200000, 0x2807df41, 3 | BRF_GRA },
	{ "uec.17m",      0x200000, 0x8a708d02, 3 | BRF_GRA },
	{ "uec.19m",      0x200000, 0xde7be0ef, 3 | BRF_GRA },
	{ "uec.14m",      0x100000, 0x1a003558, 3 | BRF_GRA },
	{ "uec.16m",      0x100000, 0x4ff8a6f9, 3 | BRF_GRA },
	{ "uec.18m",      0x100000, 0xb167ae12, 3 | BRF_GRA },
	{ "uec.20m",      0x100000, 0x1064bdc2, 3 | BRF_GRA },

	{ "uec.01",       0x020000, 0xc235bd15, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "uec.11m",      0x200000, 0x81b25d39, 5 | BRF_SND },
	{ "uec.12m",      0x200000, 0x27729e52, 5 | BRF_SND },
};

STD_ROM_PICK(ecofghtru1) STD_ROM_FN(ecofghtru1)

struct BurnDriver BurnDrvCpsecofghtru1 = {
	"ecofghtru1", "ecofghtr", NULL, "1993",
	"Eco Fighters (USA 931203)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, ecofghtru1RomInfo, ecofghtru1RomName, ecofghtrInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Ultimate Ecology (Japan 931203)

static struct BurnRomInfo UecologyRomDesc[] = {
	{ "uecj.03",      0x080000, 0x94c40a4c, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "uecj.04",      0x080000, 0x8d6e3a09, 1 | BRF_ESS | BRF_PRG },
	{ "uecj.05",      0x080000, 0x8604ecd7, 1 | BRF_ESS | BRF_PRG },
	{ "uecj.06",      0x080000, 0xb7e1d31f, 1 | BRF_ESS | BRF_PRG },

	{ "uec.13m",      0x200000, 0xdcaf1436, 3 | BRF_GRA },
	{ "uec.15m",      0x200000, 0x2807df41, 3 | BRF_GRA },
	{ "uec.17m",      0x200000, 0x8a708d02, 3 | BRF_GRA },
	{ "uec.19m",      0x200000, 0xde7be0ef, 3 | BRF_GRA },
	{ "uec.14m",      0x100000, 0x1a003558, 3 | BRF_GRA },
	{ "uec.16m",      0x100000, 0x4ff8a6f9, 3 | BRF_GRA },
	{ "uec.18m",      0x100000, 0xb167ae12, 3 | BRF_GRA },
	{ "uec.20m",      0x100000, 0x1064bdc2, 3 | BRF_GRA },

	{ "uec.01",       0x020000, 0xc235bd15, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "uec.11m",      0x200000, 0x81b25d39, 5 | BRF_SND },
	{ "uec.12m",      0x200000, 0x27729e52, 5 | BRF_SND },
};


STD_ROM_PICK(Uecology) STD_ROM_FN(Uecology)

struct BurnDriver BurnDrvCpsUecology = {
	"uecology", "ecofghtr", NULL, "1993",
	"Ultimate Ecology (Japan 931203)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, UecologyRomInfo, UecologyRomName, ecofghtrInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Eco Fighters (Asia 931203)

static struct BurnRomInfo EcofghtraRomDesc[] = {
	{ "ueca.03",	  0x080000, 0xbd4589b1, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "ueca.04",	  0x080000, 0x1d134b7d, 1 | BRF_ESS | BRF_PRG },
	{ "ueca.05",	  0x080000, 0x9c581fc7, 1 | BRF_ESS | BRF_PRG },
	{ "ueca.06",	  0x080000, 0xc92a7c50, 1 | BRF_ESS | BRF_PRG },

	{ "uec.13m",      0x200000, 0xdcaf1436, 3 | BRF_GRA },
	{ "uec.15m",      0x200000, 0x2807df41, 3 | BRF_GRA },
	{ "uec.17m",      0x200000, 0x8a708d02, 3 | BRF_GRA },
	{ "uec.19m",      0x200000, 0xde7be0ef, 3 | BRF_GRA },
	{ "uec.14m",      0x100000, 0x1a003558, 3 | BRF_GRA },
	{ "uec.16m",      0x100000, 0x4ff8a6f9, 3 | BRF_GRA },
	{ "uec.18m",      0x100000, 0xb167ae12, 3 | BRF_GRA },
	{ "uec.20m",      0x100000, 0x1064bdc2, 3 | BRF_GRA },

	{ "uec.01",       0x020000, 0xc235bd15, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "uec.11m",      0x200000, 0x81b25d39, 5 | BRF_SND },
	{ "uec.12m",      0x200000, 0x27729e52, 5 | BRF_SND },
};

STD_ROM_PICK(Ecofghtra) STD_ROM_FN(Ecofghtra)

struct BurnDriver BurnDrvCpsEcofghtra = {
	"ecofghtra", "ecofghtr", NULL, "1993",
	"Eco Fighters (Asia 931203)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, EcofghtraRomInfo, EcofghtraRomName, ecofghtrInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Giga Wing (USA 990222)

static struct BurnRomInfo GigawingRomDesc[] = {
	{ "ggwu.03",      0x080000, 0xac725eb2, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "ggwu.04",      0x080000, 0x392f4118, 1 | BRF_ESS | BRF_PRG },
	{ "ggw.05",       0x080000, 0x3239d642, 1 | BRF_ESS | BRF_PRG },

	{ "ggw.13m",      0x400000, 0x105530a4, 3 | BRF_GRA },
	{ "ggw.15m",      0x400000, 0x9e774ab9, 3 | BRF_GRA },
	{ "ggw.17m",      0x400000, 0x466e0ba4, 3 | BRF_GRA },
	{ "ggw.19m",      0x400000, 0x840c8dea, 3 | BRF_GRA },

	{ "ggw.01",       0x020000, 0x4c6351d5, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "ggw.11m",      0x400000, 0xe172acf5, 5 | BRF_SND },
	{ "ggw.12m",      0x400000, 0x4bee4e8f, 5 | BRF_SND },
};

STD_ROM_PICK(Gigawing) STD_ROM_FN(Gigawing)

struct BurnDriver BurnDrvCpsGigawing = {
	"gigawing", NULL, NULL, "1999",
	"Giga Wing (USA 990222)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING, 2, HARDWARE_CAPCOM_CPS2,
	NULL, GigawingRomInfo, GigawingRomName, gwingInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Giga Wing (Japan 990223)

static struct BurnRomInfo GigawingjRomDesc[] = {
	{ "ggwj.03a",     0x080000, 0xfdd23b91, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "ggwj.04a",     0x080000, 0x8c6e093c, 1 | BRF_ESS | BRF_PRG },
	{ "ggwj.05a",     0x080000, 0x43811454, 1 | BRF_ESS | BRF_PRG },

	{ "ggw.13m",      0x400000, 0x105530a4, 3 | BRF_GRA },
	{ "ggw.15m",      0x400000, 0x9e774ab9, 3 | BRF_GRA },
	{ "ggw.17m",      0x400000, 0x466e0ba4, 3 | BRF_GRA },
	{ "ggw.19m",      0x400000, 0x840c8dea, 3 | BRF_GRA },

	{ "ggw.01",       0x020000, 0x4c6351d5, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "ggw.11m",      0x400000, 0xe172acf5, 5 | BRF_SND },
	{ "ggw.12m",      0x400000, 0x4bee4e8f, 5 | BRF_SND },
};

STD_ROM_PICK(Gigawingj) STD_ROM_FN(Gigawingj)

struct BurnDriver BurnDrvCpsGigawingj = {
	"gigawingj", "gigawing", NULL, "1999",
	"Giga Wing (Japan 990223)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE, 2, HARDWARE_CAPCOM_CPS2,
	NULL, GigawingjRomInfo, GigawingjRomName, gwingInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Giga Wing (Asia 990222)

static struct BurnRomInfo gigawingaRomDesc[] = {
	{ "ggwa.03a",     0x080000, 0x116f8837, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "ggwa.04a",     0x080000, 0xe6e3f0c4, 1 | BRF_ESS | BRF_PRG },
	{ "ggwa.05a",     0x080000, 0x465e8ac9, 1 | BRF_ESS | BRF_PRG },

	{ "ggw.13m",      0x400000, 0x105530a4, 3 | BRF_GRA },
	{ "ggw.15m",      0x400000, 0x9e774ab9, 3 | BRF_GRA },
	{ "ggw.17m",      0x400000, 0x466e0ba4, 3 | BRF_GRA },
	{ "ggw.19m",      0x400000, 0x840c8dea, 3 | BRF_GRA },

	{ "ggw.01",       0x020000, 0x4c6351d5, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "ggw.11m",      0x400000, 0xe172acf5, 5 | BRF_SND },
	{ "ggw.12m",      0x400000, 0x4bee4e8f, 5 | BRF_SND },
};

STD_ROM_PICK(gigawinga) STD_ROM_FN(gigawinga)

struct BurnDriver BurnDrvCpsgigawinga = {
	"gigawinga", "gigawing", NULL, "1999",
	"Giga Wing (Asia 990222)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE, 2, HARDWARE_CAPCOM_CPS2,
	NULL, gigawingaRomInfo, gigawingaRomName, gwingInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Giga Wing (Brazil 990222)

static struct BurnRomInfo gigawingbRomDesc[] = {
	{ "ggwb.03",      0x080000, 0xa1f8a448, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "ggwb.04",      0x080000, 0x6a423e76, 1 | BRF_ESS | BRF_PRG },
	{ "ggw.05",       0x080000, 0x3239d642, 1 | BRF_ESS | BRF_PRG },

	{ "ggw.13m",      0x400000, 0x105530a4, 3 | BRF_GRA },
	{ "ggw.15m",      0x400000, 0x9e774ab9, 3 | BRF_GRA },
	{ "ggw.17m",      0x400000, 0x466e0ba4, 3 | BRF_GRA },
	{ "ggw.19m",      0x400000, 0x840c8dea, 3 | BRF_GRA },

	{ "ggw.01",       0x020000, 0x4c6351d5, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "ggw.11m",      0x400000, 0xe172acf5, 5 | BRF_SND },
	{ "ggw.12m",      0x400000, 0x4bee4e8f, 5 | BRF_SND },
};

STD_ROM_PICK(gigawingb) STD_ROM_FN(gigawingb)

struct BurnDriver BurnDrvCpsgigawingb = {
	"gigawingb", "gigawing", NULL, "1999",
	"Giga Wing (Brazil 990222)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE, 2, HARDWARE_CAPCOM_CPS2,
	NULL, gigawingbRomInfo, gigawingbRomName, gwingInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Giga Wing (Japan 990223, Phoenix Edition)\0

static struct BurnRomInfo GwingjdRomDesc[] = {
	{ "ggwjd.03a",     0x80000, 0xcb1c756e, 1 | BRF_ESS | BRF_PRG },
	{ "ggwjd.04a",     0x80000, 0xfa158e04, 1 | BRF_ESS | BRF_PRG },
	{ "ggwjd.05a",     0x80000, 0x1c5bc4e7, 1 | BRF_ESS | BRF_PRG },

	{ "ggw.13m",      0x400000, 0x105530a4, 3 | BRF_GRA },
	{ "ggw.15m",      0x400000, 0x9e774ab9, 3 | BRF_GRA },
	{ "ggw.17m",      0x400000, 0x466e0ba4, 3 | BRF_GRA },
	{ "ggw.19m",      0x400000, 0x840c8dea, 3 | BRF_GRA },

	{ "ggw.01",       0x020000, 0x4c6351d5, 4 | BRF_ESS | BRF_PRG },

	{ "ggw.11m",      0x400000, 0xe172acf5, 5 | BRF_SND },
	{ "ggw.12m",      0x400000, 0x4bee4e8f, 5 | BRF_SND },
};

STD_ROM_PICK(Gwingjd) STD_ROM_FN(Gwingjd)

struct BurnDriver BurnDrvCpsGwingjd = {
	"gwingjd", "gigawing", NULL, "1999",
	"Giga Wing (Japan 990223, Phoenix Edition)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE | BDF_BOOTLEG, 2, HARDWARE_CAPCOM_CPS2,
	NULL, GwingjdRomInfo, GwingjdRomName, gwingInputInfo, NULL,
	PhoenixInit, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Hyper Street Fighter 2: The Anniversary Edition (USA 040202)

static struct BurnRomInfo hsf2RomDesc[] = {
	{ "hs2u.03",      0x080000, 0xb308151e, 1 | BRF_ESS | BRF_PRG },
	{ "hs2u.04",      0x080000, 0x327aa49c, 1 | BRF_ESS | BRF_PRG },
	{ "hs2.05",       0x080000, 0xdde34a35, 1 | BRF_ESS | BRF_PRG },
	{ "hs2.06",       0x080000, 0xf4e56dda, 1 | BRF_ESS | BRF_PRG },
	{ "hs2.07",       0x080000, 0xee4420fc, 1 | BRF_ESS | BRF_PRG },
	{ "hs2.08",       0x080000, 0xc9441533, 1 | BRF_ESS | BRF_PRG },
	{ "hs2.09",       0x080000, 0x3fc638a8, 1 | BRF_ESS | BRF_PRG },
	{ "hs2.10",       0x080000, 0x20d0f9e4, 1 | BRF_ESS | BRF_PRG },

	{ "hs2.13m",      0x800000, 0xa6ecab17, 3 | BRF_GRA },
	{ "hs2.15m",      0x800000, 0x10a0ae4d, 3 | BRF_GRA },
	{ "hs2.17m",      0x800000, 0xadfa7726, 3 | BRF_GRA },
	{ "hs2.19m",      0x800000, 0xbb3ae322, 3 | BRF_GRA },

	{ "hs2.01",       0x020000, 0xc1a13786, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "hs2.02",       0x020000, 0x2d8794aa, 4 | BRF_ESS | BRF_PRG },

	{ "hs2.11m",      0x800000, 0x0e15c359, 5 | BRF_SND },
};

STD_ROM_PICK(hsf2) STD_ROM_FN(hsf2)

static int Ssf2tInit()
{
	Ssf2t = 1;
	return Cps2Init();
}

static int Ssf2tExit()
{
	Ssf2t = 0;
	return CpsExit();
}

static int Ssf2tPhoenixInit()
{
	Ssf2t = 1;
	return PhoenixInit();
}

struct BurnDriver BurnDrvCpshsf2 = {
	"hsf2", NULL, NULL, "2004",
	"Hyper Street Fighter 2: The Anniversary Edition (USA 040202)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING, 2, HARDWARE_CAPCOM_CPS2,
	NULL, hsf2RomInfo, hsf2RomName, DrvInputInfo, NULL,
	Ssf2tInit, Ssf2tExit, Cps2Frame, Cps2Redraw, CpsAreaScan,
	&CpsRecalcPal, 384, 224, 4, 3
};


// Hyper Street Fighter 2: The Anniversary Edition (Asia 040202)

static struct BurnRomInfo hsf2aRomDesc[] = {
	{ "hs2a.03",      0x080000, 0xd50a17e0, 1 | BRF_ESS | BRF_PRG },
	{ "hs2a.04",      0x080000, 0xa27f42de, 1 | BRF_ESS | BRF_PRG },
	{ "hs2.05",       0x080000, 0xdde34a35, 1 | BRF_ESS | BRF_PRG },
	{ "hs2.06",       0x080000, 0xf4e56dda, 1 | BRF_ESS | BRF_PRG },
	{ "hs2.07",       0x080000, 0xee4420fc, 1 | BRF_ESS | BRF_PRG },
	{ "hs2.08",       0x080000, 0xc9441533, 1 | BRF_ESS | BRF_PRG },
	{ "hs2.09",       0x080000, 0x3fc638a8, 1 | BRF_ESS | BRF_PRG },
	{ "hs2.10",       0x080000, 0x20d0f9e4, 1 | BRF_ESS | BRF_PRG },

	{ "hs2.13m",      0x800000, 0xa6ecab17, 3 | BRF_GRA },
	{ "hs2.15m",      0x800000, 0x10a0ae4d, 3 | BRF_GRA },
	{ "hs2.17m",      0x800000, 0xadfa7726, 3 | BRF_GRA },
	{ "hs2.19m",      0x800000, 0xbb3ae322, 3 | BRF_GRA },

	{ "hs2.01",       0x020000, 0xc1a13786, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "hs2.02",       0x020000, 0x2d8794aa, 4 | BRF_ESS | BRF_PRG },

	{ "hs2.11m",      0x800000, 0x0e15c359, 5 | BRF_SND },
};

STD_ROM_PICK(hsf2a) STD_ROM_FN(hsf2a)

struct BurnDriver BurnDrvCpshsf2a = {
	"hsf2a", "hsf2", NULL, "2004",
	"Hyper Street Fighter 2: The Anniversary Edition (Asia 040202)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE, 2, HARDWARE_CAPCOM_CPS2,
	NULL, hsf2aRomInfo, hsf2aRomName, DrvInputInfo, NULL,
	Ssf2tInit, Ssf2tExit, Cps2Frame, Cps2Redraw, CpsAreaScan,
	&CpsRecalcPal, 384, 224, 4, 3
};


// Hyper Street Fighter 2: The Anniversary Edition (Japan 031222)

static struct BurnRomInfo hsf2jRomDesc[] = {
	{ "hs2j.03",      0x080000, 0x00738f73, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "hs2j.04",      0x080000, 0x40072c4a, 1 | BRF_ESS | BRF_PRG },
	{ "hs2.05",       0x080000, 0xdde34a35, 1 | BRF_ESS | BRF_PRG },
	{ "hs2.06",       0x080000, 0xf4e56dda, 1 | BRF_ESS | BRF_PRG },
	{ "hs2.07",       0x080000, 0xee4420fc, 1 | BRF_ESS | BRF_PRG },
	{ "hs2.08",       0x080000, 0xc9441533, 1 | BRF_ESS | BRF_PRG },
	{ "hs2.09",       0x080000, 0x3fc638a8, 1 | BRF_ESS | BRF_PRG },
	{ "hs2.10",       0x080000, 0x20d0f9e4, 1 | BRF_ESS | BRF_PRG },

	{ "hs2.13m",      0x800000, 0xa6ecab17, 3 | BRF_GRA },
	{ "hs2.15m",      0x800000, 0x10a0ae4d, 3 | BRF_GRA },
	{ "hs2.17m",      0x800000, 0xadfa7726, 3 | BRF_GRA },
	{ "hs2.19m",      0x800000, 0xbb3ae322, 3 | BRF_GRA },

	{ "hs2.01",       0x020000, 0xc1a13786, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "hs2.02",       0x020000, 0x2d8794aa, 4 | BRF_ESS | BRF_PRG },

	{ "hs2.11m",      0x800000, 0x0e15c359, 5 | BRF_SND },
};

STD_ROM_PICK(hsf2j) STD_ROM_FN(hsf2j)

struct BurnDriver BurnDrvCpshsf2j = {
	"hsf2j", "hsf2", NULL, "2003",
	"Hyper Street Fighter 2: The Anniversary Edition (Japan 031222)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE, 2, HARDWARE_CAPCOM_CPS2,
	NULL, hsf2jRomInfo, hsf2jRomName, DrvInputInfo, NULL,
	Ssf2tInit, Ssf2tExit, Cps2Frame, Cps2Redraw, CpsAreaScan,
	&CpsRecalcPal, 384, 224, 4, 3
};


// Hyper Street Fighter II: The Anniversary Edition (Asia 040202, Phoenix Edition)

static struct BurnRomInfo hsf2dRomDesc[] = {
	{ "hs2ad.03",    0x80000, 0x0153d371, 1 | BRF_ESS | BRF_PRG },  // 8, 68000 code
	{ "hs2ad.04",    0x80000, 0x0276b78a, 1 | BRF_ESS | BRF_PRG },

	{ "hs2.05",      0x80000, 0xdde34a35, 1 | BRF_ESS | BRF_PRG },
	{ "hs2.06",      0x80000, 0xf4e56dda, 1 | BRF_ESS | BRF_PRG },
	{ "hs2.07",      0x80000, 0xee4420fc, 1 | BRF_ESS | BRF_PRG },
	{ "hs2.08",      0x80000, 0xc9441533, 1 | BRF_ESS | BRF_PRG },
	{ "hs2.09",      0x80000, 0x3fc638a8, 1 | BRF_ESS | BRF_PRG },
	{ "hs2.10",      0x80000, 0x20d0f9e4, 1 | BRF_ESS | BRF_PRG },

	{ "hs2.13m",     0x800000, 0xa6ecab17, 3 | BRF_GRA },		  // 16
	{ "hs2.15m",     0x800000, 0x10a0ae4d, 3 | BRF_GRA },
	{ "hs2.17m",     0x800000, 0xadfa7726, 3 | BRF_GRA },
	{ "hs2.19m",     0x800000, 0xbb3ae322, 3 | BRF_GRA },

	{ "hs2.01",      0x020000, 0xc1a13786, 4 | BRF_ESS | BRF_PRG }, // 20
	{ "hs2.02",      0x020000, 0x2d8794aa, 4 | BRF_ESS | BRF_PRG },

	{ "hs2.11m",     0x800000, 0x0e15c359, 5 | BRF_SND },		  // 22
};

STD_ROM_PICK(hsf2d) STD_ROM_FN(hsf2d)

struct BurnDriver BurnDrvCpsHsf2d = {
	"hsf2d", "hsf2", NULL, "2004",
	"Hyper Street Fighter II: The Anniversary Edition (Asia 040202, Phoenix Edition)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE | BDF_BOOTLEG, 2, HARDWARE_CAPCOM_CPS2,
	NULL, hsf2dRomInfo, hsf2dRomName, DrvInputInfo, NULL,
	Ssf2tPhoenixInit, Ssf2tExit, Cps2Frame, Cps2Redraw, CpsAreaScan,
	&CpsRecalcPal, 384, 224, 4, 3
};


// Jyangokushi: Haoh no Saihai (Japan 990527)

static struct BurnRomInfo jyangokuRomDesc[] = {
	{ "majj.03",      0x080000, 0x4614a3b2,  1 | BRF_ESS | BRF_PRG },	// 68k program

	{ "maj1_d.simm1", 0x200000, 0xba0fe27b, 11 | BRF_GRA },
	{ "maj1_c.simm1", 0x200000, 0x2cd141bf, 11 | BRF_GRA },
	{ "maj1_b.simm1", 0x200000, 0xe29e4c26, 11 | BRF_GRA },
	{ "maj1_a.simm1", 0x200000, 0x7f68b88a, 11 | BRF_GRA },
	{ "maj3_d.simm3", 0x200000, 0x3aaeb90b, 11 | BRF_GRA },
	{ "maj3_c.simm3", 0x200000, 0x97894cea, 11 | BRF_GRA },
	{ "maj3_b.simm3", 0x200000, 0xec737d9d, 11 | BRF_GRA },
	{ "maj3_a.simm3", 0x200000, 0xc23b6f22, 11 | BRF_GRA },

	{ "maj.01",       0x020000, 0x1fe8c213,  4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "maj5_a.simm5", 0x200000, 0x5ad9ee53, 15 | BRF_SND },
	{ "maj5_b.simm5", 0x200000, 0xefb3dbfb, 15 | BRF_SND },
};

STD_ROM_PICK(jyangoku) STD_ROM_FN(jyangoku)

struct BurnDriver BurnDrvCpsjyangoku = {
	"jyangoku", NULL, NULL, "1999",
	"Jyangokushi: Haoh no Saihai (Japan 990527)\0", NULL, "Capcom", "CPS2",
	L"\u96C0\u570B\u5FD7 -\u8987\u738B\u306E\u91C7\u724C- (990527 Japan)\0", NULL, NULL, NULL,
	BDF_GAME_WORKING, 2, HARDWARE_CAPCOM_CPS2 | HARDWARE_CAPCOM_CPS2_SIMM,
	NULL, jyangokuRomInfo, jyangokuRomName, jyangokuInputInfo, NULL,
	Cps2Init,CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Mega Man 2: The Power Fighters (USA 960708)

static struct BurnRomInfo Megaman2RomDesc[] = {
	{ "rm2u.03",      0x080000, 0x8ffc2cd1, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "rm2u.04",      0x080000, 0xbb30083a, 1 | BRF_ESS | BRF_PRG },
	{ "rm2.05",       0x080000, 0x02ee9efc, 1 | BRF_ESS | BRF_PRG },

	{ "rm2.14m",      0x200000, 0x9b1f00b4, 3 | BRF_GRA },
	{ "rm2.16m",      0x200000, 0xc2bb0c24, 3 | BRF_GRA },
	{ "rm2.18m",      0x200000, 0x12257251, 3 | BRF_GRA },
	{ "rm2.20m",      0x200000, 0xf9b6e786, 3 | BRF_GRA },

	{ "rm2.01a",      0x020000, 0xd18e7859, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "rm2.02",       0x020000, 0xc463ece0, 4 | BRF_ESS | BRF_PRG },

	{ "rm2.11m",      0x200000, 0x2106174d, 5 | BRF_SND },
	{ "rm2.12m",      0x200000, 0x546c1636, 5 | BRF_SND },
};

STD_ROM_PICK(Megaman2) STD_ROM_FN(Megaman2)

struct BurnDriver BurnDrvCpsMegaman2 = {
	"megaman2", NULL, NULL, "1996",
	"Mega Man 2: The Power Fighters (USA 960708)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING, 2, HARDWARE_CAPCOM_CPS2,
	NULL, Megaman2RomInfo, Megaman2RomName, megamanInputInfo, NULL,
	Cps2Init, CpsExit, Cps2Frame, Cps2Redraw, CpsAreaScan,
	&CpsRecalcPal, 384, 224, 4, 3
};


// Mega Man 2: The Power Fighters (Asia 960708)

static struct BurnRomInfo Megaman2aRomDesc[] = {
	{ "rm2a.03",      0x080000, 0x2b330ca7, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "rm2a.04",      0x080000, 0x8b47942b, 1 | BRF_ESS | BRF_PRG },
	{ "rm2.05",       0x080000, 0x02ee9efc, 1 | BRF_ESS | BRF_PRG },

	{ "rm2.14m",      0x200000, 0x9b1f00b4, 3 | BRF_GRA },
	{ "rm2.16m",      0x200000, 0xc2bb0c24, 3 | BRF_GRA },
	{ "rm2.18m",      0x200000, 0x12257251, 3 | BRF_GRA },
	{ "rm2.20m",      0x200000, 0xf9b6e786, 3 | BRF_GRA },

	{ "rm2.01a",      0x020000, 0xd18e7859, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "rm2.02",       0x020000, 0xc463ece0, 4 | BRF_ESS | BRF_PRG },

	{ "rm2.11m",      0x200000, 0x2106174d, 5 | BRF_SND },
	{ "rm2.12m",      0x200000, 0x546c1636, 5 | BRF_SND },
};

STD_ROM_PICK(Megaman2a) STD_ROM_FN(Megaman2a)

struct BurnDriver BurnDrvCpsMegaman2a = {
	"megaman2a", "megaman2", NULL, "1996",
	"Mega Man 2: The Power Fighters (Asia 960708)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE, 2, HARDWARE_CAPCOM_CPS2,
	NULL, Megaman2aRomInfo, Megaman2aRomName, megamanInputInfo, NULL,
	Cps2Init, CpsExit, Cps2Frame, Cps2Redraw, CpsAreaScan,
	&CpsRecalcPal, 384, 224, 4, 3
};


// Rockman 2: The Power Fighters (Japan 960708)

static struct BurnRomInfo Rockman2jRomDesc[] = {
	{ "rm2j.03",      0x080000, 0xdbaa1437, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "rm2j.04",      0x080000, 0xcf5ba612, 1 | BRF_ESS | BRF_PRG },
	{ "rm2.05",       0x080000, 0x02ee9efc, 1 | BRF_ESS | BRF_PRG },

	{ "rm2.14m",      0x200000, 0x9b1f00b4, 3 | BRF_GRA },
	{ "rm2.16m",      0x200000, 0xc2bb0c24, 3 | BRF_GRA },
	{ "rm2.18m",      0x200000, 0x12257251, 3 | BRF_GRA },
	{ "rm2.20m",      0x200000, 0xf9b6e786, 3 | BRF_GRA },

	{ "rm2.01a",      0x020000, 0xd18e7859, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "rm2.02",       0x020000, 0xc463ece0, 4 | BRF_ESS | BRF_PRG },

	{ "rm2.11m",      0x200000, 0x2106174d, 5 | BRF_SND },
	{ "rm2.12m",      0x200000, 0x546c1636, 5 | BRF_SND },
};

STD_ROM_PICK(Rockman2j) STD_ROM_FN(Rockman2j)

struct BurnDriver BurnDrvCpsRockman2j = {
	"rockman2j", "megaman2", NULL, "1996",
	"Rockman 2: The Power Fighters (Japan 960708)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE, 2, HARDWARE_CAPCOM_CPS2,
	NULL, Rockman2jRomInfo, Rockman2jRomName, megamanInputInfo, NULL,
	Cps2Init, CpsExit, Cps2Frame, Cps2Redraw, CpsAreaScan,
	&CpsRecalcPal, 384, 224, 4, 3
};


// Mega Man 2: The Power Fighters (Hispanic 960712)

static struct BurnRomInfo Megaman2hRomDesc[] = {
	{ "rm2h.03",      0x080000, 0xbb180378, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "rm2h.04",      0x080000, 0x205ffcd6, 1 | BRF_ESS | BRF_PRG },
	{ "rm2.05",       0x080000, 0x02ee9efc, 1 | BRF_ESS | BRF_PRG },

	{ "rm2.14m",      0x200000, 0x9b1f00b4, 3 | BRF_GRA },
	{ "rm2.16m",      0x200000, 0xc2bb0c24, 3 | BRF_GRA },
	{ "rm2.18m",      0x200000, 0x12257251, 3 | BRF_GRA },
	{ "rm2.20m",      0x200000, 0xf9b6e786, 3 | BRF_GRA },

	{ "rm2.01a",      0x020000, 0xd18e7859, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "rm2.02",       0x020000, 0xc463ece0, 4 | BRF_ESS | BRF_PRG },

	{ "rm2.11m",      0x200000, 0x2106174d, 5 | BRF_SND },
	{ "rm2.12m",      0x200000, 0x546c1636, 5 | BRF_SND },
};

STD_ROM_PICK(Megaman2h) STD_ROM_FN(Megaman2h)

struct BurnDriver BurnDrvCpsMegaman2h = {
	"megaman2h", "megaman2", NULL, "1996",
	"Mega Man 2: The Power Fighters (Hispanic 960712)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE, 2, HARDWARE_CAPCOM_CPS2,
	NULL, Megaman2hRomInfo, Megaman2hRomName, megamanInputInfo, NULL,
	Cps2Init, CpsExit, Cps2Frame, Cps2Redraw, CpsAreaScan,
	&CpsRecalcPal, 384, 224, 4, 3
};


// Mega Man 2: The Power Fighters (USA 960708, Phoenix Edition)

static struct BurnRomInfo Megamn2dRomDesc[] = {
	{ "rm2ud.03",     0x080000, 0xd3635f25, 1 | BRF_ESS | BRF_PRG },
	{ "rm2ud.04",     0x080000, 0x768a1705, 1 | BRF_ESS | BRF_PRG },
	{ "rm2.05",       0x080000, 0x02ee9efc, 1 | BRF_ESS | BRF_PRG },

	{ "rm2.14m",      0x200000, 0x9b1f00b4, 3 | BRF_GRA },
	{ "rm2.16m",      0x200000, 0xc2bb0c24, 3 | BRF_GRA },
	{ "rm2.18m",      0x200000, 0x12257251, 3 | BRF_GRA },
	{ "rm2.20m",      0x200000, 0xf9b6e786, 3 | BRF_GRA },

	{ "rm2.01a",      0x020000, 0xd18e7859, 4 | BRF_ESS | BRF_PRG },
	{ "rm2.02",       0x020000, 0xc463ece0, 4 | BRF_ESS | BRF_PRG },

	{ "rm2.11m",      0x200000, 0x2106174d, 5 | BRF_SND },
	{ "rm2.12m",      0x200000, 0x546c1636, 5 | BRF_SND },
};

STD_ROM_PICK(Megamn2d) STD_ROM_FN(Megamn2d)

struct BurnDriver BurnDrvCpsMegamn2d = {
	"megamn2d", "megaman2", NULL, "1996",
	"Mega Man 2: The Power Fighters (USA 960708, Phoenix Edition)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE | BDF_BOOTLEG, 2, HARDWARE_CAPCOM_CPS2,
	NULL, Megamn2dRomInfo, Megamn2dRomName, DrvInputInfo, NULL,
	PhoenixInit, CpsExit, Cps2Frame, Cps2Redraw, CpsAreaScan,
	&CpsRecalcPal ,384, 224, 4, 3
};


// Giga Man 2: The Power Fighters (bootleg)

static struct BurnRomInfo Gigamn2RomDesc[] = {
	{ "prog.bin",     0x400000, 0x2eaa5e10, 1 | BRF_ESS | BRF_PRG },	// 68k program

	{ "gfx1.bin",     0x400000, 0x00000000, 3 | BRF_GRA | BRF_NODUMP },
	{ "gfx2.bin",     0x400000, 0x00000000, 3 | BRF_GRA | BRF_NODUMP },

	{ "89c4051.bin",  0x010000, 0x00000000, 4 | BRF_ESS | BRF_NODUMP },	// sound MCU

	{ "oki.bin",      0x400000, 0x00000000, 5 | BRF_SND | BRF_NODUMP },
};

STD_ROM_PICK(Gigamn2) STD_ROM_FN(Gigamn2)

struct BurnDriver BurnDrvCpsGigamn2 = {
	"gigamn2", "megaman2", NULL, "2004",
	"Giga Man 2: The Power Fighters (bootleg)\0", NULL, "bootleg", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_CLONE | BDF_BOOTLEG, 2, HARDWARE_CAPCOM_CPS2,
	NULL, Gigamn2RomInfo, Gigamn2RomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit, Cps2Frame, Cps2Redraw, CpsAreaScan,
	&CpsRecalcPal, 384, 224, 4, 3
};


// Mars Matrix (USA 000412)

static struct BurnRomInfo mmatrixRomDesc[] = {
	{ "mmxu.03",      0x080000, 0xAB65b599, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "mmxu.04",      0x080000, 0x0135FC6C, 1 | BRF_ESS | BRF_PRG },
	{ "mmxu.05",      0x080000, 0xF1FD2B84, 1 | BRF_ESS | BRF_PRG },

	{ "mmx.13m",      0x400000, 0x04748718, 3 | BRF_GRA },
	{ "mmx.15m",      0x400000, 0x38074F44, 3 | BRF_GRA },
	{ "mmx.17m",      0x400000, 0xE4635E35, 3 | BRF_GRA },
	{ "mmx.19m",      0x400000, 0x4400A3F2, 3 | BRF_GRA },
	{ "mmx.14m",      0x400000, 0xD52BF491, 3 | BRF_GRA },
	{ "mmx.16m",      0x400000, 0x23F70780, 3 | BRF_GRA },
	{ "mmx.18m",      0x400000, 0x2562C9D5, 3 | BRF_GRA },
	{ "mmx.20m",      0x400000, 0x583A9687, 3 | BRF_GRA },

	{ "mmx.01",       0x020000, 0xC57E8171, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "mmx.11m",      0x400000, 0x4180B39F, 5 | BRF_SND },
	{ "mmx.12m",      0x400000, 0x95E22A59, 5 | BRF_SND },
};

STD_ROM_PICK(mmatrix) STD_ROM_FN(mmatrix)

struct BurnDriver BurnDrvCpsMarsMatrix = {
	"mmatrix", NULL, NULL, "2000",
	"Mars Matrix (USA 000412)\0", NULL, "Capcom / Takumi", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING, 2, HARDWARE_CAPCOM_CPS2,
	NULL, mmatrixRomInfo, mmatrixRomName, mmatrixInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Mars Matrix (USA 000412, Phoenix Edition)

static struct BurnRomInfo mmatrixdRomDesc[] = {
	{ "mmxud.03",     0x080000, 0x36711E60, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "mmxud.04",     0x080000, 0x4687226F, 1 | BRF_ESS | BRF_PRG },
	{ "mmxud.05",     0x080000, 0x52124398, 1 | BRF_ESS | BRF_PRG },

	{ "mmx.13m",      0x400000, 0x04748718, 3 | BRF_GRA },
	{ "mmx.15m",      0x400000, 0x38074F44, 3 | BRF_GRA },
	{ "mmx.17m",      0x400000, 0xE4635E35, 3 | BRF_GRA },
	{ "mmx.19m",      0x400000, 0x4400A3F2, 3 | BRF_GRA },
	{ "mmx.14m",      0x400000, 0xD52BF491, 3 | BRF_GRA },
	{ "mmx.16m",      0x400000, 0x23F70780, 3 | BRF_GRA },
	{ "mmx.18m",      0x400000, 0x2562C9D5, 3 | BRF_GRA },
	{ "mmx.20m",      0x400000, 0x583A9687, 3 | BRF_GRA },

	{ "mmx.01",       0x020000, 0xC57E8171, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "mmx.11m",      0x400000, 0x4180B39F, 5 | BRF_SND },
	{ "mmx.12m",      0x400000, 0x95E22A59, 5 | BRF_SND },
};

STD_ROM_PICK(mmatrixd) STD_ROM_FN(mmatrixd)

struct BurnDriver BurnDrvCpsMarsMatrixd = {
	"mmatrixd", "mmatrix", NULL, "2000",
	"Mars Matrix (USA 000412, Phoenix Edition)\0", NULL, "Capcom / Takumi", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE | BDF_BOOTLEG, 2, HARDWARE_CAPCOM_CPS2,
	NULL, mmatrixdRomInfo, mmatrixdRomName, mmatrixInputInfo, NULL,
	PhoenixInit, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Mars Matrix (Japan 000412)

static struct BurnRomInfo mmatrixjRomDesc[] = {
	{ "mmxj.03",      0x080000, 0x1D5DE213, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "mmxj.04",      0x080000, 0xD943A339, 1 | BRF_ESS | BRF_PRG },
	{ "mmxj.05",      0x080000, 0x0C8B4ABB, 1 | BRF_ESS | BRF_PRG },

	{ "mmx.13m",      0x400000, 0x04748718, 3 | BRF_GRA },
	{ "mmx.15m",      0x400000, 0x38074F44, 3 | BRF_GRA },
	{ "mmx.17m",      0x400000, 0xE4635E35, 3 | BRF_GRA },
	{ "mmx.19m",      0x400000, 0x4400A3F2, 3 | BRF_GRA },
	{ "mmx.14m",      0x400000, 0xD52BF491, 3 | BRF_GRA },
	{ "mmx.16m",      0x400000, 0x23F70780, 3 | BRF_GRA },
	{ "mmx.18m",      0x400000, 0x2562C9D5, 3 | BRF_GRA },
	{ "mmx.20m",      0x400000, 0x583A9687, 3 | BRF_GRA },

	{ "mmx.01",       0x020000, 0xC57E8171, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "mmx.11m",      0x400000, 0x4180B39F, 5 | BRF_SND },
	{ "mmx.12m",      0x400000, 0x95E22A59, 5 | BRF_SND },
};

STD_ROM_PICK(mmatrixj) STD_ROM_FN(mmatrixj)

struct BurnDriver BurnDrvCpsMarsMatrixJ = {
	"mmatrixj", "mmatrix", NULL, "2000",
	"Mars Matrix (Japan 000412)\0", NULL, "Capcom / Takumi", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE, 2, HARDWARE_CAPCOM_CPS2,
	NULL, mmatrixjRomInfo, mmatrixjRomName, mmatrixInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Marvel Super Heroes (Euro 951024)

static struct BurnRomInfo MshRomDesc[] = {
	{ "mshe.03",      0x080000, 0xbd951414, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "mshe.04",      0x080000, 0x19dd42f2, 1 | BRF_ESS | BRF_PRG },
	{ "msh.05",       0x080000, 0x6a091b9e, 1 | BRF_ESS | BRF_PRG },
	{ "msh.06b",      0x080000, 0x803e3fa4, 1 | BRF_ESS | BRF_PRG },
	{ "msh.07a",      0x080000, 0xc45f8e27, 1 | BRF_ESS | BRF_PRG },
	{ "msh.08a",      0x080000, 0x9ca6f12c, 1 | BRF_ESS | BRF_PRG },
	{ "msh.09a",      0x080000, 0x82ec27af, 1 | BRF_ESS | BRF_PRG },
	{ "msh.10b",      0x080000, 0x8d931196, 1 | BRF_ESS | BRF_PRG },

	{ "msh.13m",      0x400000, 0x09d14566, 3 | BRF_GRA },
	{ "msh.15m",      0x400000, 0xee962057, 3 | BRF_GRA },
	{ "msh.17m",      0x400000, 0x604ece14, 3 | BRF_GRA },
	{ "msh.19m",      0x400000, 0x94a731e8, 3 | BRF_GRA },
	{ "msh.14m",      0x400000, 0x4197973e, 3 | BRF_GRA },
	{ "msh.16m",      0x400000, 0x438da4a0, 3 | BRF_GRA },
	{ "msh.18m",      0x400000, 0x4db92d94, 3 | BRF_GRA },
	{ "msh.20m",      0x400000, 0xa2b0c6c0, 3 | BRF_GRA },

	{ "msh.01",       0x020000, 0xc976e6f9, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "msh.02",       0x020000, 0xce67d0d9, 4 | BRF_ESS | BRF_PRG },

	{ "msh.11m",      0x200000, 0x37ac6d30, 5 | BRF_SND },
	{ "msh.12m",      0x200000, 0xde092570, 5 | BRF_SND },
};

STD_ROM_PICK(Msh) STD_ROM_FN(Msh)

struct BurnDriver BurnDrvCpsMsh = {
	"msh", NULL, NULL, "1995",
	"Marvel Super Heroes (Euro 951024)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING,2,HARDWARE_CAPCOM_CPS2,
	NULL, MshRomInfo, MshRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Marvel Super Heroes (USA 951024)

static struct BurnRomInfo MshuRomDesc[] = {
	{ "mshu.03",      0x080000, 0xd2805bdd, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "mshu.04",      0x080000, 0x743f96ff, 1 | BRF_ESS | BRF_PRG },
	{ "msh.05",       0x080000, 0x6a091b9e, 1 | BRF_ESS | BRF_PRG },
	{ "msh.06b",      0x080000, 0x803e3fa4, 1 | BRF_ESS | BRF_PRG },
	{ "msh.07a",      0x080000, 0xc45f8e27, 1 | BRF_ESS | BRF_PRG },
	{ "msh.08a",      0x080000, 0x9ca6f12c, 1 | BRF_ESS | BRF_PRG },
	{ "msh.09a",      0x080000, 0x82ec27af, 1 | BRF_ESS | BRF_PRG },
	{ "msh.10b",      0x080000, 0x8d931196, 1 | BRF_ESS | BRF_PRG },

	{ "msh.13m",      0x400000, 0x09d14566, 3 | BRF_GRA },
	{ "msh.15m",      0x400000, 0xee962057, 3 | BRF_GRA },
	{ "msh.17m",      0x400000, 0x604ece14, 3 | BRF_GRA },
	{ "msh.19m",      0x400000, 0x94a731e8, 3 | BRF_GRA },
	{ "msh.14m",      0x400000, 0x4197973e, 3 | BRF_GRA },
	{ "msh.16m",      0x400000, 0x438da4a0, 3 | BRF_GRA },
	{ "msh.18m",      0x400000, 0x4db92d94, 3 | BRF_GRA },
	{ "msh.20m",      0x400000, 0xa2b0c6c0, 3 | BRF_GRA },

	{ "msh.01",       0x020000, 0xc976e6f9, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "msh.02",       0x020000, 0xce67d0d9, 4 | BRF_ESS | BRF_PRG },

	{ "msh.11m",      0x200000, 0x37ac6d30, 5 | BRF_SND },
	{ "msh.12m",      0x200000, 0xde092570, 5 | BRF_SND },
};

STD_ROM_PICK(Mshu) STD_ROM_FN(Mshu)

struct BurnDriver BurnDrvCpsMshu = {
	"mshu", "msh", NULL, "1995",
	"Marvel Super Heroes (USA 951024)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, MshuRomInfo, MshuRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Marvel Super Heroes (USA 951024, Phoenix Edition)

static struct BurnRomInfo MshudRomDesc[] = {
	{ "mshud.03",     0x080000, 0xc1d8c4c6, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "mshud.04",     0x080000, 0xe73dda16, 1 | BRF_ESS | BRF_PRG },
	{ "mshd.05",      0x080000, 0x3b493e84, 1 | BRF_ESS | BRF_PRG },
	{ "msh.06b",      0x080000, 0x803e3fa4, 1 | BRF_ESS | BRF_PRG },
	{ "msh.07a",      0x080000, 0xc45f8e27, 1 | BRF_ESS | BRF_PRG },
	{ "msh.08a",      0x080000, 0x9ca6f12c, 1 | BRF_ESS | BRF_PRG },
	{ "msh.09a",      0x080000, 0x82ec27af, 1 | BRF_ESS | BRF_PRG },
	{ "msh.10b",      0x080000, 0x8d931196, 1 | BRF_ESS | BRF_PRG },

	{ "msh.13m",      0x400000, 0x09d14566, 3 | BRF_GRA },
	{ "msh.15m",      0x400000, 0xee962057, 3 | BRF_GRA },
	{ "msh.17m",      0x400000, 0x604ece14, 3 | BRF_GRA },
	{ "msh.19m",      0x400000, 0x94a731e8, 3 | BRF_GRA },
	{ "msh.14m",      0x400000, 0x4197973e, 3 | BRF_GRA },
	{ "msh.16m",      0x400000, 0x438da4a0, 3 | BRF_GRA },
	{ "msh.18m",      0x400000, 0x4db92d94, 3 | BRF_GRA },
	{ "msh.20m",      0x400000, 0xa2b0c6c0, 3 | BRF_GRA },

	{ "msh.01",       0x020000, 0xc976e6f9, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "msh.02",       0x020000, 0xce67d0d9, 4 | BRF_ESS | BRF_PRG },

	{ "msh.11m",      0x200000, 0x37ac6d30, 5 | BRF_SND },
	{ "msh.12m",      0x200000, 0xde092570, 5 | BRF_SND },
};

STD_ROM_PICK(Mshud) STD_ROM_FN(Mshud)

struct BurnDriver BurnDrvCpsMshud = {
	"mshud", "msh", NULL, "1995",
	"Marvel Super Heroes (USA 951024, Phoenix Edition)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE | BDF_BOOTLEG,2,HARDWARE_CAPCOM_CPS2,
	NULL, MshudRomInfo, MshudRomName, DrvInputInfo, NULL,
	PhoenixInit, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Marvel Super Heroes (Japan 951117)

static struct BurnRomInfo MshjRomDesc[] = {
	{ "mshj.03g",     0x080000, 0x261f4091, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "mshj.04g",     0x080000, 0x61d791c6, 1 | BRF_ESS | BRF_PRG },
	{ "msh.05a",      0x080000, 0xf37539e6, 1 | BRF_ESS | BRF_PRG },
	{ "msh.06b",      0x080000, 0x803e3fa4, 1 | BRF_ESS | BRF_PRG },
	{ "msh.07a",      0x080000, 0xc45f8e27, 1 | BRF_ESS | BRF_PRG },
	{ "msh.08a",      0x080000, 0x9ca6f12c, 1 | BRF_ESS | BRF_PRG },
	{ "msh.09a",      0x080000, 0x82ec27af, 1 | BRF_ESS | BRF_PRG },
	{ "msh.10b",      0x080000, 0x8d931196, 1 | BRF_ESS | BRF_PRG },

	{ "msh.13m",      0x400000, 0x09d14566, 3 | BRF_GRA },
	{ "msh.15m",      0x400000, 0xee962057, 3 | BRF_GRA },
	{ "msh.17m",      0x400000, 0x604ece14, 3 | BRF_GRA },
	{ "msh.19m",      0x400000, 0x94a731e8, 3 | BRF_GRA },
	{ "msh.14m",      0x400000, 0x4197973e, 3 | BRF_GRA },
	{ "msh.16m",      0x400000, 0x438da4a0, 3 | BRF_GRA },
	{ "msh.18m",      0x400000, 0x4db92d94, 3 | BRF_GRA },
	{ "msh.20m",      0x400000, 0xa2b0c6c0, 3 | BRF_GRA },

	{ "msh.01",       0x020000, 0xc976e6f9, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "msh.02",       0x020000, 0xce67d0d9, 4 | BRF_ESS | BRF_PRG },

	{ "msh.11m",      0x200000, 0x37ac6d30, 5 | BRF_SND },
	{ "msh.12m",      0x200000, 0xde092570, 5 | BRF_SND },
};

STD_ROM_PICK(Mshj) STD_ROM_FN(Mshj)

struct BurnDriver BurnDrvCpsMshj = {
	"mshj", "msh", NULL, "1995",
	"Marvel Super Heroes (Japan 951117)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, MshjRomInfo, MshjRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Marvel Super Heroes (Japan 951024)

static struct BurnRomInfo Mshjr1RomDesc[] = {
	{ "mshj.03f",     0x080000, 0xff172fd2, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "mshj.04f",     0x080000, 0xebbb205a, 1 | BRF_ESS | BRF_PRG },
	{ "msh.05",       0x080000, 0x6a091b9e, 1 | BRF_ESS | BRF_PRG },
	{ "msh.06b",      0x080000, 0x803e3fa4, 1 | BRF_ESS | BRF_PRG },
	{ "msh.07a",      0x080000, 0xc45f8e27, 1 | BRF_ESS | BRF_PRG },
	{ "msh.08a",      0x080000, 0x9ca6f12c, 1 | BRF_ESS | BRF_PRG },
	{ "msh.09a",      0x080000, 0x82ec27af, 1 | BRF_ESS | BRF_PRG },
	{ "msh.10b",      0x080000, 0x8d931196, 1 | BRF_ESS | BRF_PRG },

	{ "msh.13m",      0x400000, 0x09d14566, 3 | BRF_GRA },
	{ "msh.15m",      0x400000, 0xee962057, 3 | BRF_GRA },
	{ "msh.17m",      0x400000, 0x604ece14, 3 | BRF_GRA },
	{ "msh.19m",      0x400000, 0x94a731e8, 3 | BRF_GRA },
	{ "msh.14m",      0x400000, 0x4197973e, 3 | BRF_GRA },
	{ "msh.16m",      0x400000, 0x438da4a0, 3 | BRF_GRA },
	{ "msh.18m",      0x400000, 0x4db92d94, 3 | BRF_GRA },
	{ "msh.20m",      0x400000, 0xa2b0c6c0, 3 | BRF_GRA },

	{ "msh.01",       0x020000, 0xc976e6f9, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "msh.02",       0x020000, 0xce67d0d9, 4 | BRF_ESS | BRF_PRG },

	{ "msh.11m",      0x200000, 0x37ac6d30, 5 | BRF_SND },
	{ "msh.12m",      0x200000, 0xde092570, 5 | BRF_SND },
};

STD_ROM_PICK(Mshjr1) STD_ROM_FN(Mshjr1)

struct BurnDriver BurnDrvCpsMshjr1 = {
	"mshjr1", "msh", NULL, "1995",
	"Marvel Super Heroes (Japan 951024)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Mshjr1RomInfo, Mshjr1RomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Marvel Super Heroes (Asia 951024)

static struct BurnRomInfo MshaRomDesc[] = {
	{ "msha.03e",     0x080000, 0xec84ec44, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "msha.04e",     0x080000, 0x098b8503, 1 | BRF_ESS | BRF_PRG },
	{ "msh.05",       0x080000, 0x6a091b9e, 1 | BRF_ESS | BRF_PRG },
	{ "msh.06b",      0x080000, 0x803e3fa4, 1 | BRF_ESS | BRF_PRG },
	{ "msh.07a",      0x080000, 0xc45f8e27, 1 | BRF_ESS | BRF_PRG },
	{ "msh.08a",      0x080000, 0x9ca6f12c, 1 | BRF_ESS | BRF_PRG },
	{ "msh.09a",      0x080000, 0x82ec27af, 1 | BRF_ESS | BRF_PRG },
	{ "msh.10b",      0x080000, 0x8d931196, 1 | BRF_ESS | BRF_PRG },

	{ "msh.13m",      0x400000, 0x09d14566, 3 | BRF_GRA },
	{ "msh.15m",      0x400000, 0xee962057, 3 | BRF_GRA },
	{ "msh.17m",      0x400000, 0x604ece14, 3 | BRF_GRA },
	{ "msh.19m",      0x400000, 0x94a731e8, 3 | BRF_GRA },
	{ "msh.14m",      0x400000, 0x4197973e, 3 | BRF_GRA },
	{ "msh.16m",      0x400000, 0x438da4a0, 3 | BRF_GRA },
	{ "msh.18m",      0x400000, 0x4db92d94, 3 | BRF_GRA },
	{ "msh.20m",      0x400000, 0xa2b0c6c0, 3 | BRF_GRA },

	{ "msh.01",       0x020000, 0xc976e6f9, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "msh.02",       0x020000, 0xce67d0d9, 4 | BRF_ESS | BRF_PRG },

	{ "msh.11m",      0x200000, 0x37ac6d30, 5 | BRF_SND },
	{ "msh.12m",      0x200000, 0xde092570, 5 | BRF_SND },
};

STD_ROM_PICK(Msha) STD_ROM_FN(Msha)

struct BurnDriver BurnDrvCpsMsha = {
	"msha", "msh", NULL, "1995",
	"Marvel Super Heroes (Asia 951024)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, MshaRomInfo, MshaRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Marvel Super Heroes (Hispanic 951117)

static struct BurnRomInfo MshhRomDesc[] = {
	{ "mshh.03c",     0x080000, 0x8d84b0fa, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "mshh.04c",     0x080000, 0xd638f601, 1 | BRF_ESS | BRF_PRG },
	{ "msh.05a",      0x080000, 0xf37539e6, 1 | BRF_ESS | BRF_PRG },
	{ "msh.06b",      0x080000, 0x803e3fa4, 1 | BRF_ESS | BRF_PRG },
	{ "msh.07a",      0x080000, 0xc45f8e27, 1 | BRF_ESS | BRF_PRG },
	{ "msh.08a",      0x080000, 0x9ca6f12c, 1 | BRF_ESS | BRF_PRG },
	{ "msh.09a",      0x080000, 0x82ec27af, 1 | BRF_ESS | BRF_PRG },
	{ "msh.10b",      0x080000, 0x8d931196, 1 | BRF_ESS | BRF_PRG },

	{ "msh.13m",      0x400000, 0x09d14566, 3 | BRF_GRA },
	{ "msh.15m",      0x400000, 0xee962057, 3 | BRF_GRA },
	{ "msh.17m",      0x400000, 0x604ece14, 3 | BRF_GRA },
	{ "msh.19m",      0x400000, 0x94a731e8, 3 | BRF_GRA },
	{ "msh.14m",      0x400000, 0x4197973e, 3 | BRF_GRA },
	{ "msh.16m",      0x400000, 0x438da4a0, 3 | BRF_GRA },
	{ "msh.18m",      0x400000, 0x4db92d94, 3 | BRF_GRA },
	{ "msh.20m",      0x400000, 0xa2b0c6c0, 3 | BRF_GRA },

	{ "msh.01",       0x020000, 0xc976e6f9, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "msh.02",       0x020000, 0xce67d0d9, 4 | BRF_ESS | BRF_PRG },

	{ "msh.11m",      0x200000, 0x37ac6d30, 5 | BRF_SND },
	{ "msh.12m",      0x200000, 0xde092570, 5 | BRF_SND },
};

STD_ROM_PICK(Mshh) STD_ROM_FN(Mshh)

struct BurnDriver BurnDrvCpsMshh = {
	"mshh", "msh", NULL, "1995",
	"Marvel Super Heroes (Hispanic 951117)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, MshhRomInfo, MshhRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Marvel Super Heroes (Brazil 951117)

static struct BurnRomInfo MshbRomDesc[] = {
	{ "mshb.03c",     0x080000, 0x19697f74, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "mshb.04c",     0x080000, 0x95317a6f, 1 | BRF_ESS | BRF_PRG },
	{ "msh.05a",      0x080000, 0xf37539e6, 1 | BRF_ESS | BRF_PRG },
	{ "msh.06b",      0x080000, 0x803e3fa4, 1 | BRF_ESS | BRF_PRG },
	{ "msh.07a",      0x080000, 0xc45f8e27, 1 | BRF_ESS | BRF_PRG },
	{ "msh.08a",      0x080000, 0x9ca6f12c, 1 | BRF_ESS | BRF_PRG },
	{ "msh.09a",      0x080000, 0x82ec27af, 1 | BRF_ESS | BRF_PRG },
	{ "msh.10b",      0x080000, 0x8d931196, 1 | BRF_ESS | BRF_PRG },

	{ "msh.13m",      0x400000, 0x09d14566, 3 | BRF_GRA },
	{ "msh.15m",      0x400000, 0xee962057, 3 | BRF_GRA },
	{ "msh.17m",      0x400000, 0x604ece14, 3 | BRF_GRA },
	{ "msh.19m",      0x400000, 0x94a731e8, 3 | BRF_GRA },
	{ "msh.14m",      0x400000, 0x4197973e, 3 | BRF_GRA },
	{ "msh.16m",      0x400000, 0x438da4a0, 3 | BRF_GRA },
	{ "msh.18m",      0x400000, 0x4db92d94, 3 | BRF_GRA },
	{ "msh.20m",      0x400000, 0xa2b0c6c0, 3 | BRF_GRA },

	{ "msh.01",       0x020000, 0xc976e6f9, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "msh.02",       0x020000, 0xce67d0d9, 4 | BRF_ESS | BRF_PRG },

	{ "msh.11m",      0x200000, 0x37ac6d30, 5 | BRF_SND },
	{ "msh.12m",      0x200000, 0xde092570, 5 | BRF_SND },
};

STD_ROM_PICK(Mshb) STD_ROM_FN(Mshb)

struct BurnDriver BurnDrvCpsMshb = {
	"mshb", "msh", NULL, "1995",
	"Marvel Super Heroes (Brazil 951117)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, MshbRomInfo, MshbRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Marvel Super Heroes vs Street Fighter (Euro 970625)

static struct BurnRomInfo MshvsfRomDesc[] = {
	{ "mvse.03f",     0x080000, 0xb72dc199, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "mvse.04f",     0x080000, 0x6ef799f9, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.05a",      0x080000, 0x1a5de0cb, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.06a",      0x080000, 0x959f3030, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.07b",      0x080000, 0x7f915bdb, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.08a",      0x080000, 0xc2813884, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.09b",      0x080000, 0x3ba08818, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.10b",      0x080000, 0xcf0dba98, 1 | BRF_ESS | BRF_PRG },

	{ "mvs.13m",      0x400000, 0x29b05fd9, 3 | BRF_GRA },
	{ "mvs.15m",      0x400000, 0xfaddccf1, 3 | BRF_GRA },
	{ "mvs.17m",      0x400000, 0x97aaf4c7, 3 | BRF_GRA },
	{ "mvs.19m",      0x400000, 0xcb70e915, 3 | BRF_GRA },
	{ "mvs.14m",      0x400000, 0xb3b1972d, 3 | BRF_GRA },
	{ "mvs.16m",      0x400000, 0x08aadb5d, 3 | BRF_GRA },
	{ "mvs.18m",      0x400000, 0xc1228b35, 3 | BRF_GRA },
	{ "mvs.20m",      0x400000, 0x366cc6c2, 3 | BRF_GRA },

	{ "mvs.01",       0x020000, 0x68252324, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "mvs.02",       0x020000, 0xb34e773d, 4 | BRF_ESS | BRF_PRG },

	{ "mvs.11m",      0x400000, 0x86219770, 5 | BRF_SND },
	{ "mvs.12m",      0x400000, 0xf2fd7f68, 5 | BRF_SND },
};

STD_ROM_PICK(Mshvsf) STD_ROM_FN(Mshvsf)

struct BurnDriver BurnDrvCpsMshvsf = {
	"mshvsf", NULL, NULL, "1997",
	"Marvel Super Heroes vs Street Fighter (Euro 970625)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING,2,HARDWARE_CAPCOM_CPS2,
	NULL, MshvsfRomInfo, MshvsfRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Marvel Super Heroes vs Street Fighter (USA 970827)

static struct BurnRomInfo MshvsfuRomDesc[] = {
	{ "mvsu.03g",     0x080000, 0x0664ab15, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "mvsu.04g",     0x080000, 0x97e060ee, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.05d",      0x080000, 0x921fc542, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.06a",      0x080000, 0x959f3030, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.07b",      0x080000, 0x7f915bdb, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.08a",      0x080000, 0xc2813884, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.09b",      0x080000, 0x3ba08818, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.10b",      0x080000, 0xcf0dba98, 1 | BRF_ESS | BRF_PRG },

	{ "mvs.13m",      0x400000, 0x29b05fd9, 3 | BRF_GRA },
	{ "mvs.15m",      0x400000, 0xfaddccf1, 3 | BRF_GRA },
	{ "mvs.17m",      0x400000, 0x97aaf4c7, 3 | BRF_GRA },
	{ "mvs.19m",      0x400000, 0xcb70e915, 3 | BRF_GRA },
	{ "mvs.14m",      0x400000, 0xb3b1972d, 3 | BRF_GRA },
	{ "mvs.16m",      0x400000, 0x08aadb5d, 3 | BRF_GRA },
	{ "mvs.18m",      0x400000, 0xc1228b35, 3 | BRF_GRA },
	{ "mvs.20m",      0x400000, 0x366cc6c2, 3 | BRF_GRA },

	{ "mvs.01",       0x020000, 0x68252324, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "mvs.02",       0x020000, 0xb34e773d, 4 | BRF_ESS | BRF_PRG },

	{ "mvs.11m",      0x400000, 0x86219770, 5 | BRF_SND },
	{ "mvs.12m",      0x400000, 0xf2fd7f68, 5 | BRF_SND },
};

STD_ROM_PICK(Mshvsfu) STD_ROM_FN(Mshvsfu)

struct BurnDriver BurnDrvCpsMshvsfu = {
	"mshvsfu", "mshvsf", NULL, "1997",
	"Marvel Super Heroes vs Street Fighter (USA 970827)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, MshvsfuRomInfo, MshvsfuRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Marvel Super Heroes vs Street Fighter (USA 970625)

static struct BurnRomInfo Mshvsfu1RomDesc[] = {
	{ "mvsu.03d",     0x080000, 0xae60a66a, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "mvsu.04d",     0x080000, 0x91f67d8a, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.05a",      0x080000, 0x1a5de0cb, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.06a",      0x080000, 0x959f3030, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.07b",      0x080000, 0x7f915bdb, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.08a",      0x080000, 0xc2813884, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.09b",      0x080000, 0x3ba08818, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.10b",      0x080000, 0xcf0dba98, 1 | BRF_ESS | BRF_PRG },

	{ "mvs.13m",      0x400000, 0x29b05fd9, 3 | BRF_GRA },
	{ "mvs.15m",      0x400000, 0xfaddccf1, 3 | BRF_GRA },
	{ "mvs.17m",      0x400000, 0x97aaf4c7, 3 | BRF_GRA },
	{ "mvs.19m",      0x400000, 0xcb70e915, 3 | BRF_GRA },
	{ "mvs.14m",      0x400000, 0xb3b1972d, 3 | BRF_GRA },
	{ "mvs.16m",      0x400000, 0x08aadb5d, 3 | BRF_GRA },
	{ "mvs.18m",      0x400000, 0xc1228b35, 3 | BRF_GRA },
	{ "mvs.20m",      0x400000, 0x366cc6c2, 3 | BRF_GRA },

	{ "mvs.01",       0x020000, 0x68252324, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "mvs.02",       0x020000, 0xb34e773d, 4 | BRF_ESS | BRF_PRG },

	{ "mvs.11m",      0x400000, 0x86219770, 5 | BRF_SND },
	{ "mvs.12m",      0x400000, 0xf2fd7f68, 5 | BRF_SND },
};

STD_ROM_PICK(Mshvsfu1) STD_ROM_FN(Mshvsfu1)

struct BurnDriver BurnDrvCpsMshvsfu1 = {
	"mshvsfu1", "mshvsf", NULL, "1997",
	"Marvel Super Heroes vs Street Fighter (USA 970625)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Mshvsfu1RomInfo, Mshvsfu1RomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Marvel Super Heroes vs Street Fighter (Japan 970707)

static struct BurnRomInfo MshvsfjRomDesc[] = {
	{ "mvsj.03i",     0x080000, 0xd8cbb691, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "mvsj.04i",     0x080000, 0x32741ace, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.05h",      0x080000, 0x77870dc3, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.06a",      0x080000, 0x959f3030, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.07b",      0x080000, 0x7f915bdb, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.08a",      0x080000, 0xc2813884, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.09b",      0x080000, 0x3ba08818, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.10b",      0x080000, 0xcf0dba98, 1 | BRF_ESS | BRF_PRG },

	{ "mvs.13m",      0x400000, 0x29b05fd9, 3 | BRF_GRA },
	{ "mvs.15m",      0x400000, 0xfaddccf1, 3 | BRF_GRA },
	{ "mvs.17m",      0x400000, 0x97aaf4c7, 3 | BRF_GRA },
	{ "mvs.19m",      0x400000, 0xcb70e915, 3 | BRF_GRA },
	{ "mvs.14m",      0x400000, 0xb3b1972d, 3 | BRF_GRA },
	{ "mvs.16m",      0x400000, 0x08aadb5d, 3 | BRF_GRA },
	{ "mvs.18m",      0x400000, 0xc1228b35, 3 | BRF_GRA },
	{ "mvs.20m",      0x400000, 0x366cc6c2, 3 | BRF_GRA },

	{ "mvs.01",       0x020000, 0x68252324, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "mvs.02",       0x020000, 0xb34e773d, 4 | BRF_ESS | BRF_PRG },

	{ "mvs.11m",      0x400000, 0x86219770, 5 | BRF_SND },
	{ "mvs.12m",      0x400000, 0xf2fd7f68, 5 | BRF_SND },
};

STD_ROM_PICK(Mshvsfj) STD_ROM_FN(Mshvsfj)

struct BurnDriver BurnDrvCpsMshvsfj = {
	"mshvsfj", "mshvsf", NULL, "1997",
	"Marvel Super Heroes vs Street Fighter (Japan 970707)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, MshvsfjRomInfo, MshvsfjRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Marvel Super Heroes vs Street Fighter (Japan 970702)

static struct BurnRomInfo Mshvsfj1RomDesc[] = {
	{ "mvsj.03h",     0x080000, 0xfbe2115f, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "mvsj.04h",     0x080000, 0xb528a367, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.05g",      0x080000, 0x9515a245, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.06a",      0x080000, 0x959f3030, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.07b",      0x080000, 0x7f915bdb, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.08a",      0x080000, 0xc2813884, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.09b",      0x080000, 0x3ba08818, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.10b",      0x080000, 0xcf0dba98, 1 | BRF_ESS | BRF_PRG },

	{ "mvs.13m",      0x400000, 0x29b05fd9, 3 | BRF_GRA },
	{ "mvs.15m",      0x400000, 0xfaddccf1, 3 | BRF_GRA },
	{ "mvs.17m",      0x400000, 0x97aaf4c7, 3 | BRF_GRA },
	{ "mvs.19m",      0x400000, 0xcb70e915, 3 | BRF_GRA },
	{ "mvs.14m",      0x400000, 0xb3b1972d, 3 | BRF_GRA },
	{ "mvs.16m",      0x400000, 0x08aadb5d, 3 | BRF_GRA },
	{ "mvs.18m",      0x400000, 0xc1228b35, 3 | BRF_GRA },
	{ "mvs.20m",      0x400000, 0x366cc6c2, 3 | BRF_GRA },

	{ "mvs.01",       0x020000, 0x68252324, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "mvs.02",       0x020000, 0xb34e773d, 4 | BRF_ESS | BRF_PRG },

	{ "mvs.11m",      0x400000, 0x86219770, 5 | BRF_SND },
	{ "mvs.12m",      0x400000, 0xf2fd7f68, 5 | BRF_SND },
};

STD_ROM_PICK(Mshvsfj1) STD_ROM_FN(Mshvsfj1)

struct BurnDriver BurnDrvCpsMshvsfj1 = {
	"mshvsfj1", "mshvsf", NULL, "1997",
	"Marvel Super Heroes vs Street Fighter (Japan 970702)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Mshvsfj1RomInfo, Mshvsfj1RomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Marvel Super Heroes vs Street Fighter (Japan 970625)

static struct BurnRomInfo Mshvsfj2RomDesc[] = {
	{ "mvsj.03g",     0x080000, 0xfdfa7e26, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "mvsj.04g",     0x080000, 0xc921825f, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.05a",      0x080000, 0x1a5de0cb, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.06a",      0x080000, 0x959f3030, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.07b",      0x080000, 0x7f915bdb, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.08a",      0x080000, 0xc2813884, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.09b",      0x080000, 0x3ba08818, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.10b",      0x080000, 0xcf0dba98, 1 | BRF_ESS | BRF_PRG },

	{ "mvs.13m",      0x400000, 0x29b05fd9, 3 | BRF_GRA },
	{ "mvs.15m",      0x400000, 0xfaddccf1, 3 | BRF_GRA },
	{ "mvs.17m",      0x400000, 0x97aaf4c7, 3 | BRF_GRA },
	{ "mvs.19m",      0x400000, 0xcb70e915, 3 | BRF_GRA },
	{ "mvs.14m",      0x400000, 0xb3b1972d, 3 | BRF_GRA },
	{ "mvs.16m",      0x400000, 0x08aadb5d, 3 | BRF_GRA },
	{ "mvs.18m",      0x400000, 0xc1228b35, 3 | BRF_GRA },
	{ "mvs.20m",      0x400000, 0x366cc6c2, 3 | BRF_GRA },

	{ "mvs.01",       0x020000, 0x68252324, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "mvs.02",       0x020000, 0xb34e773d, 4 | BRF_ESS | BRF_PRG },

	{ "mvs.11m",      0x400000, 0x86219770, 5 | BRF_SND },
	{ "mvs.12m",      0x400000, 0xf2fd7f68, 5 | BRF_SND },
};

STD_ROM_PICK(Mshvsfj2) STD_ROM_FN(Mshvsfj2)

struct BurnDriver BurnDrvCpsMshvsfj2 = {
	"mshvsfj2", "mshvsf", NULL, "1997",
	"Marvel Super Heroes vs Street Fighter (Japan 970625)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Mshvsfj2RomInfo, Mshvsfj2RomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Marvel Super Heroes vs Street Fighter (Hispanic 970625)

static struct BurnRomInfo MshvsfhRomDesc[] = {
	{ "mvsh.03f",     0x080000, 0x4f60f41e, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "mvsh.04f",     0x080000, 0xdc08ec12, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.05a",      0x080000, 0x1a5de0cb, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.06a",      0x080000, 0x959f3030, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.07b",      0x080000, 0x7f915bdb, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.08a",      0x080000, 0xc2813884, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.09b",      0x080000, 0x3ba08818, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.10b",      0x080000, 0xcf0dba98, 1 | BRF_ESS | BRF_PRG },

	{ "mvs.13m",      0x400000, 0x29b05fd9, 3 | BRF_GRA },
	{ "mvs.15m",      0x400000, 0xfaddccf1, 3 | BRF_GRA },
	{ "mvs.17m",      0x400000, 0x97aaf4c7, 3 | BRF_GRA },
	{ "mvs.19m",      0x400000, 0xcb70e915, 3 | BRF_GRA },
	{ "mvs.14m",      0x400000, 0xb3b1972d, 3 | BRF_GRA },
	{ "mvs.16m",      0x400000, 0x08aadb5d, 3 | BRF_GRA },
	{ "mvs.18m",      0x400000, 0xc1228b35, 3 | BRF_GRA },
	{ "mvs.20m",      0x400000, 0x366cc6c2, 3 | BRF_GRA },

	{ "mvs.01",       0x020000, 0x68252324, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "mvs.02",       0x020000, 0xb34e773d, 4 | BRF_ESS | BRF_PRG },

	{ "mvs.11m",      0x400000, 0x86219770, 5 | BRF_SND },
	{ "mvs.12m",      0x400000, 0xf2fd7f68, 5 | BRF_SND },
};

STD_ROM_PICK(Mshvsfh) STD_ROM_FN(Mshvsfh)

struct BurnDriver BurnDrvCpsMshvsfh = {
	"mshvsfh", "mshvsf", NULL, "1997",
	"Marvel Super Heroes vs Street Fighter (Hispanic 970625)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, MshvsfhRomInfo, MshvsfhRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Marvel Super Heroes vs Street Fighter (Asia 970625)

static struct BurnRomInfo MshvsfaRomDesc[] = {
	{ "mvsa.03d",     0x080000, 0x5b863716, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "mvsa.04d",     0x080000, 0x4886e65f, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.05a",      0x080000, 0x1a5de0cb, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.06a",      0x080000, 0x959f3030, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.07b",      0x080000, 0x7f915bdb, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.08a",      0x080000, 0xc2813884, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.09b",      0x080000, 0x3ba08818, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.10b",      0x080000, 0xcf0dba98, 1 | BRF_ESS | BRF_PRG },

	{ "mvs.13m",      0x400000, 0x29b05fd9, 3 | BRF_GRA },
	{ "mvs.15m",      0x400000, 0xfaddccf1, 3 | BRF_GRA },
	{ "mvs.17m",      0x400000, 0x97aaf4c7, 3 | BRF_GRA },
	{ "mvs.19m",      0x400000, 0xcb70e915, 3 | BRF_GRA },
	{ "mvs.14m",      0x400000, 0xb3b1972d, 3 | BRF_GRA },
	{ "mvs.16m",      0x400000, 0x08aadb5d, 3 | BRF_GRA },
	{ "mvs.18m",      0x400000, 0xc1228b35, 3 | BRF_GRA },
	{ "mvs.20m",      0x400000, 0x366cc6c2, 3 | BRF_GRA },

	{ "mvs.01",       0x020000, 0x68252324, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "mvs.02",       0x020000, 0xb34e773d, 4 | BRF_ESS | BRF_PRG },

	{ "mvs.11m",      0x400000, 0x86219770, 5 | BRF_SND },
	{ "mvs.12m",      0x400000, 0xf2fd7f68, 5 | BRF_SND },
};

STD_ROM_PICK(Mshvsfa) STD_ROM_FN(Mshvsfa)

struct BurnDriver BurnDrvCpsMshvsfa = {
	"mshvsfa", "mshvsf", NULL, "1997",
	"Marvel Super Heroes vs Street Fighter (Asia 970625)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, MshvsfaRomInfo, MshvsfaRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Marvel Super Heroes vs Street Fighter (Asia 970620)

static struct BurnRomInfo Mshvsfa1RomDesc[] = {
	{ "mvsa.03",      0x080000, 0x92ef1933, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "mvsa.04",      0x080000, 0x4b24373c, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.05",       0x080000, 0xac180c1c, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.06a",      0x080000, 0x959f3030, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.07b",      0x080000, 0x7f915bdb, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.08a",      0x080000, 0xc2813884, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.09b",      0x080000, 0x3ba08818, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.10b",      0x080000, 0xcf0dba98, 1 | BRF_ESS | BRF_PRG },

	{ "mvs.13m",      0x400000, 0x29b05fd9, 3 | BRF_GRA },
	{ "mvs.15m",      0x400000, 0xfaddccf1, 3 | BRF_GRA },
	{ "mvs.17m",      0x400000, 0x97aaf4c7, 3 | BRF_GRA },
	{ "mvs.19m",      0x400000, 0xcb70e915, 3 | BRF_GRA },
	{ "mvs.14m",      0x400000, 0xb3b1972d, 3 | BRF_GRA },
	{ "mvs.16m",      0x400000, 0x08aadb5d, 3 | BRF_GRA },
	{ "mvs.18m",      0x400000, 0xc1228b35, 3 | BRF_GRA },
	{ "mvs.20m",      0x400000, 0x366cc6c2, 3 | BRF_GRA },

	{ "mvs.01",       0x020000, 0x68252324, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "mvs.02",       0x020000, 0xb34e773d, 4 | BRF_ESS | BRF_PRG },

	{ "mvs.11m",      0x400000, 0x86219770, 5 | BRF_SND },
	{ "mvs.12m",      0x400000, 0xf2fd7f68, 5 | BRF_SND },
};

STD_ROM_PICK(Mshvsfa1) STD_ROM_FN(Mshvsfa1)

struct BurnDriver BurnDrvCpsMshvsfa1 = {
	"mshvsfa1", "mshvsf", NULL, "1997",
	"Marvel Super Heroes vs Street Fighter (Asia 970620)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Mshvsfa1RomInfo, Mshvsfa1RomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Marvel Super Heroes vs Street Fighter (Brazil 970827)

static struct BurnRomInfo MshvsfbRomDesc[] = {
	{ "mvsb.03g",     0x080000, 0x143895ef, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "mvsb.04g",     0x080000, 0xdd8a886c, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.05d",      0x080000, 0x921fc542, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.06a",      0x080000, 0x959f3030, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.07b",      0x080000, 0x7f915bdb, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.08a",      0x080000, 0xc2813884, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.09b",      0x080000, 0x3ba08818, 1 | BRF_ESS | BRF_PRG },
	{ "mvs.10b",      0x080000, 0xcf0dba98, 1 | BRF_ESS | BRF_PRG },

	{ "mvs.13m",      0x400000, 0x29b05fd9, 3 | BRF_GRA },
	{ "mvs.15m",      0x400000, 0xfaddccf1, 3 | BRF_GRA },
	{ "mvs.17m",      0x400000, 0x97aaf4c7, 3 | BRF_GRA },
	{ "mvs.19m",      0x400000, 0xcb70e915, 3 | BRF_GRA },
	{ "mvs.14m",      0x400000, 0xb3b1972d, 3 | BRF_GRA },
	{ "mvs.16m",      0x400000, 0x08aadb5d, 3 | BRF_GRA },
	{ "mvs.18m",      0x400000, 0xc1228b35, 3 | BRF_GRA },
	{ "mvs.20m",      0x400000, 0x366cc6c2, 3 | BRF_GRA },

	{ "mvs.01",       0x020000, 0x68252324, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "mvs.02",       0x020000, 0xb34e773d, 4 | BRF_ESS | BRF_PRG },

	{ "mvs.11m",      0x400000, 0x86219770, 5 | BRF_SND },
	{ "mvs.12m",      0x400000, 0xf2fd7f68, 5 | BRF_SND },
};

STD_ROM_PICK(Mshvsfb) STD_ROM_FN(Mshvsfb)

struct BurnDriver BurnDrvCpsMshvsfb = {
	"mshvsfb", "mshvsf", NULL, "1997",
	"Marvel Super Heroes vs Street Fighter (Brazil 970827)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, MshvsfbRomInfo, MshvsfbRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Marvel Super Heroes vs Street Fighter (Brazil 970625)

static struct BurnRomInfo Mshvsfb1RomDesc[] = {
	{"mvsb.03f",	  0x080000, 0x9c4bb950, 1 | BRF_ESS | BRF_PRG},		// 68k program
	{"mvsb.04f",	  0x080000, 0xd3320d13, 1 | BRF_ESS | BRF_PRG},
	{"mvs.05a",	  0x080000, 0x1a5de0cb, 1 | BRF_ESS | BRF_PRG},
	{"mvs.06a",	  0x080000, 0x959f3030, 1 | BRF_ESS | BRF_PRG},
	{"mvs.07b",	  0x080000, 0x7f915bdb, 1 | BRF_ESS | BRF_PRG},
	{"mvs.08a",	  0x080000, 0xc2813884, 1 | BRF_ESS | BRF_PRG},
	{"mvs.09b",	  0x080000, 0x3ba08818, 1 | BRF_ESS | BRF_PRG},
	{"mvs.10b",	  0x080000, 0xcf0dba98, 1 | BRF_ESS | BRF_PRG},

	{ "mvs.13m",      0x400000, 0x29b05fd9, 3 | BRF_GRA },
	{ "mvs.15m",      0x400000, 0xfaddccf1, 3 | BRF_GRA },
	{ "mvs.17m",      0x400000, 0x97aaf4c7, 3 | BRF_GRA },
	{ "mvs.19m",      0x400000, 0xcb70e915, 3 | BRF_GRA },
	{ "mvs.14m",      0x400000, 0xb3b1972d, 3 | BRF_GRA },
	{ "mvs.16m",      0x400000, 0x08aadb5d, 3 | BRF_GRA },
	{ "mvs.18m",      0x400000, 0xc1228b35, 3 | BRF_GRA },
	{ "mvs.20m",      0x400000, 0x366cc6c2, 3 | BRF_GRA },

	{ "mvs.01",       0x020000, 0x68252324, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "mvs.02",       0x020000, 0xb34e773d, 4 | BRF_ESS | BRF_PRG },

	{ "mvs.11m",      0x400000, 0x86219770, 5 | BRF_SND },
	{ "mvs.12m",      0x400000, 0xf2fd7f68, 5 | BRF_SND },
};

STD_ROM_PICK(Mshvsfb1) STD_ROM_FN(Mshvsfb1)

struct BurnDriver BurnDrvCpsMshvsfb1 = {
	"mshvsfb1", "mshvsf", NULL, "1997",
	"Marvel Super Heroes vs Street Fighter (Brazil 970625)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Mshvsfb1RomInfo, Mshvsfb1RomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// FBA Combo - extra players input hack
// kDropped = which players got dropped during netplay
#ifndef SN_TARGET_PS3
static void MshvsfDrv4pInputSwap()
{
	static bool bInit = false;
	unsigned char pDropped = kDropped;
	unsigned char nInputSwap = 0x00; // default = don't swap

	if (SekReadByte(0xFF2492) == 1) {
		bInit = true;
	}
	if (bInit) {
		if (!(pDropped&0x02) && SekReadByte(0xFF4983) > 0) {
			nInputSwap |= 0x02; // p2 controls p1
		}
		if (!(pDropped&0x08) && SekReadByte(0xFF49A3) > 0) {
			nInputSwap |= 0x08; // p4 controls p2
		}
		if (SekReadByte(0xFF2492) == 0) {
			bInit = false;
			nInputSwap = 0x00; // back to default
		}
	} else {
		if (!(pDropped&0x02) && SekReadByte(0xFF3A61) == 1) {
			nInputSwap |= 0x02; // p2 controls p1
		}
		if (!(pDropped&0x08) && SekReadByte(0xFF3E61) == 1) {
			nInputSwap |= 0x08; // p4 controls p2
		}
	}

	if (pDropped&0x04 && !(pDropped&0x08)) {
		nInputSwap |= 0x08; // p4 controls p2
	}

	CpsDrv4pSwap(nInputSwap);
}
#endif

// FBA Combo - extra players input hack
#ifndef SN_TARGET_PS3
static int MshvsfDrv4pInit()
{
	bInputSwap = true;
	kDropped = 0x00;
	BurnDrvInputSwap = MshvsfDrv4pInputSwap;
	return Cps2Init();
}
#endif

// FBA Combo - extra players input hack
#ifndef SN_TARGET_PS3
static int MshvsfDrv4pExit()
{
	bInputSwap = false;
	kDropped = 0x00;
	BurnDrvInputSwap = NULL;
	return CpsExit();
}
#endif

#ifndef SN_TARGET_PS3
struct BurnDriver BurnDrvCpsMshvsf4p = {
	"mshvsf4p", "mshvsf", NULL, "1997",
	"Marvel Super Heroes vs Street Fighter (Euro 970625 / 4 Players)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,4,HARDWARE_CAPCOM_CPS2,
	NULL, MshvsfRomInfo, MshvsfRomName, Drv4pInputInfo, NULL,
	MshvsfDrv4pInit, MshvsfDrv4pExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};

struct BurnDriver BurnDrvCpsMshvsfu4p = {
	"mshvsfu4p", "mshvsf", "mshvsfu", "1997",
	"Marvel Super Heroes vs Street Fighter (USA 970827 / 4 Players)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,4,HARDWARE_CAPCOM_CPS2,
	NULL, MshvsfuRomInfo, MshvsfuRomName, Drv4pInputInfo, NULL,
	MshvsfDrv4pInit, MshvsfDrv4pExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};

struct BurnDriver BurnDrvCpsMshvsfj4p = {
	"mshvsfj4p", "mshvsf", "mshvsfj", "1997",
	"Marvel Super Heroes vs Street Fighter (Japan 970707 / 4 Players)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,4,HARDWARE_CAPCOM_CPS2,
	NULL, MshvsfjRomInfo, MshvsfjRomName, Drv4pInputInfo, NULL,
	MshvsfDrv4pInit, MshvsfDrv4pExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};

struct BurnDriver BurnDrvCpsMshvsfa4p = {
	"mshvsfa4p", "mshvsf", "mshvsfa", "1997",
	"Marvel Super Heroes vs Street Fighter (Asia 970625 / 4 Players)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,4,HARDWARE_CAPCOM_CPS2,
	NULL, MshvsfaRomInfo, MshvsfaRomName, Drv4pInputInfo, NULL,
	MshvsfDrv4pInit, MshvsfDrv4pExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};
#endif


// Marvel Vs. Capcom: Clash of Super Heroes (Euro 980123)

static struct BurnRomInfo MvscRomDesc[] = {
	{ "mvce.03a",     0x080000, 0x824e4a90, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "mvce.04a",     0x080000, 0xcac02153, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.05a",      0x080000, 0x2d8c8e86, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.06a",      0x080000, 0x8528e1f5, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.07",       0x080000, 0xc3baa32b, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.08",       0x080000, 0xbc002fcd, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.09",       0x080000, 0xc67b26df, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.10",       0x080000, 0x0fdd1e26, 1 | BRF_ESS | BRF_PRG },

	{ "mvc.13m",      0x400000, 0xfa5f74bc, 3 | BRF_GRA },
	{ "mvc.15m",      0x400000, 0x71938a8f, 3 | BRF_GRA },
	{ "mvc.17m",      0x400000, 0x92741d07, 3 | BRF_GRA },
	{ "mvc.19m",      0x400000, 0xbcb72fc6, 3 | BRF_GRA },
	{ "mvc.14m",      0x400000, 0x7f1df4e4, 3 | BRF_GRA },
	{ "mvc.16m",      0x400000, 0x90bd3203, 3 | BRF_GRA },
	{ "mvc.18m",      0x400000, 0x67aaf727, 3 | BRF_GRA },
	{ "mvc.20m",      0x400000, 0x8b0bade8, 3 | BRF_GRA },

	{ "mvc.01",       0x020000, 0x41629e95, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "mvc.02",       0x020000, 0x963abf6b, 4 | BRF_ESS | BRF_PRG },

	{ "mvc.11m",      0x400000, 0x850fe663, 5 | BRF_SND },
	{ "mvc.12m",      0x400000, 0x7ccb1896, 5 | BRF_SND },
};

STD_ROM_PICK(Mvsc) STD_ROM_FN(Mvsc)

struct BurnDriver BurnDrvCpsMvsc = {
	"mvsc", NULL, NULL, "1998",
	"Marvel Vs. Capcom: Clash of Super Heroes (Euro 980123)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING,2,HARDWARE_CAPCOM_CPS2,
	NULL, MvscRomInfo, MvscRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Marvel Vs. Capcom: Clash of Super Heroes (Euro 980112)

static struct BurnRomInfo Mvscr1RomDesc[] = {
	{ "mvce.03",      0x080000, 0xe0633fc0, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "mvce.04",      0x080000, 0xa450a251, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.05",       0x080000, 0x7db71ce9, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.06",       0x080000, 0x4b0b6d3e, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.07",       0x080000, 0xc3baa32b, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.08",       0x080000, 0xbc002fcd, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.09",       0x080000, 0xc67b26df, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.10",       0x080000, 0x0fdd1e26, 1 | BRF_ESS | BRF_PRG },

	{ "mvc.13m",      0x400000, 0xfa5f74bc, 3 | BRF_GRA },
	{ "mvc.15m",      0x400000, 0x71938a8f, 3 | BRF_GRA },
	{ "mvc.17m",      0x400000, 0x92741d07, 3 | BRF_GRA },
	{ "mvc.19m",      0x400000, 0xbcb72fc6, 3 | BRF_GRA },
	{ "mvc.14m",      0x400000, 0x7f1df4e4, 3 | BRF_GRA },
	{ "mvc.16m",      0x400000, 0x90bd3203, 3 | BRF_GRA },
	{ "mvc.18m",      0x400000, 0x67aaf727, 3 | BRF_GRA },
	{ "mvc.20m",      0x400000, 0x8b0bade8, 3 | BRF_GRA },

	{ "mvc.01",       0x020000, 0x41629e95, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "mvc.02",       0x020000, 0x963abf6b, 4 | BRF_ESS | BRF_PRG },

	{ "mvc.11m",      0x400000, 0x850fe663, 5 | BRF_SND },
	{ "mvc.12m",      0x400000, 0x7ccb1896, 5 | BRF_SND },
};

STD_ROM_PICK(Mvscr1) STD_ROM_FN(Mvscr1)

struct BurnDriver BurnDrvCpsMvscr1 = {
	"mvscr1", "mvsc", NULL, "1998",
	"Marvel Vs. Capcom: Clash of Super Heroes (Euro 980112)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Mvscr1RomInfo, Mvscr1RomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Marvel Vs. Capcom: Clash of Super Heroes (USA 980123)

static struct BurnRomInfo MvscuRomDesc[] = {
	{ "mvcu.03d",     0x080000, 0xc6007557, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "mvcu.04d",     0x080000, 0x724b2b20, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.05a",      0x080000, 0x2d8c8e86, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.06a",      0x080000, 0x8528e1f5, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.07",       0x080000, 0xc3baa32b, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.08",       0x080000, 0xbc002fcd, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.09",       0x080000, 0xc67b26df, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.10",       0x080000, 0x0fdd1e26, 1 | BRF_ESS | BRF_PRG },

	{ "mvc.13m",      0x400000, 0xfa5f74bc, 3 | BRF_GRA },
	{ "mvc.15m",      0x400000, 0x71938a8f, 3 | BRF_GRA },
	{ "mvc.17m",      0x400000, 0x92741d07, 3 | BRF_GRA },
	{ "mvc.19m",      0x400000, 0xbcb72fc6, 3 | BRF_GRA },
	{ "mvc.14m",      0x400000, 0x7f1df4e4, 3 | BRF_GRA },
	{ "mvc.16m",      0x400000, 0x90bd3203, 3 | BRF_GRA },
	{ "mvc.18m",      0x400000, 0x67aaf727, 3 | BRF_GRA },
	{ "mvc.20m",      0x400000, 0x8b0bade8, 3 | BRF_GRA },

	{ "mvc.01",       0x020000, 0x41629e95, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "mvc.02",       0x020000, 0x963abf6b, 4 | BRF_ESS | BRF_PRG },

	{ "mvc.11m",      0x400000, 0x850fe663, 5 | BRF_SND },
	{ "mvc.12m",      0x400000, 0x7ccb1896, 5 | BRF_SND },
};

STD_ROM_PICK(Mvscu) STD_ROM_FN(Mvscu)

struct BurnDriver BurnDrvCpsMvscu = {
	"mvscu", "mvsc", NULL, "1998",
	"Marvel Vs. Capcom: Clash of Super Heroes (USA 980123)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, MvscuRomInfo, MvscuRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Marvel Vs. Capcom: Clash of Super Heroes (Japan 980123)

static struct BurnRomInfo MvscjRomDesc[] = {
	{ "mvcj.03a",     0x080000, 0x3df18879, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "mvcj.04a",     0x080000, 0x07d212e8, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.05a",      0x080000, 0x2d8c8e86, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.06a",      0x080000, 0x8528e1f5, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.07",       0x080000, 0xc3baa32b, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.08",       0x080000, 0xbc002fcd, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.09",       0x080000, 0xc67b26df, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.10",       0x080000, 0x0fdd1e26, 1 | BRF_ESS | BRF_PRG },

	{ "mvc.13m",      0x400000, 0xfa5f74bc, 3 | BRF_GRA },
	{ "mvc.15m",      0x400000, 0x71938a8f, 3 | BRF_GRA },
	{ "mvc.17m",      0x400000, 0x92741d07, 3 | BRF_GRA },
	{ "mvc.19m",      0x400000, 0xbcb72fc6, 3 | BRF_GRA },
	{ "mvc.14m",      0x400000, 0x7f1df4e4, 3 | BRF_GRA },
	{ "mvc.16m",      0x400000, 0x90bd3203, 3 | BRF_GRA },
	{ "mvc.18m",      0x400000, 0x67aaf727, 3 | BRF_GRA },
	{ "mvc.20m",      0x400000, 0x8b0bade8, 3 | BRF_GRA },

	{ "mvc.01",       0x020000, 0x41629e95, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "mvc.02",       0x020000, 0x963abf6b, 4 | BRF_ESS | BRF_PRG },

	{ "mvc.11m",      0x400000, 0x850fe663, 5 | BRF_SND },
	{ "mvc.12m",      0x400000, 0x7ccb1896, 5 | BRF_SND },
};

STD_ROM_PICK(Mvscj) STD_ROM_FN(Mvscj)

struct BurnDriver BurnDrvCpsMvscj = {
	"mvscj", "mvsc", NULL, "1998",
	"Marvel Vs. Capcom: Clash of Super Heroes (Japan 980123)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, MvscjRomInfo, MvscjRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Marvel Vs. Capcom: Clash of Super Heroes (Japan 980112)

static struct BurnRomInfo Mvscjr1RomDesc[] = {
	{ "mvcj.03",      0x080000, 0x2164213f, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "mvcj.04",      0x080000, 0xc905c86f, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.05",       0x080000, 0x7db71ce9, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.06",       0x080000, 0x4b0b6d3e, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.07",       0x080000, 0xc3baa32b, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.08",       0x080000, 0xbc002fcd, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.09",       0x080000, 0xc67b26df, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.10",       0x080000, 0x0fdd1e26, 1 | BRF_ESS | BRF_PRG },

	{ "mvc.13m",      0x400000, 0xfa5f74bc, 3 | BRF_GRA },
	{ "mvc.15m",      0x400000, 0x71938a8f, 3 | BRF_GRA },
	{ "mvc.17m",      0x400000, 0x92741d07, 3 | BRF_GRA },
	{ "mvc.19m",      0x400000, 0xbcb72fc6, 3 | BRF_GRA },
	{ "mvc.14m",      0x400000, 0x7f1df4e4, 3 | BRF_GRA },
	{ "mvc.16m",      0x400000, 0x90bd3203, 3 | BRF_GRA },
	{ "mvc.18m",      0x400000, 0x67aaf727, 3 | BRF_GRA },
	{ "mvc.20m",      0x400000, 0x8b0bade8, 3 | BRF_GRA },

	{ "mvc.01",       0x020000, 0x41629e95, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "mvc.02",       0x020000, 0x963abf6b, 4 | BRF_ESS | BRF_PRG },

	{ "mvc.11m",      0x400000, 0x850fe663, 5 | BRF_SND },
	{ "mvc.12m",      0x400000, 0x7ccb1896, 5 | BRF_SND },
};

STD_ROM_PICK(Mvscjr1) STD_ROM_FN(Mvscjr1)

struct BurnDriver BurnDrvCpsMvscjr1 = {
	"mvscjr1", "mvsc", NULL, "1998",
	"Marvel Vs. Capcom: Clash of Super Heroes (Japan 980112)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Mvscjr1RomInfo, Mvscjr1RomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Marvel Vs. Capcom: Clash of Super Heroes (Asia 980123)

static struct BurnRomInfo MvscaRomDesc[] = {
	{ "mvca.03a",	  0x080000, 0x2ff4ae25, 1 | BRF_ESS | BRF_PRG},		// 68k program
	{ "mvca.04a",	  0x080000, 0xf28427ef, 1 | BRF_ESS | BRF_PRG},
	{ "mvc.05a",	  0x080000, 0x2d8c8e86, 1 | BRF_ESS | BRF_PRG},
	{ "mvc.06a",	  0x080000, 0x8528e1f5, 1 | BRF_ESS | BRF_PRG},
	{ "mvc.07",	  0x080000, 0xc3baa32b, 1 | BRF_ESS | BRF_PRG},
	{ "mvc.08",	  0x080000, 0xbc002fcd, 1 | BRF_ESS | BRF_PRG},
	{ "mvc.09",	  0x080000, 0xc67b26df, 1 | BRF_ESS | BRF_PRG},
	{ "mvc.10",	  0x080000, 0x0fdd1e26, 1 | BRF_ESS | BRF_PRG},

	{ "mvc.13m",      0x400000, 0xfa5f74bc, 3 | BRF_GRA },
	{ "mvc.15m",      0x400000, 0x71938a8f, 3 | BRF_GRA },
	{ "mvc.17m",      0x400000, 0x92741d07, 3 | BRF_GRA },
	{ "mvc.19m",      0x400000, 0xbcb72fc6, 3 | BRF_GRA },
	{ "mvc.14m",      0x400000, 0x7f1df4e4, 3 | BRF_GRA },
	{ "mvc.16m",      0x400000, 0x90bd3203, 3 | BRF_GRA },
	{ "mvc.18m",      0x400000, 0x67aaf727, 3 | BRF_GRA },
	{ "mvc.20m",      0x400000, 0x8b0bade8, 3 | BRF_GRA },

	{ "mvc.01",       0x020000, 0x41629e95, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "mvc.02",       0x020000, 0x963abf6b, 4 | BRF_ESS | BRF_PRG },

	{ "mvc.11m",      0x400000, 0x850fe663, 5 | BRF_SND },
	{ "mvc.12m",      0x400000, 0x7ccb1896, 5 | BRF_SND },
};

STD_ROM_PICK(Mvsca) STD_ROM_FN(Mvsca)

struct BurnDriver BurnDrvCpsMvsca = {
	"mvsca", "mvsc", NULL, "1998",
	"Marvel Vs. Capcom: Clash of Super Heroes (Asia 980123)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, MvscaRomInfo, MvscaRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Marvel Vs. Capcom: Clash of Super Heroes (Asia 980112)

static struct BurnRomInfo Mvscar1RomDesc[] = {
	{ "mvca.03",      0x080000, 0xfe5fa7b9, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "mvca.04",      0x080000, 0x082b701c, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.05",       0x080000, 0x7db71ce9, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.06",       0x080000, 0x4b0b6d3e, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.07",       0x080000, 0xc3baa32b, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.08",       0x080000, 0xbc002fcd, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.09",       0x080000, 0xc67b26df, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.10",       0x080000, 0x0fdd1e26, 1 | BRF_ESS | BRF_PRG },

	{ "mvc.13m",      0x400000, 0xfa5f74bc, 3 | BRF_GRA },
	{ "mvc.15m",      0x400000, 0x71938a8f, 3 | BRF_GRA },
	{ "mvc.17m",      0x400000, 0x92741d07, 3 | BRF_GRA },
	{ "mvc.19m",      0x400000, 0xbcb72fc6, 3 | BRF_GRA },
	{ "mvc.14m",      0x400000, 0x7f1df4e4, 3 | BRF_GRA },
	{ "mvc.16m",      0x400000, 0x90bd3203, 3 | BRF_GRA },
	{ "mvc.18m",      0x400000, 0x67aaf727, 3 | BRF_GRA },
	{ "mvc.20m",      0x400000, 0x8b0bade8, 3 | BRF_GRA },

	{ "mvc.01",       0x020000, 0x41629e95, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "mvc.02",       0x020000, 0x963abf6b, 4 | BRF_ESS | BRF_PRG },

	{ "mvc.11m",      0x400000, 0x850fe663, 5 | BRF_SND },
	{ "mvc.12m",      0x400000, 0x7ccb1896, 5 | BRF_SND },
};

STD_ROM_PICK(Mvscar1) STD_ROM_FN(Mvscar1)

struct BurnDriver BurnDrvCpsMvscar1 = {
	"mvscar1", "mvsc", NULL, "1998",
	"Marvel Vs. Capcom: Clash of Super Heroes (Asia 980112)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Mvscar1RomInfo, Mvscar1RomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Marvel Vs. Capcom: Clash of Super Heroes (Hispanic 980123)

static struct BurnRomInfo MvschRomDesc[] = {
	{ "mvch.03",      0x080000, 0x6a0ec9f7, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "mvch.04",      0x080000, 0x00f03fa4, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.05a",      0x080000, 0x2d8c8e86, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.06a",      0x080000, 0x8528e1f5, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.07",       0x080000, 0xc3baa32b, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.08",       0x080000, 0xbc002fcd, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.09",       0x080000, 0xc67b26df, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.10",       0x080000, 0x0fdd1e26, 1 | BRF_ESS | BRF_PRG },

	{ "mvc.13m",      0x400000, 0xfa5f74bc, 3 | BRF_GRA },
	{ "mvc.15m",      0x400000, 0x71938a8f, 3 | BRF_GRA },
	{ "mvc.17m",      0x400000, 0x92741d07, 3 | BRF_GRA },
	{ "mvc.19m",      0x400000, 0xbcb72fc6, 3 | BRF_GRA },
	{ "mvc.14m",      0x400000, 0x7f1df4e4, 3 | BRF_GRA },
	{ "mvc.16m",      0x400000, 0x90bd3203, 3 | BRF_GRA },
	{ "mvc.18m",      0x400000, 0x67aaf727, 3 | BRF_GRA },
	{ "mvc.20m",      0x400000, 0x8b0bade8, 3 | BRF_GRA },

	{ "mvc.01",       0x020000, 0x41629e95, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "mvc.02",       0x020000, 0x963abf6b, 4 | BRF_ESS | BRF_PRG },

	{ "mvc.11m",      0x400000, 0x850fe663, 5 | BRF_SND },
	{ "mvc.12m",      0x400000, 0x7ccb1896, 5 | BRF_SND },
};

STD_ROM_PICK(Mvsch) STD_ROM_FN(Mvsch)

struct BurnDriver BurnDrvCpsMvsch = {
	"mvsch", "mvsc", NULL, "1998",
	"Marvel Vs. Capcom: Clash of Super Heroes (Hispanic 980123)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, MvschRomInfo, MvschRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Marvel Vs. Capcom: Clash of Super Heroes (Brazil 980123)

static struct BurnRomInfo MvscbRomDesc[] = {
	{ "mvcb.03a",	  0x080000, 0x7155953b, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "mvcb.04a",	  0x080000, 0xfb117d0e, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.05a",	  0x080000, 0x2d8c8e86, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.06a",	  0x080000, 0x8528e1f5, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.07",       0x080000, 0xc3baa32b, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.08",       0x080000, 0xbc002fcd, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.09",       0x080000, 0xc67b26df, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.10",       0x080000, 0x0fdd1e26, 1 | BRF_ESS | BRF_PRG },

	{ "mvc.13m",      0x400000, 0xfa5f74bc, 3 | BRF_GRA },
	{ "mvc.15m",      0x400000, 0x71938a8f, 3 | BRF_GRA },
	{ "mvc.17m",      0x400000, 0x92741d07, 3 | BRF_GRA },
	{ "mvc.19m",      0x400000, 0xbcb72fc6, 3 | BRF_GRA },
	{ "mvc.14m",      0x400000, 0x7f1df4e4, 3 | BRF_GRA },
	{ "mvc.16m",      0x400000, 0x90bd3203, 3 | BRF_GRA },
	{ "mvc.18m",      0x400000, 0x67aaf727, 3 | BRF_GRA },
	{ "mvc.20m",      0x400000, 0x8b0bade8, 3 | BRF_GRA },

	{ "mvc.01",       0x020000, 0x41629e95, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "mvc.02",       0x020000, 0x963abf6b, 4 | BRF_ESS | BRF_PRG },

	{ "mvc.11m",      0x400000, 0x850fe663, 5 | BRF_SND },
	{ "mvc.12m",      0x400000, 0x7ccb1896, 5 | BRF_SND },
};

STD_ROM_PICK(Mvscb) STD_ROM_FN(Mvscb)

struct BurnDriver BurnDrvCpsMvscb = {
	"mvscb", "mvsc", NULL, "1998",
	"Marvel Vs. Capcom: Clash of Super Heroes (Brazil 980123)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, MvscbRomInfo, MvscbRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Marvel vs. Capcom: Clash of Super Heroes (USA 980123, Phoenix Edition)

static struct BurnRomInfo MvscudRomDesc[] = {
	{ "mvcud.03d",    0x80000, 0x75cde3e5, 1 | BRF_ESS | BRF_PRG },
	{ "mvcud.04d",    0x80000, 0xb32ea484, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.05a",      0x80000, 0x2d8c8e86, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.06a",      0x80000, 0x8528e1f5, 1 | BRF_ESS | BRF_PRG },
	{ "mvcd.07",      0x80000, 0x205293e9, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.08",       0x80000, 0xbc002fcd, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.09",       0x80000, 0xc67b26df, 1 | BRF_ESS | BRF_PRG },
	{ "mvc.10",       0x80000, 0x0fdd1e26, 1 | BRF_ESS | BRF_PRG },

	{ "mvc.13m",      0x400000, 0xfa5f74bc, 3 | BRF_GRA },
	{ "mvc.15m",      0x400000, 0x71938a8f, 3 | BRF_GRA },
	{ "mvc.17m",      0x400000, 0x92741d07, 3 | BRF_GRA },
	{ "mvc.19m",      0x400000, 0xbcb72fc6, 3 | BRF_GRA },
	{ "mvc.14m",      0x400000, 0x7f1df4e4, 3 | BRF_GRA },
	{ "mvc.16m",      0x400000, 0x90bd3203, 3 | BRF_GRA },
	{ "mvc.18m",      0x400000, 0x67aaf727, 3 | BRF_GRA },
	{ "mvc.20m",      0x400000, 0x8b0bade8, 3 | BRF_GRA },

	{ "mvc.01",       0x020000, 0x41629e95, 4 | BRF_ESS | BRF_PRG },
	{ "mvc.02",       0x020000, 0x963abf6b, 4 | BRF_ESS | BRF_PRG },

	{ "mvc.11m",      0x400000, 0x850fe663, 5 | BRF_SND },
	{ "mvc.12m",      0x400000, 0x7ccb1896, 5 | BRF_SND },
};

STD_ROM_PICK(Mvscud) STD_ROM_FN(Mvscud)

struct BurnDriver BurnDrvCpsMvscud = {
	"mvscud", "mvsc", NULL, "1998",
	"Marvel vs. Capcom: Clash of Super Heroes (USA 980123, Phoenix Edition)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE | BDF_BOOTLEG,2,HARDWARE_CAPCOM_CPS2,
	NULL, MvscudRomInfo, MvscudRomName, DrvInputInfo, NULL,
	PhoenixInit, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// FBA Combo - extra players input hack
// kDropped = which players got dropped during netplay
#ifndef SN_TARGET_PS3
static void MvscDrv4pInputSwap()
{
	static bool bInit = false;
	unsigned char pDropped = kDropped;
	unsigned char nInputSwap = 0x00; // default = don't swap

	if (SekReadByte(0xFF5C2B) == 1) {
		bInit = true;
	}
	if (bInit) {
		if (!(pDropped&0x02) && SekReadByte(0xFF5E4C) > 0) {
			nInputSwap |= 0x02; // p2 controls p1
		}
		if (!(pDropped&0x08) && SekReadByte(0xFF5DDC) > 0) {
			nInputSwap |= 0x08; // p4 controls p2
		}
		if (SekReadByte(0xFF5C2B) == 0) {
			bInit = false;
			nInputSwap = 0x00; // back to default
		}
	} else {
		if (!(pDropped&0x02) && SekReadByte(0xFF3A81) == 0) {
			nInputSwap |= 0x02; // p2 controls p1
		}
		if (!(pDropped&0x08) && SekReadByte(0xFF3E81) == 0) {
			nInputSwap |= 0x08; // p4 controls p2
		}
	}

	if (pDropped&0x04 && !(pDropped&0x08)) {
		nInputSwap |= 0x08; // p4 controls p2
	}

	CpsDrv4pSwap(nInputSwap);
}
#endif

// FBA Combo - extra players input hack
#ifndef SN_TARGET_PS3
static int MvscDrv4pInit()
{
	bInputSwap = true;
	kDropped = 0x00;
	BurnDrvInputSwap = MvscDrv4pInputSwap;
	return Cps2Init();
}
#endif

// FBA Combo - extra players input hack
#ifndef SN_TARGET_PS3
static int MvscDrv4pExit()
{
	bInputSwap = false;
	kDropped = 0x00;
	BurnDrvInputSwap = NULL;
	return CpsExit();
}
#endif

#ifndef SN_TARGET_PS3
struct BurnDriver BurnDrvCpsMvsc4p = {
	"mvsc4p", "mvsc", NULL, "1998",
	"Marvel Vs. Capcom: Clash of Super Heroes (Euro 980123 / 4 Players)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,4,HARDWARE_CAPCOM_CPS2,
	NULL, MvscRomInfo, MvscRomName, Drv4pInputInfo, NULL,
	MvscDrv4pInit, MvscDrv4pExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};

struct BurnDriver BurnDrvCpsMvscu4p = {
	"mvscu4p", "mvsc", "mvscu", "1998",
	"Marvel Vs. Capcom: Clash of Super Heroes (USA 980123 / 4 Players)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,4,HARDWARE_CAPCOM_CPS2,
	NULL, MvscuRomInfo, MvscuRomName, Drv4pInputInfo, NULL,
	MvscDrv4pInit, MvscDrv4pExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};

struct BurnDriver BurnDrvCpsMvscj4p = {
	"mvscj4p", "mvsc", "mvscj", "1998",
	"Marvel Vs. Capcom: Clash of Super Heroes (Japan 980123 / 4 Players)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,4,HARDWARE_CAPCOM_CPS2,
	NULL, MvscjRomInfo, MvscjRomName, Drv4pInputInfo, NULL,
	MvscDrv4pInit, MvscDrv4pExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};

struct BurnDriver BurnDrvCpsMvsca4p = {
	"mvsca4p", "mvsc", "mvsca", "1998",
	"Marvel Vs. Capcom: Clash of Super Heroes (Asia 980123 / 4 Players)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,4,HARDWARE_CAPCOM_CPS2,
	NULL, MvscaRomInfo, MvscaRomName, Drv4pInputInfo, NULL,
	MvscDrv4pInit, MvscDrv4pExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};
#endif


// Mighty! Pang (Euro 001010)

static struct BurnRomInfo mpangRomDesc[] = {
	{ "mpne.03c",     0x080000, 0xfe16fc9f, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "mpne.04c",     0x080000, 0x2cc5ec22, 1 | BRF_ESS | BRF_PRG },

	{ "mpn-simm.01c", 0x200000, 0x388DB66B, 11 | BRF_GRA },
	{ "mpn-simm.01d", 0x200000, 0xAFF1B494, 11 | BRF_GRA },
	{ "mpn-simm.01a", 0x200000, 0xA9C4857B, 11 | BRF_GRA },
	{ "mpn-simm.01b", 0x200000, 0xF759DF22, 11 | BRF_GRA },
	{ "mpn-simm.03c", 0x200000, 0xDEC6B720, 11 | BRF_GRA },
	{ "mpn-simm.03d", 0x200000, 0xF8774C18, 11 | BRF_GRA },
	{ "mpn-simm.03a", 0x200000, 0xC2AEA4EC, 11 | BRF_GRA },
	{ "mpn-simm.03b", 0x200000, 0x84D6DC33, 11 | BRF_GRA },

	{ "mpn.01",       0x020000, 0x90C7ADB6,  4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "mpn-simm.05a", 0x200000, 0x318A2E21, 13 | BRF_SND },
	{ "mpn-simm.05b", 0x200000, 0x5462F4E8, 13 | BRF_SND },
};

STD_ROM_PICK(mpang) STD_ROM_FN(mpang)

struct BurnDriver BurnDrvCpsMPang = {
	"mpang", NULL, NULL, "2000",
	"Mighty! Pang (Euro 001010)\0", NULL, "Mitchell", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING, 2, HARDWARE_CAPCOM_CPS2 | HARDWARE_CAPCOM_CPS2_SIMM,
	NULL, mpangRomInfo, mpangRomName, mpangInputInfo, NULL,
	Cps2Init,CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Mighty! Pang (Euro 000925)

static struct BurnRomInfo mpangr1RomDesc[] = {
	{ "mpne.03b",     0x080000, 0x6ef0f9b2, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "mpne.04b",     0x080000, 0x30a468bb, 1 | BRF_ESS | BRF_PRG },

	{ "mpn-simm.01c", 0x200000, 0x388DB66B, 11 | BRF_GRA },
	{ "mpn-simm.01d", 0x200000, 0xAFF1B494, 11 | BRF_GRA },
	{ "mpn-simm.01a", 0x200000, 0xA9C4857B, 11 | BRF_GRA },
	{ "mpn-simm.01b", 0x200000, 0xF759DF22, 11 | BRF_GRA },
	{ "mpn-simm.03c", 0x200000, 0xDEC6B720, 11 | BRF_GRA },
	{ "mpn-simm.03d", 0x200000, 0xF8774C18, 11 | BRF_GRA },
	{ "mpn-simm.03a", 0x200000, 0xC2AEA4EC, 11 | BRF_GRA },
	{ "mpn-simm.03b", 0x200000, 0x84D6DC33, 11 | BRF_GRA },

	{ "mpn.01",       0x020000, 0x90C7ADB6,  4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "mpn-simm.05a", 0x200000, 0x318A2E21, 13 | BRF_SND },
	{ "mpn-simm.05b", 0x200000, 0x5462F4E8, 13 | BRF_SND },
};

STD_ROM_PICK(mpangr1) STD_ROM_FN(mpangr1)

struct BurnDriver BurnDrvCpsMpangr1 = {
	"mpangr1", "mpang", NULL, "2000",
	"Mighty! Pang (Euro 000925)\0", NULL, "Mitchell", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE, 2, HARDWARE_CAPCOM_CPS2 | HARDWARE_CAPCOM_CPS2_SIMM,
	NULL, mpangr1RomInfo, mpangr1RomName, mpangInputInfo, NULL,
	Cps2Init,CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Mighty! Pang (USA 001010)

static struct BurnRomInfo mpanguRomDesc[] = {
	{ "mpnu.03",      0x080000, 0x6e7ed03c, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "mpnu.04",      0x080000, 0xde079131, 1 | BRF_ESS | BRF_PRG },

	{ "mpn.13m",	  0x200000, 0xc5f123dc, 3 | BRF_GRA },
	{ "mpn.15m",	  0x200000, 0x8e033265, 3 | BRF_GRA },
	{ "mpn.17m",	  0x200000, 0xcfcd73d2, 3 | BRF_GRA },
	{ "mpn.19m",	  0x200000, 0x2db1ffbc, 3 | BRF_GRA },

	{ "mpn.01",       0x020000, 0x90C7ADB6, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "mpn.q1",	  0x100000, 0xd21c1f5a, 5 | BRF_SND },
	{ "mpn.q2",	  0x100000, 0xd22090b1, 5 | BRF_SND },
	{ "mpn.q3",	  0x100000, 0x60aa5ef2, 5 | BRF_SND },
	{ "mpn.q4",	  0x100000, 0x3a67d203, 5 | BRF_SND },
};

STD_ROM_PICK(mpangu) STD_ROM_FN(mpangu)

struct BurnDriver BurnDrvCpsMPangu = {
	"mpangu", "mpang", NULL, "2000",
	"Mighty! Pang (USA 001010)\0", NULL, "Mitchell", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE, 2, HARDWARE_CAPCOM_CPS2,
	NULL, mpanguRomInfo, mpanguRomName, mpangInputInfo, NULL,
	Cps2Init,CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Mighty! Pang (Japan 001011)

static struct BurnRomInfo mpangjRomDesc[] = {
	{ "mpnj.03a",     0x080000, 0xBF597b1C,  1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "mpnj.04a",     0x080000, 0xF4A3AB0F,  1 | BRF_ESS | BRF_PRG },

	{ "mpn-simm.01c", 0x200000, 0x388DB66B, 11 | BRF_GRA },
	{ "mpn-simm.01d", 0x200000, 0xAFF1B494, 11 | BRF_GRA },
	{ "mpn-simm.01a", 0x200000, 0xA9C4857B, 11 | BRF_GRA },
	{ "mpn-simm.01b", 0x200000, 0xF759DF22, 11 | BRF_GRA },
	{ "mpn-simm.03c", 0x200000, 0xDEC6B720, 11 | BRF_GRA },
	{ "mpn-simm.03d", 0x200000, 0xF8774C18, 11 | BRF_GRA },
	{ "mpn-simm.03a", 0x200000, 0xC2AEA4EC, 11 | BRF_GRA },
	{ "mpn-simm.03b", 0x200000, 0x84D6DC33, 11 | BRF_GRA },

	{ "mpn.01",       0x020000, 0x90C7ADB6,  4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "mpn-simm.05a", 0x200000, 0x318A2E21, 13 | BRF_SND },
	{ "mpn-simm.05b", 0x200000, 0x5462F4E8, 13 | BRF_SND },
};

STD_ROM_PICK(mpangj) STD_ROM_FN(mpangj)

struct BurnDriver BurnDrvCpsMPangj = {
	"mpangj", "mpang", NULL, "2000",
	"Mighty! Pang (Japan 001011)\0", NULL, "Mitchell", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE, 2, HARDWARE_CAPCOM_CPS2 | HARDWARE_CAPCOM_CPS2_SIMM,
	NULL, mpangjRomInfo, mpangjRomName, mpangInputInfo, NULL,
	Cps2Init,CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Night Warriors: Darkstalkers' Revenge (Euro 950316)

static struct BurnRomInfo NwarrRomDesc[] = {
	{ "vphe.03f",     0x080000, 0xa922c44f, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "vphe.04c",     0x080000, 0x7312d890, 1 | BRF_ESS | BRF_PRG },
	{ "vphe.05d",     0x080000, 0xcde8b506, 1 | BRF_ESS | BRF_PRG },
	{ "vphe.06c",     0x080000, 0xbe99e7d0, 1 | BRF_ESS | BRF_PRG },
	{ "vphe.07b",     0x080000, 0x69e0e60c, 1 | BRF_ESS | BRF_PRG },
	{ "vphe.08b",     0x080000, 0xd95a3849, 1 | BRF_ESS | BRF_PRG },
	{ "vphe.09b",     0x080000, 0x9882561c, 1 | BRF_ESS | BRF_PRG },
	{ "vphe.10b",     0x080000, 0x976fa62f, 1 | BRF_ESS | BRF_PRG },

	{ "vph.13m",      0x400000, 0xc51baf99, 3 | BRF_GRA },
	{ "vph.15m",      0x400000, 0x3ce83c77, 3 | BRF_GRA },
	{ "vph.17m",      0x400000, 0x4f2408e0, 3 | BRF_GRA },
	{ "vph.19m",      0x400000, 0x9ff60250, 3 | BRF_GRA },
	{ "vph.14m",      0x400000, 0x7a0e1add, 3 | BRF_GRA },
	{ "vph.16m",      0x400000, 0x2f41ca75, 3 | BRF_GRA },
	{ "vph.18m",      0x400000, 0x64498eed, 3 | BRF_GRA },
	{ "vph.20m",      0x400000, 0x17f2433f, 3 | BRF_GRA },

	{ "vph.01",       0x020000, 0x5045dcac, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "vph.02",       0x020000, 0x86b60e59, 4 | BRF_ESS | BRF_PRG },

	{ "vph.11m",      0x200000, 0xe1837d33, 5 | BRF_SND },
	{ "vph.12m",      0x200000, 0xfbd3cd90, 5 | BRF_SND },
};

STD_ROM_PICK(Nwarr) STD_ROM_FN(Nwarr)

struct BurnDriver BurnDrvCpsNwarr = {
	"nwarr", NULL, NULL, "1995",
	"Night Warriors: Darkstalkers' Revenge (Euro 950316)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING,2,HARDWARE_CAPCOM_CPS2,
	NULL, NwarrRomInfo, NwarrRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Night Warriors: Darkstalkers' Revenge (USA 950406)

static struct BurnRomInfo NwarruRomDesc[] = {
	{ "vphu.03f",     0x080000, 0x85d6a359, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "vphu.04c",     0x080000, 0xcb7fce77, 1 | BRF_ESS | BRF_PRG },
	{ "vphu.05e",     0x080000, 0xe08f2bba, 1 | BRF_ESS | BRF_PRG },
	{ "vphu.06c",     0x080000, 0x08c04cdb, 1 | BRF_ESS | BRF_PRG },
	{ "vphu.07b",     0x080000, 0xb5a5ab19, 1 | BRF_ESS | BRF_PRG },
	{ "vphu.08b",     0x080000, 0x51bb20fb, 1 | BRF_ESS | BRF_PRG },
	{ "vphu.09b",     0x080000, 0x41a64205, 1 | BRF_ESS | BRF_PRG },
	{ "vphu.10b",     0x080000, 0x2b1d43ae, 1 | BRF_ESS | BRF_PRG },

	{ "vph.13m",      0x400000, 0xc51baf99, 3 | BRF_GRA },
	{ "vph.15m",      0x400000, 0x3ce83c77, 3 | BRF_GRA },
	{ "vph.17m",      0x400000, 0x4f2408e0, 3 | BRF_GRA },
	{ "vph.19m",      0x400000, 0x9ff60250, 3 | BRF_GRA },
	{ "vph.14m",      0x400000, 0x7a0e1add, 3 | BRF_GRA },
	{ "vph.16m",      0x400000, 0x2f41ca75, 3 | BRF_GRA },
	{ "vph.18m",      0x400000, 0x64498eed, 3 | BRF_GRA },
	{ "vph.20m",      0x400000, 0x17f2433f, 3 | BRF_GRA },

	{ "vph.01",       0x020000, 0x5045dcac, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "vph.02",       0x020000, 0x86b60e59, 4 | BRF_ESS | BRF_PRG },

	{ "vph.11m",      0x200000, 0xe1837d33, 5 | BRF_SND },
	{ "vph.12m",      0x200000, 0xfbd3cd90, 5 | BRF_SND },
};

STD_ROM_PICK(Nwarru) STD_ROM_FN(Nwarru)

struct BurnDriver BurnDrvCpsNwarru = {
	"nwarru", "nwarr", NULL, "1995",
	"Night Warriors: Darkstalkers' Revenge (USA 950406)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, NwarruRomInfo, NwarruRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Night Warriors: Darkstalkers' Revenge (Asia 950302)

static struct BurnRomInfo NwarraRomDesc[] = {
	{ "vpha.03b",     0x080000, 0x0a70cdd6, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "vpha.04b",     0x080000, 0x70ce62e4, 1 | BRF_ESS | BRF_PRG },
	{ "vpha.05b",     0x080000, 0x5692a03f, 1 | BRF_ESS | BRF_PRG },
	{ "vpha.06b",     0x080000, 0xb810fe66, 1 | BRF_ESS | BRF_PRG },
	{ "vpha.07b",     0x080000, 0x1be264f3, 1 | BRF_ESS | BRF_PRG },
	{ "vpha.08b",     0x080000, 0x86f1ed52, 1 | BRF_ESS | BRF_PRG },
	{ "vpha.09b",     0x080000, 0x7e96bd0a, 1 | BRF_ESS | BRF_PRG },
	{ "vpha.10b",     0x080000, 0x58bce2fd, 1 | BRF_ESS | BRF_PRG },

	{ "vph.13m",      0x400000, 0xc51baf99, 3 | BRF_GRA },
	{ "vph.15m",      0x400000, 0x3ce83c77, 3 | BRF_GRA },
	{ "vph.17m",      0x400000, 0x4f2408e0, 3 | BRF_GRA },
	{ "vph.19m",      0x400000, 0x9ff60250, 3 | BRF_GRA },
	{ "vph.14m",      0x400000, 0x7a0e1add, 3 | BRF_GRA },
	{ "vph.16m",      0x400000, 0x2f41ca75, 3 | BRF_GRA },
	{ "vph.18m",      0x400000, 0x64498eed, 3 | BRF_GRA },
	{ "vph.20m",      0x400000, 0x17f2433f, 3 | BRF_GRA },

	{ "vph.01",       0x020000, 0x5045dcac, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "vph.02",       0x020000, 0x86b60e59, 4 | BRF_ESS | BRF_PRG },

	{ "vph.11m",      0x200000, 0xe1837d33, 5 | BRF_SND },
	{ "vph.12m",      0x200000, 0xfbd3cd90, 5 | BRF_SND },
};

STD_ROM_PICK(Nwarra) STD_ROM_FN(Nwarra)

struct BurnDriver BurnDrvCpsNwarra = {
	"nwarra", "nwarr", NULL, "1995",
	"Night Warriors: Darkstalkers' Revenge (Asia 950302)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, NwarraRomInfo, NwarraRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Night Warriors: Darkstalkers' Revenge (Hispanic 950403)

static struct BurnRomInfo NwarrhRomDesc[] = {
	{ "vphh.03d",     0x080000, 0x6029c7be, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "vphh.04a",     0x080000, 0xd26625ee, 1 | BRF_ESS | BRF_PRG },
	{ "vphh.05c",     0x080000, 0x73ee0b8a, 1 | BRF_ESS | BRF_PRG },
	{ "vphh.06a",     0x080000, 0xa5b3a50a, 1 | BRF_ESS | BRF_PRG },
	{ "vphh.07",      0x080000, 0x5fc2bdc1, 1 | BRF_ESS | BRF_PRG },
	{ "vphh.08",      0x080000, 0xe65588d9, 1 | BRF_ESS | BRF_PRG },
	{ "vphh.09",      0x080000, 0xa2ce6d63, 1 | BRF_ESS | BRF_PRG },
	{ "vphh.10",      0x080000, 0xe2f4f4b9, 1 | BRF_ESS | BRF_PRG },

	{ "vph.13m",      0x400000, 0xc51baf99, 3 | BRF_GRA },
	{ "vph.15m",      0x400000, 0x3ce83c77, 3 | BRF_GRA },
	{ "vph.17m",      0x400000, 0x4f2408e0, 3 | BRF_GRA },
	{ "vph.19m",      0x400000, 0x9ff60250, 3 | BRF_GRA },
	{ "vph.14m",      0x400000, 0x7a0e1add, 3 | BRF_GRA },
	{ "vph.16m",      0x400000, 0x2f41ca75, 3 | BRF_GRA },
	{ "vph.18m",      0x400000, 0x64498eed, 3 | BRF_GRA },
	{ "vph.20m",      0x400000, 0x17f2433f, 3 | BRF_GRA },

	{ "vph.01",       0x020000, 0x5045dcac, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "vph.02",       0x020000, 0x86b60e59, 4 | BRF_ESS | BRF_PRG },

	{ "vph.11m",      0x200000, 0xe1837d33, 5 | BRF_SND },
	{ "vph.12m",      0x200000, 0xfbd3cd90, 5 | BRF_SND },
};

STD_ROM_PICK(Nwarrh) STD_ROM_FN(Nwarrh)

struct BurnDriver BurnDrvCpsNwarrh = {
	"nwarrh", "nwarr", NULL, "1995",
	"Night Warriors: Darkstalkers' Revenge (Hispanic 950403)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, NwarrhRomInfo, NwarrhRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Night Warriors: Darkstalkers' Revenge (Brazil 950403)

static struct BurnRomInfo NwarrbRomDesc[] = {
	{ "vphb.03d",     0x080000, 0x3a426d3f, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "vphb.04a",     0x080000, 0x51c4bb2f, 1 | BRF_ESS | BRF_PRG },
	{ "vphb.05c",     0x080000, 0xac44d997, 1 | BRF_ESS | BRF_PRG },
	{ "vphb.06a",     0x080000, 0x5072a5fe, 1 | BRF_ESS | BRF_PRG },
	{ "vphb.07",      0x080000, 0x9b355192, 1 | BRF_ESS | BRF_PRG },
	{ "vphb.08",      0x080000, 0x42220f84, 1 | BRF_ESS | BRF_PRG },
	{ "vphb.09",      0x080000, 0x029e015d, 1 | BRF_ESS | BRF_PRG },
	{ "vphb.10",      0x080000, 0x37b3ce37, 1 | BRF_ESS | BRF_PRG },

	{ "vph.13m",      0x400000, 0xc51baf99, 3 | BRF_GRA },
	{ "vph.15m",      0x400000, 0x3ce83c77, 3 | BRF_GRA },
	{ "vph.17m",      0x400000, 0x4f2408e0, 3 | BRF_GRA },
	{ "vph.19m",      0x400000, 0x9ff60250, 3 | BRF_GRA },
	{ "vph.14m",      0x400000, 0x7a0e1add, 3 | BRF_GRA },
	{ "vph.16m",      0x400000, 0x2f41ca75, 3 | BRF_GRA },
	{ "vph.18m",      0x400000, 0x64498eed, 3 | BRF_GRA },
	{ "vph.20m",      0x400000, 0x17f2433f, 3 | BRF_GRA },

	{ "vph.01",       0x020000, 0x5045dcac, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "vph.02",       0x020000, 0x86b60e59, 4 | BRF_ESS | BRF_PRG },

	{ "vph.11m",      0x200000, 0xe1837d33, 5 | BRF_SND },
	{ "vph.12m",      0x200000, 0xfbd3cd90, 5 | BRF_SND },
};

STD_ROM_PICK(Nwarrb) STD_ROM_FN(Nwarrb)

struct BurnDriver BurnDrvCpsNwarrb = {
	"nwarrb", "nwarr", NULL, "1995",
	"Night Warriors: Darkstalkers' Revenge (Brazil 950403)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, NwarrbRomInfo, NwarrbRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Vampire Hunter: Darkstalkers' Revenge (Japan 950316)

static struct BurnRomInfo VhuntjRomDesc[] = {
	{ "vphj.03f",     0x080000, 0x3de2e333, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "vphj.04c",     0x080000, 0xc95cf304, 1 | BRF_ESS | BRF_PRG },
	{ "vphj.05d",     0x080000, 0x50de5ddd, 1 | BRF_ESS | BRF_PRG },
	{ "vphj.06c",     0x080000, 0xac3bd3d5, 1 | BRF_ESS | BRF_PRG },
	{ "vphj.07b",     0x080000, 0x0761309f, 1 | BRF_ESS | BRF_PRG },
	{ "vphj.08b",     0x080000, 0x5a5c2bf5, 1 | BRF_ESS | BRF_PRG },
	{ "vphj.09b",     0x080000, 0x823d6d99, 1 | BRF_ESS | BRF_PRG },
	{ "vphj.10b",     0x080000, 0x32c7d8f0, 1 | BRF_ESS | BRF_PRG },

	{ "vph.13m",      0x400000, 0xc51baf99, 3 | BRF_GRA },
	{ "vph.15m",      0x400000, 0x3ce83c77, 3 | BRF_GRA },
	{ "vph.17m",      0x400000, 0x4f2408e0, 3 | BRF_GRA },
	{ "vph.19m",      0x400000, 0x9ff60250, 3 | BRF_GRA },
	{ "vph.14m",      0x400000, 0x7a0e1add, 3 | BRF_GRA },
	{ "vph.16m",      0x400000, 0x2f41ca75, 3 | BRF_GRA },
	{ "vph.18m",      0x400000, 0x64498eed, 3 | BRF_GRA },
	{ "vph.20m",      0x400000, 0x17f2433f, 3 | BRF_GRA },

	{ "vph.01",       0x020000, 0x5045dcac, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "vph.02",       0x020000, 0x86b60e59, 4 | BRF_ESS | BRF_PRG },

	{ "vph.11m",      0x200000, 0xe1837d33, 5 | BRF_SND },
	{ "vph.12m",      0x200000, 0xfbd3cd90, 5 | BRF_SND },
};

STD_ROM_PICK(Vhuntj) STD_ROM_FN(Vhuntj)

struct BurnDriver BurnDrvCpsVhuntj = {
	"vhuntj", "nwarr", NULL, "1995",
	"Vampire Hunter: Darkstalkers' Revenge (Japan 950316)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, VhuntjRomInfo, VhuntjRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Vampire Hunter: Darkstalkers' Revenge (Japan 950307)

static struct BurnRomInfo Vhuntjr1RomDesc[] = {
	{ "vphj.03c",	  0x080000, 0x606b682a, 1 | BRF_ESS | BRF_PRG},		// 68k program
	{ "vphj.04b",	  0x080000, 0xa3b40393, 1 | BRF_ESS | BRF_PRG},
	{ "vphj.05b",	  0x080000, 0xfccd5558, 1 | BRF_ESS | BRF_PRG},
	{ "vphj.06b",	  0x080000, 0x07e10a73, 1 | BRF_ESS | BRF_PRG},
	{ "vphj.07b",	  0x080000, 0x0761309f, 1 | BRF_ESS | BRF_PRG},
	{ "vphj.08b",	  0x080000, 0x5a5c2bf5, 1 | BRF_ESS | BRF_PRG},
	{ "vphj.09b",	  0x080000, 0x823d6d99, 1 | BRF_ESS | BRF_PRG},
	{ "vphj.10b",	  0x080000, 0x32c7d8f0, 1 | BRF_ESS | BRF_PRG},

	{ "vph.13m",      0x400000, 0xc51baf99, 3 | BRF_GRA },
	{ "vph.15m",      0x400000, 0x3ce83c77, 3 | BRF_GRA },
	{ "vph.17m",      0x400000, 0x4f2408e0, 3 | BRF_GRA },
	{ "vph.19m",      0x400000, 0x9ff60250, 3 | BRF_GRA },
	{ "vph.14m",      0x400000, 0x7a0e1add, 3 | BRF_GRA },
	{ "vph.16m",      0x400000, 0x2f41ca75, 3 | BRF_GRA },
	{ "vph.18m",      0x400000, 0x64498eed, 3 | BRF_GRA },
	{ "vph.20m",      0x400000, 0x17f2433f, 3 | BRF_GRA },

	{ "vph.01",       0x020000, 0x5045dcac, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "vph.02",       0x020000, 0x86b60e59, 4 | BRF_ESS | BRF_PRG },

	{ "vph.11m",      0x200000, 0xe1837d33, 5 | BRF_SND },
	{ "vph.12m",      0x200000, 0xfbd3cd90, 5 | BRF_SND },
};

STD_ROM_PICK(Vhuntjr1) STD_ROM_FN(Vhuntjr1)

struct BurnDriver BurnDrvCpsVhuntjr1 = {
	"vhuntjr1", "nwarr", NULL, "1995",
	"Vampire Hunter: Darkstalkers' Revenge (Japan 950307)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Vhuntjr1RomInfo, Vhuntjr1RomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Vampire Hunter: Darkstalkers' Revenge (Japan 950302)

static struct BurnRomInfo Vhuntjr2RomDesc[] = {
	{ "vphj.03b",     0x080000, 0x679c3fa9, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "vphj.04a",     0x080000, 0xeb6e71e4, 1 | BRF_ESS | BRF_PRG },
	{ "vphj.05a",     0x080000, 0xeaf634ea, 1 | BRF_ESS | BRF_PRG },
	{ "vphj.06a",     0x080000, 0xb70cc6be, 1 | BRF_ESS | BRF_PRG },
	{ "vphj.07a",     0x080000, 0x46ab907d, 1 | BRF_ESS | BRF_PRG },
	{ "vphj.08a",     0x080000, 0x1c00355e, 1 | BRF_ESS | BRF_PRG },
	{ "vphj.09a",     0x080000, 0x026e6f82, 1 | BRF_ESS | BRF_PRG },
	{ "vphj.10a",     0x080000, 0xaadfb3ea, 1 | BRF_ESS | BRF_PRG },

	{ "vph.13m",      0x400000, 0xc51baf99, 3 | BRF_GRA },
	{ "vph.15m",      0x400000, 0x3ce83c77, 3 | BRF_GRA },
	{ "vph.17m",      0x400000, 0x4f2408e0, 3 | BRF_GRA },
	{ "vph.19m",      0x400000, 0x9ff60250, 3 | BRF_GRA },
	{ "vph.14m",      0x400000, 0x7a0e1add, 3 | BRF_GRA },
	{ "vph.16m",      0x400000, 0x2f41ca75, 3 | BRF_GRA },
	{ "vph.18m",      0x400000, 0x64498eed, 3 | BRF_GRA },
	{ "vph.20m",      0x400000, 0x17f2433f, 3 | BRF_GRA },

	{ "vph.01",       0x020000, 0x5045dcac, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "vph.02",       0x020000, 0x86b60e59, 4 | BRF_ESS | BRF_PRG },

	{ "vph.11m",      0x200000, 0xe1837d33, 5 | BRF_SND },
	{ "vph.12m",      0x200000, 0xfbd3cd90, 5 | BRF_SND },
};

STD_ROM_PICK(Vhuntjr2) STD_ROM_FN(Vhuntjr2)

struct BurnDriver BurnDrvCpsVhuntjr2 = {
	"vhuntjr2", "nwarr", NULL, "1995",
	"Vampire Hunter: Darkstalkers' Revenge (Japan 950302)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Vhuntjr2RomInfo, Vhuntjr2RomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Night Warriors: Darkstalkers' Revenge (USA 950406, Phoenix Edition)

static struct BurnRomInfo NwarrudRomDesc[] = {
	{ "vphud.03f",    0x080000, 0x20d4d5a8, 1 | BRF_ESS | BRF_PRG },
	{ "vphud.04c",    0x080000, 0x61be9b42, 1 | BRF_ESS | BRF_PRG },
	{ "vphud.05e",    0x080000, 0x1ba906d8, 1 | BRF_ESS | BRF_PRG },
	{ "vphu.06c",     0x080000, 0x08c04cdb, 1 | BRF_ESS | BRF_PRG },
	{ "vphu.07b",     0x080000, 0xb5a5ab19, 1 | BRF_ESS | BRF_PRG },
	{ "vphu.08b",     0x080000, 0x51bb20fb, 1 | BRF_ESS | BRF_PRG },
	{ "vphu.09b",     0x080000, 0x41a64205, 1 | BRF_ESS | BRF_PRG },
	{ "vphud.10b",    0x080000, 0x9619adad, 1 | BRF_ESS | BRF_PRG },

	{ "vph.13m",      0x400000, 0xc51baf99, 3 | BRF_GRA },
	{ "vph.15m",      0x400000, 0x3ce83c77, 3 | BRF_GRA },
	{ "vph.17m",      0x400000, 0x4f2408e0, 3 | BRF_GRA },
	{ "vph.19m",      0x400000, 0x9ff60250, 3 | BRF_GRA },
	{ "vph.14m",      0x400000, 0x7a0e1add, 3 | BRF_GRA },
	{ "vph.16m",      0x400000, 0x2f41ca75, 3 | BRF_GRA },
	{ "vph.18m",      0x400000, 0x64498eed, 3 | BRF_GRA },
	{ "vph.20m",      0x400000, 0x17f2433f, 3 | BRF_GRA },

	{ "vph.01",       0x020000, 0x5045dcac, 4 | BRF_ESS | BRF_PRG },
	{ "vph.02",       0x020000, 0x86b60e59, 4 | BRF_ESS | BRF_PRG },

	{ "vph.11m",      0x200000, 0xe1837d33, 5 | BRF_SND },
	{ "vph.12m",      0x200000, 0xfbd3cd90, 5 | BRF_SND },
};

STD_ROM_PICK(Nwarrud) STD_ROM_FN(Nwarrud)

struct BurnDriver BurnDrvCpsNwarrud = {
	"nwarrud", "nwarr", NULL, "1995",
	"Night Warriors: Darkstalkers' Revenge (USA 950406, Phoenix Edition)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE | BDF_BOOTLEG,2,HARDWARE_CAPCOM_CPS2,
	NULL, NwarrudRomInfo, NwarrudRomName, DrvInputInfo, NULL,
	PhoenixInit, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Progear (USA 010117)

static struct BurnRomInfo progearRomDesc[] = {
	{ "pgau.03",      0x080000, 0x343A783E,  1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "pgau.04",      0x080000, 0x16208D79,  1 | BRF_ESS | BRF_PRG },

	{ "pga-simm.01c", 0x200000, 0x452F98B0, 11 | BRF_GRA },
	{ "pga-simm.01d", 0x200000, 0x9E672092, 11 | BRF_GRA },
	{ "pga-simm.01a", 0x200000, 0xAE9DDAFE, 11 | BRF_GRA },
	{ "pga-simm.01b", 0x200000, 0x94D72D94, 11 | BRF_GRA },
	{ "pga-simm.03c", 0x200000, 0x48A1886D, 11 | BRF_GRA },
	{ "pga-simm.03d", 0x200000, 0x172D7E37, 11 | BRF_GRA },
	{ "pga-simm.03a", 0x200000, 0x9EE33D98, 11 | BRF_GRA },
	{ "pga-simm.03b", 0x200000, 0x848DEE32, 11 | BRF_GRA },

	{ "pga.01",       0x020000, 0xBDBFA992,  4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "pga-simm.05a", 0x200000, 0xC0AAC80C, 13 | BRF_SND },
	{ "pga-simm.05b", 0x200000, 0x37A65D86, 13 | BRF_SND },
	{ "pga-simm.06a", 0x200000, 0xD3F1E934, 13 | BRF_SND },
	{ "pga-simm.06b", 0x200000, 0x8B39489A, 13 | BRF_SND },
};

STD_ROM_PICK(progear) STD_ROM_FN(progear)

struct BurnDriver BurnDrvCpsProgear = {
	"progear", NULL, NULL, "2001",
	"Progear (USA 010117)\0", NULL, "Capcom / Cave", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING, 2, HARDWARE_CAPCOM_CPS2 | HARDWARE_CAPCOM_CPS2_SIMM,
	NULL, progearRomInfo, progearRomName, progearInputInfo, NULL,
	Cps2Init,CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Progear (Asia 010117)

static struct BurnRomInfo progearaRomDesc[] = {
	{ "pgaa.03",      0x080000, 0x25E6E2CE,  1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "pgaa.04",      0x080000, 0x8104307E,  1 | BRF_ESS | BRF_PRG },

	{ "pga-simm.01c", 0x200000, 0x452F98B0, 11 | BRF_GRA },
	{ "pga-simm.01d", 0x200000, 0x9E672092, 11 | BRF_GRA },
	{ "pga-simm.01a", 0x200000, 0xAE9DDAFE, 11 | BRF_GRA },
	{ "pga-simm.01b", 0x200000, 0x94D72D94, 11 | BRF_GRA },
	{ "pga-simm.03c", 0x200000, 0x48A1886D, 11 | BRF_GRA },
	{ "pga-simm.03d", 0x200000, 0x172D7E37, 11 | BRF_GRA },
	{ "pga-simm.03a", 0x200000, 0x9EE33D98, 11 | BRF_GRA },
	{ "pga-simm.03b", 0x200000, 0x848DEE32, 11 | BRF_GRA },

	{ "pga.01",       0x020000, 0xBDBFA992,  4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "pga-simm.05a", 0x200000, 0xC0AAC80C, 13 | BRF_SND },
	{ "pga-simm.05b", 0x200000, 0x37A65D86, 13 | BRF_SND },
	{ "pga-simm.06a", 0x200000, 0xD3F1E934, 13 | BRF_SND },
	{ "pga-simm.06b", 0x200000, 0x8B39489A, 13 | BRF_SND },
};

STD_ROM_PICK(progeara) STD_ROM_FN(progeara)

struct BurnDriver BurnDrvCpsProgeara = {
	"progeara", "progear", NULL, "2001",
	"Progear (Asia 010117)\0", NULL, "Capcom / Cave", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE, 2, HARDWARE_CAPCOM_CPS2 | HARDWARE_CAPCOM_CPS2_SIMM,
	NULL, progearaRomInfo, progearaRomName, progearInputInfo, NULL,
	Cps2Init,CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Progear No Arashi (Japan 010117)

static struct BurnRomInfo progearjRomDesc[] = {
	{ "pgaj.03",      0x080000, 0x06DBBA54,  1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "pgaj.04",      0x080000, 0xA1F1F1BC,  1 | BRF_ESS | BRF_PRG },

	{ "pga-simm.01c", 0x200000, 0x452F98B0, 11 | BRF_GRA },
	{ "pga-simm.01d", 0x200000, 0x9E672092, 11 | BRF_GRA },
	{ "pga-simm.01a", 0x200000, 0xAE9DDAFE, 11 | BRF_GRA },
	{ "pga-simm.01b", 0x200000, 0x94D72D94, 11 | BRF_GRA },
	{ "pga-simm.03c", 0x200000, 0x48A1886D, 11 | BRF_GRA },
	{ "pga-simm.03d", 0x200000, 0x172D7E37, 11 | BRF_GRA },
	{ "pga-simm.03a", 0x200000, 0x9EE33D98, 11 | BRF_GRA },
	{ "pga-simm.03b", 0x200000, 0x848DEE32, 11 | BRF_GRA },

	{ "pga.01",       0x020000, 0xBDBFA992,  4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "pga-simm.05a", 0x200000, 0xC0AAC80C, 13 | BRF_SND },
	{ "pga-simm.05b", 0x200000, 0x37A65D86, 13 | BRF_SND },
	{ "pga-simm.06a", 0x200000, 0xD3F1E934, 13 | BRF_SND },
	{ "pga-simm.06b", 0x200000, 0x8B39489A, 13 | BRF_SND },
};

STD_ROM_PICK(progearj) STD_ROM_FN(progearj)

struct BurnDriver BurnDrvCpsProgearj = {
	"progearj", "progear", NULL, "2001",
	"Progear no Arashi (Japan 010117)\0", NULL, "Capcom / Cave", "CPS2",
	L"\u30D7\u30ED\u30AE\u30A2\u306E\u5D50 (Progear no Arashi Japan 010117)\0", NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE, 2, HARDWARE_CAPCOM_CPS2 | HARDWARE_CAPCOM_CPS2_SIMM,
	NULL, progearjRomInfo, progearjRomName, progearInputInfo, NULL,
	Cps2Init,CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Progear No Arashi (Japan 010117, Phoenix Edition)

static struct BurnRomInfo progerjdRomDesc[] = {
	{ "pgajd.03",     0x080000, 0x4FEF676C,  1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "pgajd.04",     0x080000, 0xA069BD3B,  1 | BRF_ESS | BRF_PRG },

	{ "pga-simm.01c", 0x200000, 0x452F98B0, 11 | BRF_GRA },
	{ "pga-simm.01d", 0x200000, 0x9E672092, 11 | BRF_GRA },
	{ "pga-simm.01a", 0x200000, 0xAE9DDAFE, 11 | BRF_GRA },
	{ "pga-simm.01b", 0x200000, 0x94D72D94, 11 | BRF_GRA },
	{ "pga-simm.03c", 0x200000, 0x48A1886D, 11 | BRF_GRA },
	{ "pga-simm.03d", 0x200000, 0x172D7E37, 11 | BRF_GRA },
	{ "pga-simm.03a", 0x200000, 0x9EE33D98, 11 | BRF_GRA },
	{ "pga-simm.03b", 0x200000, 0x848DEE32, 11 | BRF_GRA },

	{ "pga.01",       0x020000, 0xBDBFA992,  4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "pga-simm.05a", 0x200000, 0xC0AAC80C, 13 | BRF_SND },
	{ "pga-simm.05b", 0x200000, 0x37A65D86, 13 | BRF_SND },
	{ "pga-simm.06a", 0x200000, 0xD3F1E934, 13 | BRF_SND },
	{ "pga-simm.06b", 0x200000, 0x8B39489A, 13 | BRF_SND },
};

STD_ROM_PICK(progerjd) STD_ROM_FN(progerjd)

struct BurnDriver BurnDrvCpsProgerjd = {
	"progerjd", "progear", NULL, "2001",
	"Progear no Arashi (Japan 010117, Phoenix Edition)\0", NULL, "Capcom / Cave", "CPS2",
	L"\u30D7\u30ED\u30AE\u30A2\u306E\u5D50 (Progear no Arashi Japan 010117, Phoenix Edition)\0", NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE | BDF_BOOTLEG, 2, HARDWARE_CAPCOM_CPS2 | HARDWARE_CAPCOM_CPS2_SIMM,
	NULL, progerjdRomInfo, progerjdRomName, progearInputInfo, NULL,
	PhoenixInit,CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Puzz Loop 2 (Euro 010302)

static struct BurnRomInfo pzloop2RomDesc[] = {
	{ "pl2e.03",      0x080000, 0x3b1285b2,  1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "pl2e.04",      0x080000, 0x40a2d647,  1 | BRF_ESS | BRF_PRG },
	{ "pl2e.05",      0x080000, 0x0f11d818,  1 | BRF_ESS | BRF_PRG },
	{ "pl2e.06",      0x080000, 0x86fbbdf4,  1 | BRF_ESS | BRF_PRG },

	{ "pl2-simm.01c", 0x200000, 0x137b13a7, 11 | BRF_GRA },
	{ "pl2-simm.01d", 0x200000, 0xa2db1507, 11 | BRF_GRA },
	{ "pl2-simm.01a", 0x200000, 0x7e80ff8e, 11 | BRF_GRA },
	{ "pl2-simm.01b", 0x200000, 0xcd93e6ed, 11 | BRF_GRA },
	{ "pl2-simm.03c", 0x200000, 0x0f52bbca, 11 | BRF_GRA },
	{ "pl2-simm.03d", 0x200000, 0xa62712c3, 11 | BRF_GRA },
	{ "pl2-simm.03a", 0x200000, 0xb60c9f8e, 11 | BRF_GRA },
	{ "pl2-simm.03b", 0x200000, 0x83fef284, 11 | BRF_GRA },

	{ "pl2.01",       0x020000, 0x35697569,  4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "pl2-simm.05a", 0x200000, 0x85d8fbe8, 13 | BRF_SND },
	{ "pl2-simm.05b", 0x200000, 0x1ed62584, 13 | BRF_SND },
};

STD_ROM_PICK(pzloop2) STD_ROM_FN(pzloop2)

int pzloop2Init()
{
	Pzloop2 = 1;

	return Cps2Init();
}

struct BurnDriver BurnDrvCpspzloop2 = {
	"pzloop2", NULL, NULL, "2001",
	"Puzz Loop 2 (Euro 010302)\0", NULL, "Mitchell", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING, 2, HARDWARE_CAPCOM_CPS2 | HARDWARE_CAPCOM_CPS2_SIMM,
	NULL, pzloop2RomInfo, pzloop2RomName, pzloop2InputInfo, NULL,
	pzloop2Init,CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Puzz Loop 2 (Japan 010205)

static struct BurnRomInfo pzloop2jRomDesc[] = {
	{ "pl2j.03a",     0x080000, 0x0a751bd0,  1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "pl2j.04a",     0x080000, 0xc3f72afe,  1 | BRF_ESS | BRF_PRG },
	{ "pl2j.05a",     0x080000, 0x6ea9dbfc,  1 | BRF_ESS | BRF_PRG },
	{ "pl2j.06a",     0x080000, 0x0f14848d,  1 | BRF_ESS | BRF_PRG },

	{ "pl2-simm.01c", 0x200000, 0x137b13a7, 11 | BRF_GRA },
	{ "pl2-simm.01d", 0x200000, 0xa2db1507, 11 | BRF_GRA },
	{ "pl2-simm.01a", 0x200000, 0x7e80ff8e, 11 | BRF_GRA },
	{ "pl2-simm.01b", 0x200000, 0xcd93e6ed, 11 | BRF_GRA },
	{ "pl2-simm.03c", 0x200000, 0x0f52bbca, 11 | BRF_GRA },
	{ "pl2-simm.03d", 0x200000, 0xa62712c3, 11 | BRF_GRA },
	{ "pl2-simm.03a", 0x200000, 0xb60c9f8e, 11 | BRF_GRA },
	{ "pl2-simm.03b", 0x200000, 0x83fef284, 11 | BRF_GRA },

	{ "pl2.01",       0x020000, 0x35697569,  4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "pl2-simm.05a", 0x200000, 0x85d8fbe8, 13 | BRF_SND },
	{ "pl2-simm.05b", 0x200000, 0x1ed62584, 13 | BRF_SND },
};

STD_ROM_PICK(pzloop2j) STD_ROM_FN(pzloop2j)

struct BurnDriver BurnDrvCpspzloop2j = {
	"pzloop2j","pzloop2", NULL, "2001",
	"Puzz Loop 2 (Japan 010205)\0", NULL, "Mitchell", "CPS2",
	L"Puzz Loop 2 (Japan 010205)\0\u30D1\u30BA\u30EB\u30FC\u30D7 \u30C4\u30FC (\u65E5\u672C\u7248 010205)\0", NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE, 2, HARDWARE_CAPCOM_CPS2 | HARDWARE_CAPCOM_CPS2_SIMM,
	NULL, pzloop2jRomInfo, pzloop2jRomName, pzloop2InputInfo, NULL,
	pzloop2Init,CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Quiz Nanairo Dreams: Nijiirochou no Kiseki (Japan 960826)

static struct BurnRomInfo qndreamRomDesc[] = {
	{ "tqzj.03a",     0x080000, 0x7acf3e30, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "tqzj.04",      0x080000, 0xf1044a87, 1 | BRF_ESS | BRF_PRG },
	{ "tqzj.05",      0x080000, 0x4105ba0e, 1 | BRF_ESS | BRF_PRG },
	{ "tqzj.06",      0x080000, 0xc371e8a5, 1 | BRF_ESS | BRF_PRG },

	{ "tqz.14m",      0x200000, 0x98af88a2, 3 | BRF_GRA },
	{ "tqz.16m",      0x200000, 0xdf82d491, 3 | BRF_GRA },
	{ "tqz.18m",      0x200000, 0x42f132ff, 3 | BRF_GRA },
	{ "tqz.20m",      0x200000, 0xb2e128a3, 3 | BRF_GRA },

	{ "tqz.01",       0x020000, 0xe9ce9d0a, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "tqz.11m",      0x200000, 0x78e7884f, 5 | BRF_SND },
	{ "tqz.12m",      0x200000, 0x2e049b13, 5 | BRF_SND },
};

STD_ROM_PICK(qndream) STD_ROM_FN(qndream)

struct BurnDriver BurnDrvCpsQndream = {
	"qndream", NULL, NULL, "1996",
	"Quiz Nanairo Dreams: Nijiirochou no Kiseki (Japan 960826)\0", NULL, "Capcom", "CPS2",
	L"Quiz \u306A\u306A\u3044\u308D Dreams: \u8679\u8272\u753A\u306E\u5947\u8DE1 (Nanairo Dreams Japan 960826)\0Quiz Nanairo Dreams: Nijiirochou no Kiseki\0", NULL, NULL, NULL,
	BDF_GAME_WORKING,2,HARDWARE_CAPCOM_CPS2,
	NULL, qndreamRomInfo, qndreamRomName, qndreamInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Ring of Destruction: Slammasters II (Euro 940902)

static struct BurnRomInfo RingdestRomDesc[] = {
	{ "smbe.03b",     0x080000, 0xb8016278, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "smbe.04b",     0x080000, 0x18c4c447, 1 | BRF_ESS | BRF_PRG },
	{ "smbe.05b",     0x080000, 0x18ebda7f, 1 | BRF_ESS | BRF_PRG },
	{ "smbe.06b",     0x080000, 0x89c80007, 1 | BRF_ESS | BRF_PRG },
	{ "smb.07",       0x080000, 0xb9a11577, 1 | BRF_ESS | BRF_PRG },
	{ "smb.08",       0x080000, 0xf931b76b, 1 | BRF_ESS | BRF_PRG },

	{ "smb.13m",      0x200000, 0xd9b2d1de, 3 | BRF_GRA },
	{ "smb.15m",      0x200000, 0x9a766d92, 3 | BRF_GRA },
	{ "smb.17m",      0x200000, 0x51800f0f, 3 | BRF_GRA },
	{ "smb.19m",      0x200000, 0x35757e96, 3 | BRF_GRA },
	{ "smb.14m",      0x200000, 0xe5bfd0e7, 3 | BRF_GRA },
	{ "smb.16m",      0x200000, 0xc56c0866, 3 | BRF_GRA },
	{ "smb.18m",      0x200000, 0x4ded3910, 3 | BRF_GRA },
	{ "smb.20m",      0x200000, 0x26ea1ec5, 3 | BRF_GRA },
	{ "smb.21m",      0x080000, 0x0a08c5fc, 3 | BRF_GRA },
	{ "smb.23m",      0x080000, 0x0911b6c4, 3 | BRF_GRA },
	{ "smb.25m",      0x080000, 0x82d6c4ec, 3 | BRF_GRA },
	{ "smb.27m",      0x080000, 0x9b48678b, 3 | BRF_GRA },

	{ "smb.01",       0x020000, 0x0abc229a, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "smb.02",       0x020000, 0xd051679a, 4 | BRF_ESS | BRF_PRG },

	{ "smb.11m",      0x200000, 0xc56935f9, 5 | BRF_SND },
	{ "smb.12m",      0x200000, 0x955b0782, 5 | BRF_SND },
};

STD_ROM_PICK(Ringdest) STD_ROM_FN(Ringdest)

struct BurnDriver BurnDrvCpsRingdest = {
	"ringdest", NULL, NULL, "1994",
	"Ring of Destruction: Slammasters II (Euro 940902)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING,2,HARDWARE_CAPCOM_CPS2,
	NULL, RingdestRomInfo, RingdestRomName, ringdestInputInfo, NULL,
	Cps2Init,CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Super Muscle Bomber: The International Blowout (Japan 940831)

static struct BurnRomInfo SmbombRomDesc[] = {
	{ "smbj.03a",     0x080000, 0x1c5613de, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "smbj.04a",     0x080000, 0x29071ed7, 1 | BRF_ESS | BRF_PRG },
	{ "smbj.05a",     0x080000, 0xeb20bce4, 1 | BRF_ESS | BRF_PRG },
	{ "smbj.06a",     0x080000, 0x94b420cd, 1 | BRF_ESS | BRF_PRG },
	{ "smb.07",       0x080000, 0xb9a11577, 1 | BRF_ESS | BRF_PRG },
	{ "smb.08",       0x080000, 0xf931b76b, 1 | BRF_ESS | BRF_PRG },

	{ "smb.13m",      0x200000, 0xd9b2d1de, 3 | BRF_GRA },
	{ "smb.15m",      0x200000, 0x9a766d92, 3 | BRF_GRA },
	{ "smb.17m",      0x200000, 0x51800f0f, 3 | BRF_GRA },
	{ "smb.19m",      0x200000, 0x35757e96, 3 | BRF_GRA },
	{ "smb.14m",      0x200000, 0xe5bfd0e7, 3 | BRF_GRA },
	{ "smb.16m",      0x200000, 0xc56c0866, 3 | BRF_GRA },
	{ "smb.18m",      0x200000, 0x4ded3910, 3 | BRF_GRA },
	{ "smb.20m",      0x200000, 0x26ea1ec5, 3 | BRF_GRA },
	{ "smb.21m",      0x080000, 0x0a08c5fc, 3 | BRF_GRA },
	{ "smb.23m",      0x080000, 0x0911b6c4, 3 | BRF_GRA },
	{ "smb.25m",      0x080000, 0x82d6c4ec, 3 | BRF_GRA },
	{ "smb.27m",      0x080000, 0x9b48678b, 3 | BRF_GRA },

	{ "smb.01",       0x020000, 0x0abc229a, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "smb.02",       0x020000, 0xd051679a, 4 | BRF_ESS | BRF_PRG },

	{ "smb.11m",      0x200000, 0xc56935f9, 5 | BRF_SND },
	{ "smb.12m",      0x200000, 0x955b0782, 5 | BRF_SND },
};

STD_ROM_PICK(Smbomb) STD_ROM_FN(Smbomb)

struct BurnDriver BurnDrvCpsSmbomb = {
	"smbomb", "ringdest", NULL, "1994",
	"Super Muscle Bomber: The International Blowout (Japan 940831)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, SmbombRomInfo, SmbombRomName, ringdestInputInfo, NULL,
	Cps2Init,CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Super Muscle Bomber: The International Blowout (Japan 940808)

static struct BurnRomInfo Smbombr1RomDesc[] = {
	{ "smbj.03",      0x080000, 0x52eafb10, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "smbj.04",      0x080000, 0xaa6e8078, 1 | BRF_ESS | BRF_PRG },
	{ "smbj.05",      0x080000, 0xb69e7d5f, 1 | BRF_ESS | BRF_PRG },
	{ "smbj.06",      0x080000, 0x8d857b56, 1 | BRF_ESS | BRF_PRG },
	{ "smb.07",       0x080000, 0xb9a11577, 1 | BRF_ESS | BRF_PRG },
	{ "smb.08",       0x080000, 0xf931b76b, 1 | BRF_ESS | BRF_PRG },

	{ "smb.13m",      0x200000, 0xd9b2d1de, 3 | BRF_GRA },
	{ "smb.15m",      0x200000, 0x9a766d92, 3 | BRF_GRA },
	{ "smb.17m",      0x200000, 0x51800f0f, 3 | BRF_GRA },
	{ "smb.19m",      0x200000, 0x35757e96, 3 | BRF_GRA },
	{ "smb.14m",      0x200000, 0xe5bfd0e7, 3 | BRF_GRA },
	{ "smb.16m",      0x200000, 0xc56c0866, 3 | BRF_GRA },
	{ "smb.18m",      0x200000, 0x4ded3910, 3 | BRF_GRA },
	{ "smb.20m",      0x200000, 0x26ea1ec5, 3 | BRF_GRA },
	{ "smb.21m",      0x080000, 0x0a08c5fc, 3 | BRF_GRA },
	{ "smb.23m",      0x080000, 0x0911b6c4, 3 | BRF_GRA },
	{ "smb.25m",      0x080000, 0x82d6c4ec, 3 | BRF_GRA },
	{ "smb.27m",      0x080000, 0x9b48678b, 3 | BRF_GRA },

	{ "smb.01",       0x020000, 0x0abc229a, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "smb.02",       0x020000, 0xd051679a, 4 | BRF_ESS | BRF_PRG },

	{ "smb.11m",      0x200000, 0xc56935f9, 5 | BRF_SND },
	{ "smb.12m",      0x200000, 0x955b0782, 5 | BRF_SND },
};

STD_ROM_PICK(Smbombr1) STD_ROM_FN(Smbombr1)

struct BurnDriver BurnDrvCpsSmbombr1 = {
	"smbombr1", "ringdest", NULL, "1994",
	"Super Muscle Bomber: The International Blowout (Japan 940808)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Smbombr1RomInfo, Smbombr1RomName, ringdestInputInfo, NULL,
	Cps2Init,CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Ring of Destruction: Slammasters II (Euro 940902, Phoenix Edition)

static struct BurnRomInfo RingdstdRomDesc[] = {
	{ "smbed.03b",     0x80000, 0xf6fba4cd, 1 | BRF_ESS | BRF_PRG }, // 68000 code
	{ "smbed.04b",     0x80000, 0x193bc493, 1 | BRF_ESS | BRF_PRG },
	{ "smbed.05b",     0x80000, 0x168cccbb, 1 | BRF_ESS | BRF_PRG },
	{ "smbed.06b",     0x80000, 0x04673262, 1 | BRF_ESS | BRF_PRG },
	{ "smb.07",        0x80000, 0xb9a11577, 1 | BRF_ESS | BRF_PRG },
	{ "smb.08",        0x80000, 0xf931b76b, 1 | BRF_ESS | BRF_PRG },

	{ "smb.13m",      0x200000, 0xd9b2d1de, 3 | BRF_GRA },			 // 9
	{ "smb.15m",      0x200000, 0x9a766d92, 3 | BRF_GRA },
	{ "smb.17m",      0x200000, 0x51800f0f, 3 | BRF_GRA },
	{ "smb.19m",      0x200000, 0x35757e96, 3 | BRF_GRA },
	{ "smb.14m",      0x200000, 0xe5bfd0e7, 3 | BRF_GRA },
	{ "smb.16m",      0x200000, 0xc56c0866, 3 | BRF_GRA },
	{ "smb.18m",      0x200000, 0x4ded3910, 3 | BRF_GRA },
	{ "smb.20m",      0x200000, 0x26ea1ec5, 3 | BRF_GRA },
	{ "smb.21m",      0x080000, 0x0a08c5fc, 3 | BRF_GRA },
	{ "smb.23m",      0x080000, 0x0911b6c4, 3 | BRF_GRA },
	{ "smb.25m",      0x080000, 0x82d6c4ec, 3 | BRF_GRA },
	{ "smb.27m",      0x080000, 0x9b48678b, 3 | BRF_GRA },

	{ "smb.01",       0x020000, 0x0abc229a, 4 | BRF_ESS | BRF_PRG }, // 21
	{ "smb.02",       0x020000, 0xd051679a, 4 | BRF_ESS | BRF_PRG },

	{ "smb.11m",      0x200000, 0xc56935f9, 5 | BRF_SND },
	{ "smb.12m",      0x200000, 0x955b0782, 5 | BRF_SND },
};

STD_ROM_PICK(Ringdstd) STD_ROM_FN(Ringdstd)

struct BurnDriver BurnDrvCpsRingdstd = {
	"ringdstd", "ringdest", NULL, "1994",
	"Ring of Destruction: Slammasters II (Euro 940902, Phoenix Edition)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE | BDF_BOOTLEG,2,HARDWARE_CAPCOM_CPS2,
	NULL, RingdstdRomInfo, RingdstdRomName, ringdestInputInfo, NULL,
	PhoenixInit,CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Mega Man - The Power Battle (CPS2, USA 951006, SAMPLE Version)

static struct BurnRomInfo mmancp2uRomDesc[] = {
	{ "rcmu.03b",  0x080000, 0xc39f037f, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "rcmu.04b",  0x080000, 0xcd6f5e99, 1 | BRF_ESS | BRF_PRG },
	{ "rcm.05b",   0x080000, 0x4376ea95, 1 | BRF_ESS | BRF_PRG },

	{ "rcm.73",    0x080000, 0x774c6e04, 3 | BRF_GRA },
	{ "rcm.63",    0x080000, 0xacad7c62, 3 | BRF_GRA },
	{ "rcm.83",    0x080000, 0x6af30499, 3 | BRF_GRA },
	{ "rcm.93",    0x080000, 0x7a5a5166, 3 | BRF_GRA },
	{ "rcm.74",    0x080000, 0x004ec725, 3 | BRF_GRA },
	{ "rcm.64",    0x080000, 0x65c0464e, 3 | BRF_GRA },
	{ "rcm.84",    0x080000, 0xfb3097cc, 3 | BRF_GRA },
	{ "rcm.94",    0x080000, 0x2e16557a, 3 | BRF_GRA },
	{ "rcm.75",    0x080000, 0x70a73f99, 3 | BRF_GRA },
	{ "rcm.65",    0x080000, 0xecedad3d, 3 | BRF_GRA },
	{ "rcm.85",    0x080000, 0x3d6186d8, 3 | BRF_GRA },
	{ "rcm.95",    0x080000, 0x8c7700f1, 3 | BRF_GRA },
	{ "rcm.76",    0x080000, 0x89a889ad, 3 | BRF_GRA },
	{ "rcm.66",    0x080000, 0x1300eb7b, 3 | BRF_GRA },
	{ "rcm.86",    0x080000, 0x6d974ebd, 3 | BRF_GRA },
	{ "rcm.96",    0x080000, 0x7da4cd24, 3 | BRF_GRA },

	{ "rcm.01",    0x020000, 0xd60cf8a3, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "rcm.51",    0x080000, 0xb6d07080, 5 | BRF_SND },
	{ "rcm.52",    0x080000, 0xdfddc493, 5 | BRF_SND },
	{ "rcm.53",    0x080000, 0x6062ae3a, 5 | BRF_SND },
	{ "rcm.54",    0x080000, 0x08c6f3bf, 5 | BRF_SND },
	{ "rcm.55",    0x080000, 0xf97dfccc, 5 | BRF_SND },
	{ "rcm.56",    0x080000, 0xade475bc, 5 | BRF_SND },
	{ "rcm.57",    0x080000, 0x075effb3, 5 | BRF_SND },
	{ "rcm.58",    0x080000, 0xf6c1f87b, 5 | BRF_SND },
};

STD_ROM_PICK(mmancp2u) STD_ROM_FN(mmancp2u)

struct BurnDriver BurnDrvCpsmmancp2u = {
	"mmancp2u", "megaman", NULL, "1995",
	"Mega Man - The Power Battle (CPS2, USA 951006, SAMPLE Version)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE, 2, HARDWARE_CAPCOM_CPS2,
	NULL, mmancp2uRomInfo, mmancp2uRomName, megamanInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame, Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Rockman: The Power Battle (CPS2, Japan 950922)

static struct BurnRomInfo rmancp2jRomDesc[] = {
	{ "rcmj.03a", 0x080000, 0x30559f60, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "rcmj.04a", 0x080000, 0x5efc9366, 1 | BRF_ESS | BRF_PRG },
	{ "rcm.05a",  0x080000, 0x517ccde2, 1 | BRF_ESS | BRF_PRG },

	{ "rcm.73",   0x080000, 0x774c6e04, 3 | BRF_GRA },
	{ "rcm.63",   0x080000, 0xacad7c62, 3 | BRF_GRA },
	{ "rcm.83",   0x080000, 0x6af30499, 3 | BRF_GRA },
	{ "rcm.93",   0x080000, 0x7a5a5166, 3 | BRF_GRA },
	{ "rcm.74",   0x080000, 0x004ec725, 3 | BRF_GRA },
	{ "rcm.64",   0x080000, 0x65c0464e, 3 | BRF_GRA },
	{ "rcm.84",   0x080000, 0xfb3097cc, 3 | BRF_GRA },
	{ "rcm.94",   0x080000, 0x2e16557a, 3 | BRF_GRA },
	{ "rcm.75",   0x080000, 0x70a73f99, 3 | BRF_GRA },
	{ "rcm.65",   0x080000, 0xecedad3d, 3 | BRF_GRA },
	{ "rcm.85",   0x080000, 0x3d6186d8, 3 | BRF_GRA },
	{ "rcm.95",   0x080000, 0x8c7700f1, 3 | BRF_GRA },
	{ "rcm.76",   0x080000, 0x89a889ad, 3 | BRF_GRA },
	{ "rcm.66",   0x080000, 0x1300eb7b, 3 | BRF_GRA },
	{ "rcm.86",   0x080000, 0x6d974ebd, 3 | BRF_GRA },
	{ "rcm.96",   0x080000, 0x7da4cd24, 3 | BRF_GRA },

	{ "rcm.01",   0x020000, 0xd60cf8a3, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "rcm.51",   0x080000, 0xb6d07080, 5 | BRF_SND },
	{ "rcm.52",   0x080000, 0xdfddc493, 5 | BRF_SND },
	{ "rcm.53",   0x080000, 0x6062ae3a, 5 | BRF_SND },
	{ "rcm.54",   0x080000, 0x08c6f3bf, 5 | BRF_SND },
	{ "rcm.55",   0x080000, 0xf97dfccc, 5 | BRF_SND },
	{ "rcm.56",   0x080000, 0xade475bc, 5 | BRF_SND },
	{ "rcm.57",   0x080000, 0x075effb3, 5 | BRF_SND },
	{ "rcm.58",   0x080000, 0xf6c1f87b, 5 | BRF_SND },
};

STD_ROM_PICK(rmancp2j) STD_ROM_FN(rmancp2j)

struct BurnDriver BurnDrvCpsrmancp2j = {
	"rmancp2j", "megaman", NULL, "1995",
	"Rockman: The Power Battle (CPS2, Japan 950922)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE, 2, HARDWARE_CAPCOM_CPS2,
	NULL, rmancp2jRomInfo, rmancp2jRomName, megamanInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame, Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Street Fighter Alpha: Warriors' Dreams (Euro 950727)

static struct BurnRomInfo SfaRomDesc[] = {
	{ "sfze.03b",     0x080000, 0xebf2054d, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "sfz.04b",      0x080000, 0x8b73b0e5, 1 | BRF_ESS | BRF_PRG },
	{ "sfz.05a",      0x080000, 0x0810544d, 1 | BRF_ESS | BRF_PRG },
	{ "sfz.06",       0x080000, 0x806e8f38, 1 | BRF_ESS | BRF_PRG },

	{ "sfz.14m",      0x200000, 0x90fefdb3, 3 | BRF_GRA },
	{ "sfz.16m",      0x200000, 0x5354c948, 3 | BRF_GRA },
	{ "sfz.18m",      0x200000, 0x41a1e790, 3 | BRF_GRA },
	{ "sfz.20m",      0x200000, 0xa549df98, 3 | BRF_GRA },

	{ "sfz.01",       0x020000, 0xffffec7d, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sfz.02",       0x020000, 0x45f46a08, 4 | BRF_ESS | BRF_PRG },

	{ "sfz.11m",      0x200000, 0xc4b093cd, 5 | BRF_SND },
	{ "sfz.12m",      0x200000, 0x8bdbc4b4, 5 | BRF_SND },
};

STD_ROM_PICK(Sfa) STD_ROM_FN(Sfa)

struct BurnDriver BurnDrvCpsSfa = {
	"sfa", NULL, NULL, "1995",
	"Street Fighter Alpha: Warriors' Dreams (Euro 950727)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING,2,HARDWARE_CAPCOM_CPS2,
	NULL, SfaRomInfo, SfaRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Street Fighter Alpha: Warriors' Dreams (Euro 950718)

static struct BurnRomInfo Sfar1RomDesc[] = {
	{ "sfze.03c",     0x080000, 0xa1b69dd7, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "sfze.04b",     0x080000, 0xbb90acd5, 1 | BRF_ESS | BRF_PRG },
	{ "sfz.05a",      0x080000, 0x0810544d, 1 | BRF_ESS | BRF_PRG },
	{ "sfz.06",       0x080000, 0x806e8f38, 1 | BRF_ESS | BRF_PRG },

	{ "sfz.14m",      0x200000, 0x90fefdb3, 3 | BRF_GRA },
	{ "sfz.16m",      0x200000, 0x5354c948, 3 | BRF_GRA },
	{ "sfz.18m",      0x200000, 0x41a1e790, 3 | BRF_GRA },
	{ "sfz.20m",      0x200000, 0xa549df98, 3 | BRF_GRA },

	{ "sfz.01",       0x020000, 0xffffec7d, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sfz.02",       0x020000, 0x45f46a08, 4 | BRF_ESS | BRF_PRG },

	{ "sfz.11m",      0x200000, 0xc4b093cd, 5 | BRF_SND },
	{ "sfz.12m",      0x200000, 0x8bdbc4b4, 5 | BRF_SND },
};

STD_ROM_PICK(Sfar1) STD_ROM_FN(Sfar1)

struct BurnDriver BurnDrvCpsSfar1 = {
	"sfar1", "sfa", NULL, "1995",
	"Street Fighter Alpha: Warriors' Dreams (Euro 950718)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Sfar1RomInfo, Sfar1RomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Street Fighter Alpha: Warriors' Dreams (Euro 950627)

static struct BurnRomInfo Sfar2RomDesc[] = {
	{ "sfze.03b",     0x080000, 0x2bf5708e, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "sfz.04a",      0x080000, 0x5f99e9a5, 1 | BRF_ESS | BRF_PRG },
	{ "sfz.05a",      0x080000, 0x0810544d, 1 | BRF_ESS | BRF_PRG },
	{ "sfz.06",       0x080000, 0x806e8f38, 1 | BRF_ESS | BRF_PRG },

	{ "sfz.14m",      0x200000, 0x90fefdb3, 3 | BRF_GRA },
	{ "sfz.16m",      0x200000, 0x5354c948, 3 | BRF_GRA },
	{ "sfz.18m",      0x200000, 0x41a1e790, 3 | BRF_GRA },
	{ "sfz.20m",      0x200000, 0xa549df98, 3 | BRF_GRA },

	{ "sfz.01",       0x020000, 0xffffec7d, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sfz.02",       0x020000, 0x45f46a08, 4 | BRF_ESS | BRF_PRG },

	{ "sfz.11m",      0x200000, 0xc4b093cd, 5 | BRF_SND },
	{ "sfz.12m",      0x200000, 0x8bdbc4b4, 5 | BRF_SND },
};

STD_ROM_PICK(Sfar2) STD_ROM_FN(Sfar2)

struct BurnDriver BurnDrvCpsSfar2 = {
	"sfar2", "sfa", NULL, "1995",
	"Street Fighter Alpha: Warriors' Dreams (Euro 950627)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Sfar2RomInfo, Sfar2RomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Street Fighter Alpha: Warriors' Dreams (Euro 950605)

static struct BurnRomInfo Sfar3RomDesc[] = {
	{ "sfze.03a",     0x080000, 0xfdbcd434, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "sfz.04",       0x080000, 0x0c436d30, 1 | BRF_ESS | BRF_PRG },
	{ "sfz.05",       0x080000, 0x1f363612, 1 | BRF_ESS | BRF_PRG },
	{ "sfz.06",       0x080000, 0x806e8f38, 1 | BRF_ESS | BRF_PRG },

	{ "sfz.14m",      0x200000, 0x90fefdb3, 3 | BRF_GRA },
	{ "sfz.16m",      0x200000, 0x5354c948, 3 | BRF_GRA },
	{ "sfz.18m",      0x200000, 0x41a1e790, 3 | BRF_GRA },
	{ "sfz.20m",      0x200000, 0xa549df98, 3 | BRF_GRA },

	{ "sfz.01",       0x020000, 0xffffec7d, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sfz.02",       0x020000, 0x45f46a08, 4 | BRF_ESS | BRF_PRG },

	{ "sfz.11m",      0x200000, 0xc4b093cd, 5 | BRF_SND },
	{ "sfz.12m",      0x200000, 0x8bdbc4b4, 5 | BRF_SND },
};

STD_ROM_PICK(Sfar3) STD_ROM_FN(Sfar3)

struct BurnDriver BurnDrvCpsSfar3 = {
	"sfar3", "sfa", NULL, "1995",
	"Street Fighter Alpha: Warriors' Dreams (Euro 950605)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Sfar3RomInfo, Sfar3RomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Street Fighter Alpha: Warriors' Dreams (USA 950627)

static struct BurnRomInfo SfauRomDesc[] = {
	{ "sfzu.03a",     0x080000, 0x49fc7db9, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "sfz.04a",      0x080000, 0x5f99e9a5, 1 | BRF_ESS | BRF_PRG },
	{ "sfz.05a",      0x080000, 0x0810544d, 1 | BRF_ESS | BRF_PRG },
	{ "sfz.06",       0x080000, 0x806e8f38, 1 | BRF_ESS | BRF_PRG },

	{ "sfz.14m",      0x200000, 0x90fefdb3, 3 | BRF_GRA },
	{ "sfz.16m",      0x200000, 0x5354c948, 3 | BRF_GRA },
	{ "sfz.18m",      0x200000, 0x41a1e790, 3 | BRF_GRA },
	{ "sfz.20m",      0x200000, 0xa549df98, 3 | BRF_GRA },

	{ "sfz.01",       0x020000, 0xffffec7d, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sfz.02",       0x020000, 0x45f46a08, 4 | BRF_ESS | BRF_PRG },

	{ "sfz.11m",      0x200000, 0xc4b093cd, 5 | BRF_SND },
	{ "sfz.12m",      0x200000, 0x8bdbc4b4, 5 | BRF_SND },
};

STD_ROM_PICK(Sfau) STD_ROM_FN(Sfau)

struct BurnDriver BurnDrvCpsSfau = {
	"sfau", "sfa", NULL, "1995",
	"Street Fighter Alpha: Warriors' Dreams (USA 950627)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, SfauRomInfo, SfauRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Street Fighter Zero (Asia 950627)

static struct BurnRomInfo SfzaRomDesc[] = {
	{ "sfza.03a",     0x080000, 0xca91bed9, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "sfz.04a",      0x080000, 0x5f99e9a5, 1 | BRF_ESS | BRF_PRG },
	{ "sfz.05a",      0x080000, 0x0810544d, 1 | BRF_ESS | BRF_PRG },
	{ "sfz.06",       0x080000, 0x806e8f38, 1 | BRF_ESS | BRF_PRG },

	{ "sfz.14m",      0x200000, 0x90fefdb3, 3 | BRF_GRA },
	{ "sfz.16m",      0x200000, 0x5354c948, 3 | BRF_GRA },
	{ "sfz.18m",      0x200000, 0x41a1e790, 3 | BRF_GRA },
	{ "sfz.20m",      0x200000, 0xa549df98, 3 | BRF_GRA },

	{ "sfz.01",       0x020000, 0xffffec7d, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sfz.02",       0x020000, 0x45f46a08, 4 | BRF_ESS | BRF_PRG },

	{ "sfz.11m",      0x200000, 0xc4b093cd, 5 | BRF_SND },
	{ "sfz.12m",      0x200000, 0x8bdbc4b4, 5 | BRF_SND },
};

STD_ROM_PICK(Sfza) STD_ROM_FN(Sfza)

struct BurnDriver BurnDrvCpsSfza = {
	"sfza", "sfa", NULL, "1995",
	"Street Fighter Zero (Asia 950627)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, SfzaRomInfo, SfzaRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Street Fighter Zero (Japan 950727)

static struct BurnRomInfo SfzjRomDesc[] = {
	{ "sfzj.03c",     0x080000, 0xf5444120, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "sfz.04b",      0x080000, 0x8b73b0e5, 1 | BRF_ESS | BRF_PRG },
	{ "sfz.05a",      0x080000, 0x0810544d, 1 | BRF_ESS | BRF_PRG },
	{ "sfz.06",       0x080000, 0x806e8f38, 1 | BRF_ESS | BRF_PRG },

	{ "sfz.14m",      0x200000, 0x90fefdb3, 3 | BRF_GRA },
	{ "sfz.16m",      0x200000, 0x5354c948, 3 | BRF_GRA },
	{ "sfz.18m",      0x200000, 0x41a1e790, 3 | BRF_GRA },
	{ "sfz.20m",      0x200000, 0xa549df98, 3 | BRF_GRA },

	{ "sfz.01",       0x020000, 0xffffec7d, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sfz.02",       0x020000, 0x45f46a08, 4 | BRF_ESS | BRF_PRG },

	{ "sfz.11m",      0x200000, 0xc4b093cd, 5 | BRF_SND },
	{ "sfz.12m",      0x200000, 0x8bdbc4b4, 5 | BRF_SND },
};

STD_ROM_PICK(Sfzj) STD_ROM_FN(Sfzj)

struct BurnDriver BurnDrvCpsSfzj = {
	"sfzj", "sfa", NULL, "1995",
	"Street Fighter Zero (Japan 950727)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, SfzjRomInfo, SfzjRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Street Fighter Zero (Japan 950627)

static struct BurnRomInfo Sfzjr1RomDesc[] = {
	{ "sfzj.03b",     0x080000, 0x844220c2, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "sfz.04a",      0x080000, 0x5f99e9a5, 1 | BRF_ESS | BRF_PRG },
	{ "sfz.05a",      0x080000, 0x0810544d, 1 | BRF_ESS | BRF_PRG },
	{ "sfz.06",       0x080000, 0x806e8f38, 1 | BRF_ESS | BRF_PRG },

	{ "sfz.14m",      0x200000, 0x90fefdb3, 3 | BRF_GRA },
	{ "sfz.16m",      0x200000, 0x5354c948, 3 | BRF_GRA },
	{ "sfz.18m",      0x200000, 0x41a1e790, 3 | BRF_GRA },
	{ "sfz.20m",      0x200000, 0xa549df98, 3 | BRF_GRA },

	{ "sfz.01",       0x020000, 0xffffec7d, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sfz.02",       0x020000, 0x45f46a08, 4 | BRF_ESS | BRF_PRG },

	{ "sfz.11m",      0x200000, 0xc4b093cd, 5 | BRF_SND },
	{ "sfz.12m",      0x200000, 0x8bdbc4b4, 5 | BRF_SND },
};

STD_ROM_PICK(Sfzjr1) STD_ROM_FN(Sfzjr1)

struct BurnDriver BurnDrvCpsSfzjr1 = {
	"sfzjr1", "sfa", NULL, "1995",
	"Street Fighter Zero (Japan 950627)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Sfzjr1RomInfo, Sfzjr1RomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Street Fighter Zero (Japan 950605)

static struct BurnRomInfo Sfzjr2RomDesc[] = {
	{ "sfzj.03a",     0x080000, 0x3cfce93c, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "sfz.04",       0x080000, 0x0c436d30, 1 | BRF_ESS | BRF_PRG },
	{ "sfz.05",       0x080000, 0x1f363612, 1 | BRF_ESS | BRF_PRG },
	{ "sfz.06",       0x080000, 0x806e8f38, 1 | BRF_ESS | BRF_PRG },

	{ "sfz.14m",      0x200000, 0x90fefdb3, 3 | BRF_GRA },
	{ "sfz.16m",      0x200000, 0x5354c948, 3 | BRF_GRA },
	{ "sfz.18m",      0x200000, 0x41a1e790, 3 | BRF_GRA },
	{ "sfz.20m",      0x200000, 0xa549df98, 3 | BRF_GRA },

	{ "sfz.01",       0x020000, 0xffffec7d, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sfz.02",       0x020000, 0x45f46a08, 4 | BRF_ESS | BRF_PRG },

	{ "sfz.11m",      0x200000, 0xc4b093cd, 5 | BRF_SND },
	{ "sfz.12m",      0x200000, 0x8bdbc4b4, 5 | BRF_SND },
};

STD_ROM_PICK(Sfzjr2) STD_ROM_FN(Sfzjr2)

struct BurnDriver BurnDrvCpsSfzjr2 = {
	"sfzjr2", "sfa", NULL, "1995",
	"Street Fighter Zero (Japan 950605)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Sfzjr2RomInfo, Sfzjr2RomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Street Fighter Zero (Hispanic 950627)

static struct BurnRomInfo SfzhRomDesc[] = {
	{ "sfzh.03c",     0x080000, 0xbce635aa, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "sfz.04a",      0x080000, 0x5f99e9a5, 1 | BRF_ESS | BRF_PRG },
	{ "sfz.05a",      0x080000, 0x0810544d, 1 | BRF_ESS | BRF_PRG },
	{ "sfz.06",       0x080000, 0x806e8f38, 1 | BRF_ESS | BRF_PRG },

	{ "sfz.14m",      0x200000, 0x90fefdb3, 3 | BRF_GRA },
	{ "sfz.16m",      0x200000, 0x5354c948, 3 | BRF_GRA },
	{ "sfz.18m",      0x200000, 0x41a1e790, 3 | BRF_GRA },
	{ "sfz.20m",      0x200000, 0xa549df98, 3 | BRF_GRA },

	{ "sfz.01",       0x020000, 0xffffec7d, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sfz.02",       0x020000, 0x45f46a08, 4 | BRF_ESS | BRF_PRG },

	{ "sfz.11m",      0x200000, 0xc4b093cd, 5 | BRF_SND },
	{ "sfz.12m",      0x200000, 0x8bdbc4b4, 5 | BRF_SND },
};

STD_ROM_PICK(Sfzh) STD_ROM_FN(Sfzh)

struct BurnDriver BurnDrvCpsSfzh = {
	"sfzh", "sfa", NULL, "1995",
	"Street Fighter Zero (Hispanic 950627)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, SfzhRomInfo, SfzhRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Street Fighter Zero (Brazil 951109)

static struct BurnRomInfo SfzbRomDesc[] = {
	{ "sfzb.03g",     0x080000, 0x348862d4, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "sfzb.04e",     0x080000, 0x8d9b2480, 1 | BRF_ESS | BRF_PRG },
	{ "sfz.05a",      0x080000, 0x0810544d, 1 | BRF_ESS | BRF_PRG },
	{ "sfz.06",       0x080000, 0x806e8f38, 1 | BRF_ESS | BRF_PRG },

	{ "sfz.14m",      0x200000, 0x90fefdb3, 3 | BRF_GRA },
	{ "sfz.16m",      0x200000, 0x5354c948, 3 | BRF_GRA },
	{ "sfz.18m",      0x200000, 0x41a1e790, 3 | BRF_GRA },
	{ "sfz.20m",      0x200000, 0xa549df98, 3 | BRF_GRA },

	{ "sfz.01",       0x020000, 0xffffec7d, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sfz.02",       0x020000, 0x45f46a08, 4 | BRF_ESS | BRF_PRG },

	{ "sfz.11m",      0x200000, 0xc4b093cd, 5 | BRF_SND },
	{ "sfz.12m",      0x200000, 0x8bdbc4b4, 5 | BRF_SND },
};

STD_ROM_PICK(Sfzb) STD_ROM_FN(Sfzb)

struct BurnDriver BurnDrvCpsSfzb = {
	"sfzb", "sfa", NULL, "1995",
	"Street Fighter Zero (Brazil 951109)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, SfzbRomInfo, SfzbRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Street Fighter Zero (Brazil 950727)

static struct BurnRomInfo Sfzbr1RomDesc[] = {
	{ "sfzb.03e",     0x080000, 0xecba89a3, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "sfz.04b",      0x080000, 0x8b73b0e5, 1 | BRF_ESS | BRF_PRG },
	{ "sfz.05a",      0x080000, 0x0810544d, 1 | BRF_ESS | BRF_PRG },
	{ "sfz.06",       0x080000, 0x806e8f38, 1 | BRF_ESS | BRF_PRG },

	{ "sfz.14m",      0x200000, 0x90fefdb3, 3 | BRF_GRA },
	{ "sfz.16m",      0x200000, 0x5354c948, 3 | BRF_GRA },
	{ "sfz.18m",      0x200000, 0x41a1e790, 3 | BRF_GRA },
	{ "sfz.20m",      0x200000, 0xa549df98, 3 | BRF_GRA },

	{ "sfz.01",       0x020000, 0xffffec7d, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sfz.02",       0x020000, 0x45f46a08, 4 | BRF_ESS | BRF_PRG },

	{ "sfz.11m",      0x200000, 0xc4b093cd, 5 | BRF_SND },
	{ "sfz.12m",      0x200000, 0x8bdbc4b4, 5 | BRF_SND },
};

STD_ROM_PICK(Sfzbr1) STD_ROM_FN(Sfzbr1)

struct BurnDriver BurnDrvCpsSfzbr1 = {
	"sfzbr1", "sfa", NULL, "1995",
	"Street Fighter Zero (Brazil 950727)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Sfzbr1RomInfo, Sfzbr1RomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Street Fighter Alpha: Warriors' Dreams (Euro 950727, Phoenix Edition)

static struct BurnRomInfo SfadRomDesc[] = {
	{ "sfzed.03b",     0x80000, 0xa1a54827, 1 | BRF_ESS | BRF_PRG },
	{ "sfz.04b",       0x80000, 0x8b73b0e5, 1 | BRF_ESS | BRF_PRG },
	{ "sfz.05a",       0x80000, 0x0810544d, 1 | BRF_ESS | BRF_PRG },
	{ "sfz.06",        0x80000, 0x806e8f38, 1 | BRF_ESS | BRF_PRG },

	{ "sfz.14m",      0x200000, 0x90fefdb3, 3 | BRF_GRA },
	{ "sfz.16m",      0x200000, 0x5354c948, 3 | BRF_GRA },
	{ "sfz.18m",      0x200000, 0x41a1e790, 3 | BRF_GRA },
	{ "sfz.20m",      0x200000, 0xa549df98, 3 | BRF_GRA },

	{ "sfz.01",       0x020000, 0xffffec7d, 4 | BRF_ESS | BRF_PRG },
	{ "sfz.02",       0x020000, 0x45f46a08, 4 | BRF_ESS | BRF_PRG },

	{ "sfz.11m",      0x200000, 0xc4b093cd, 5 | BRF_SND },
	{ "sfz.12m",      0x200000, 0x8bdbc4b4, 5 | BRF_SND },
};

STD_ROM_PICK(Sfad) STD_ROM_FN(Sfad)

struct BurnDriver BurnDrvCpsSfad = {
	"sfad", "sfa", NULL, "1995",
	"Street Fighter Alpha: Warriors' Dreams (Euro 950727, Phoenix Edition)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE | BDF_BOOTLEG,2,HARDWARE_CAPCOM_CPS2,
	NULL, SfadRomInfo, SfadRomName, DrvInputInfo, NULL,
	PhoenixInit, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Street Fighter Alpha 2 (Euro 960229)

static struct BurnRomInfo Sfa2RomDesc[] = {
	{ "sz2e.03",      0x080000, 0x1061e6bb, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "sz2e.04",      0x080000, 0x22d17b26, 1 | BRF_ESS | BRF_PRG },
	{ "sz2.05",       0x080000, 0x4b442a7c, 1 | BRF_ESS | BRF_PRG },
	{ "sz2.06",       0x080000, 0x5b1d49c0, 1 | BRF_ESS | BRF_PRG },
	{ "sz2.07",       0x080000, 0x8e184246, 1 | BRF_ESS | BRF_PRG },
	{ "sz2.08",       0x080000, 0x0fe8585d, 1 | BRF_ESS | BRF_PRG },

	{ "sz2.13m",      0x400000, 0x4d1f1f22, 3 | BRF_GRA },
	{ "sz2.15m",      0x400000, 0x19cea680, 3 | BRF_GRA },
	{ "sz2.17m",      0x400000, 0xe01b4588, 3 | BRF_GRA },
	{ "sz2.19m",      0x400000, 0x0feeda64, 3 | BRF_GRA },
	{ "sz2.14m",      0x100000, 0x0560c6aa, 3 | BRF_GRA },
	{ "sz2.16m",      0x100000, 0xae940f87, 3 | BRF_GRA },
	{ "sz2.18m",      0x100000, 0x4bc3c8bc, 3 | BRF_GRA },
	{ "sz2.20m",      0x100000, 0x39e674c0, 3 | BRF_GRA },

	{ "sz2.01a",      0x020000, 0x1bc323cf, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sz2.02a",      0x020000, 0xba6a5013, 4 | BRF_ESS | BRF_PRG },

	{ "sz2.11m",      0x200000, 0xaa47a601, 5 | BRF_SND },
	{ "sz2.12m",      0x200000, 0x2237bc53, 5 | BRF_SND },
};

STD_ROM_PICK(Sfa2) STD_ROM_FN(Sfa2)

struct BurnDriver BurnDrvCpsSfa2 = {
	"sfa2", NULL, NULL, "1996",
	"Street Fighter Alpha 2 (Euro 960229)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING,2,HARDWARE_CAPCOM_CPS2,
	NULL, Sfa2RomInfo, Sfa2RomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Street Fighter Alpha 2 (USA 960306)

static struct BurnRomInfo Sfa2uRomDesc[] = {
	{ "sz2u.03",      0x080000, 0x84a09006, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "sz2u.04",      0x080000, 0xac46e5ed, 1 | BRF_ESS | BRF_PRG },
	{ "sz2u.05",      0x080000, 0x6c0c79d3, 1 | BRF_ESS | BRF_PRG },
	{ "sz2u.06",      0x080000, 0xc5c8eb63, 1 | BRF_ESS | BRF_PRG },
	{ "sz2u.07",      0x080000, 0x5de01cc5, 1 | BRF_ESS | BRF_PRG },
	{ "sz2u.08",      0x080000, 0xbea11d56, 1 | BRF_ESS | BRF_PRG },

	{ "sz2.13m",      0x400000, 0x4d1f1f22, 3 | BRF_GRA },
	{ "sz2.15m",      0x400000, 0x19cea680, 3 | BRF_GRA },
	{ "sz2.17m",      0x400000, 0xe01b4588, 3 | BRF_GRA },
	{ "sz2.19m",      0x400000, 0x0feeda64, 3 | BRF_GRA },
	{ "sz2.14m",      0x100000, 0x0560c6aa, 3 | BRF_GRA },
	{ "sz2.16m",      0x100000, 0xae940f87, 3 | BRF_GRA },
	{ "sz2.18m",      0x100000, 0x4bc3c8bc, 3 | BRF_GRA },
	{ "sz2.20m",      0x100000, 0x39e674c0, 3 | BRF_GRA },

	{ "sz2.01a",      0x020000, 0x1bc323cf, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sz2.02a",      0x020000, 0xba6a5013, 4 | BRF_ESS | BRF_PRG },

	{ "sz2.11m",      0x200000, 0xaa47a601, 5 | BRF_SND },
	{ "sz2.12m",      0x200000, 0x2237bc53, 5 | BRF_SND },
};

STD_ROM_PICK(Sfa2u) STD_ROM_FN(Sfa2u)

struct BurnDriver BurnDrvCpsSfa2u = {
	"sfa2u", "sfa2", NULL, "1996",
	"Street Fighter Alpha 2 (USA 960306)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Sfa2uRomInfo, Sfa2uRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Street Fighter Zero 2 (Japan 960227)

static struct BurnRomInfo Sfz2jRomDesc[] = {
	{ "sz2j.03a",     0x080000, 0x97461e28, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "sz2j.04a",     0x080000, 0xae4851a9, 1 | BRF_ESS | BRF_PRG },
	{ "sz2.05a",      0x080000, 0x98e8e992, 1 | BRF_ESS | BRF_PRG },
	{ "sz2.06",       0x080000, 0x5b1d49c0, 1 | BRF_ESS | BRF_PRG },
	{ "sz2j.07a",     0x080000, 0xd910b2a2, 1 | BRF_ESS | BRF_PRG },
	{ "sz2.08",       0x080000, 0x0fe8585d, 1 | BRF_ESS | BRF_PRG },

	{ "sz2.13m",      0x400000, 0x4d1f1f22, 3 | BRF_GRA },
	{ "sz2.15m",      0x400000, 0x19cea680, 3 | BRF_GRA },
	{ "sz2.17m",      0x400000, 0xe01b4588, 3 | BRF_GRA },
	{ "sz2.19m",      0x400000, 0x0feeda64, 3 | BRF_GRA },
	{ "sz2.14m",      0x100000, 0x0560c6aa, 3 | BRF_GRA },
	{ "sz2.16m",      0x100000, 0xae940f87, 3 | BRF_GRA },
	{ "sz2.18m",      0x100000, 0x4bc3c8bc, 3 | BRF_GRA },
	{ "sz2.20m",      0x100000, 0x39e674c0, 3 | BRF_GRA },

	{ "sz2.01a",      0x020000, 0x1bc323cf, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sz2.02a",      0x020000, 0xba6a5013, 4 | BRF_ESS | BRF_PRG },

	{ "sz2.11m",      0x200000, 0xaa47a601, 5 | BRF_SND },
	{ "sz2.12m",      0x200000, 0x2237bc53, 5 | BRF_SND },
};

STD_ROM_PICK(Sfz2j) STD_ROM_FN(Sfz2j)

struct BurnDriver BurnDrvCpsSfz2j = {
	"sfz2j", "sfa2", NULL, "1996",
	"Street Fighter Zero 2 (Japan 960227)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Sfz2jRomInfo, Sfz2jRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Street Fighter Zero 2 (Asia 960227)

static struct BurnRomInfo Sfz2aRomDesc[] = {
	{ "sz2a.03a",     0x080000, 0x30d2099f, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "sz2a.04a",     0x080000, 0x1cc94db1, 1 | BRF_ESS | BRF_PRG },
	{ "sz2.05a",      0x080000, 0x98e8e992, 1 | BRF_ESS | BRF_PRG },
	{ "sz2.06",       0x080000, 0x5b1d49c0, 1 | BRF_ESS | BRF_PRG },
	{ "sz2a.07a",     0x080000, 0x0aed2494, 1 | BRF_ESS | BRF_PRG },
	{ "sz2.08",       0x080000, 0x0fe8585d, 1 | BRF_ESS | BRF_PRG },

	{ "sz2.13m",      0x400000, 0x4d1f1f22, 3 | BRF_GRA },
	{ "sz2.15m",      0x400000, 0x19cea680, 3 | BRF_GRA },
	{ "sz2.17m",      0x400000, 0xe01b4588, 3 | BRF_GRA },
	{ "sz2.19m",      0x400000, 0x0feeda64, 3 | BRF_GRA },
	{ "sz2.14m",      0x100000, 0x0560c6aa, 3 | BRF_GRA },
	{ "sz2.16m",      0x100000, 0xae940f87, 3 | BRF_GRA },
	{ "sz2.18m",      0x100000, 0x4bc3c8bc, 3 | BRF_GRA },
	{ "sz2.20m",      0x100000, 0x39e674c0, 3 | BRF_GRA },

	{ "sz2.01a",      0x020000, 0x1bc323cf, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sz2.02a",      0x020000, 0xba6a5013, 4 | BRF_ESS | BRF_PRG },

	{ "sz2.11m",      0x200000, 0xaa47a601, 5 | BRF_SND },
	{ "sz2.12m",      0x200000, 0x2237bc53, 5 | BRF_SND },
};

STD_ROM_PICK(Sfz2a) STD_ROM_FN(Sfz2a)

struct BurnDriver BurnDrvCpsSfz2a = {
	"sfz2a", "sfa2", NULL, "1996",
	"Street Fighter Zero 2 (Asia 960227)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Sfz2aRomInfo, Sfz2aRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};

// Street Fighter Zero 2 (Asia 960227, Phoenix Edition)

static struct BurnRomInfo Sfz2adRomDesc[] = {
	{ "sz2ad.03a",    0x080000, 0x017f8fab, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "sz2ad.04a",    0x080000, 0xf50e5ea2, 1 | BRF_ESS | BRF_PRG },
	{ "sz2.05a",      0x080000, 0x98e8e992, 1 | BRF_ESS | BRF_PRG },
	{ "sz2.06",       0x080000, 0x5b1d49c0, 1 | BRF_ESS | BRF_PRG },
	{ "sz2a.07a",     0x080000, 0x0aed2494, 1 | BRF_ESS | BRF_PRG },
	{ "sz2.08",       0x080000, 0x0fe8585d, 1 | BRF_ESS | BRF_PRG },

	{ "sz2.13m",      0x400000, 0x4d1f1f22, 3 | BRF_GRA },
	{ "sz2.15m",      0x400000, 0x19cea680, 3 | BRF_GRA },
	{ "sz2.17m",      0x400000, 0xe01b4588, 3 | BRF_GRA },
	{ "sz2.19m",      0x400000, 0x0feeda64, 3 | BRF_GRA },
	{ "sz2.14m",      0x100000, 0x0560c6aa, 3 | BRF_GRA },
	{ "sz2.16m",      0x100000, 0xae940f87, 3 | BRF_GRA },
	{ "sz2.18m",      0x100000, 0x4bc3c8bc, 3 | BRF_GRA },
	{ "sz2.20m",      0x100000, 0x39e674c0, 3 | BRF_GRA },

	{ "sz2.01a",      0x020000, 0x1bc323cf, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sz2.02a",      0x020000, 0xba6a5013, 4 | BRF_ESS | BRF_PRG },

	{ "sz2.11m",      0x200000, 0xaa47a601, 5 | BRF_SND },
	{ "sz2.12m",      0x200000, 0x2237bc53, 5 | BRF_SND },
};

STD_ROM_PICK(Sfz2ad) STD_ROM_FN(Sfz2ad)

struct BurnDriver BurnDrvCpsSfz2ad = {
	"sfz2ad", "sfa2", NULL, "1996",
	"Street Fighter Zero 2 (Asia 960227, Phoenix Edition)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE | BDF_BOOTLEG,2,HARDWARE_CAPCOM_CPS2,
	NULL, Sfz2adRomInfo, Sfz2adRomName, DrvInputInfo, NULL,
	PhoenixInit, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Street Fighter Zero 2 (Brazil 960531)

static struct BurnRomInfo Sfz2bRomDesc[] = {
	{ "sz2b.03b",     0x080000, 0x1ac12812, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "sz2b.04b",     0x080000, 0xe4ffaf68, 1 | BRF_ESS | BRF_PRG },
	{ "sz2b.05a",     0x080000, 0xdd224156, 1 | BRF_ESS | BRF_PRG },
	{ "sz2b.06a",     0x080000, 0xa45a75a6, 1 | BRF_ESS | BRF_PRG },
	{ "sz2b.07a",     0x080000, 0x7d19d5ec, 1 | BRF_ESS | BRF_PRG },
	{ "sz2b.08",      0x080000, 0x92b66e01, 1 | BRF_ESS | BRF_PRG },

	{ "sz2.13m",      0x400000, 0x4d1f1f22, 3 | BRF_GRA },
	{ "sz2.15m",      0x400000, 0x19cea680, 3 | BRF_GRA },
	{ "sz2.17m",      0x400000, 0xe01b4588, 3 | BRF_GRA },
	{ "sz2.19m",      0x400000, 0x0feeda64, 3 | BRF_GRA },
	{ "sz2.14m",      0x100000, 0x0560c6aa, 3 | BRF_GRA },
	{ "sz2.16m",      0x100000, 0xae940f87, 3 | BRF_GRA },
	{ "sz2.18m",      0x100000, 0x4bc3c8bc, 3 | BRF_GRA },
	{ "sz2.20m",      0x100000, 0x39e674c0, 3 | BRF_GRA },

	{ "sz2.01a",      0x020000, 0x1bc323cf, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sz2.02a",      0x020000, 0xba6a5013, 4 | BRF_ESS | BRF_PRG },

	{ "sz2.11m",      0x200000, 0xaa47a601, 5 | BRF_SND },
	{ "sz2.12m",      0x200000, 0x2237bc53, 5 | BRF_SND },
};

STD_ROM_PICK(Sfz2b) STD_ROM_FN(Sfz2b)

struct BurnDriver BurnDrvCpsSfz2b = {
	"sfz2b", "sfa2", NULL, "1996",
	"Street Fighter Zero 2 (Brazil 960531)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Sfz2bRomInfo, Sfz2bRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Street Fighter Zero 2 (Brazil 960304)

static struct BurnRomInfo Sfz2br1RomDesc[] = {
	{ "sz2b.03",      0x080000, 0xe6ce530b, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "sz2b.04",      0x080000, 0x1605a0cb, 1 | BRF_ESS | BRF_PRG },
	{ "sz2.05",       0x080000, 0x4b442a7c, 1 | BRF_ESS | BRF_PRG },
	{ "sz2.06",       0x080000, 0x5b1d49c0, 1 | BRF_ESS | BRF_PRG },
	{ "sz2b.07",      0x080000, 0x947e8ac6, 1 | BRF_ESS | BRF_PRG },
	{ "sz2b.08",      0x080000, 0x92b66e01, 1 | BRF_ESS | BRF_PRG },

	{ "sz2.13m",      0x400000, 0x4d1f1f22, 3 | BRF_GRA },
	{ "sz2.15m",      0x400000, 0x19cea680, 3 | BRF_GRA },
	{ "sz2.17m",      0x400000, 0xe01b4588, 3 | BRF_GRA },
	{ "sz2.19m",      0x400000, 0x0feeda64, 3 | BRF_GRA },
	{ "sz2.14m",      0x100000, 0x0560c6aa, 3 | BRF_GRA },
	{ "sz2.16m",      0x100000, 0xae940f87, 3 | BRF_GRA },
	{ "sz2.18m",      0x100000, 0x4bc3c8bc, 3 | BRF_GRA },
	{ "sz2.20m",      0x100000, 0x39e674c0, 3 | BRF_GRA },

	{ "sz2.01a",      0x020000, 0x1bc323cf, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sz2.02a",      0x020000, 0xba6a5013, 4 | BRF_ESS | BRF_PRG },

	{ "sz2.11m",      0x200000, 0xaa47a601, 5 | BRF_SND },
	{ "sz2.12m",      0x200000, 0x2237bc53, 5 | BRF_SND },
};

STD_ROM_PICK(Sfz2br1) STD_ROM_FN(Sfz2br1)

struct BurnDriver BurnDrvCpsSfz2br1 = {
	"sfz2br1", "sfa2", NULL, "1996",
	"Street Fighter Zero 2 (Brazil 960304)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Sfz2br1RomInfo, Sfz2br1RomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Street Fighter Zero 2 (Hispanic 960304)

static struct BurnRomInfo Sfz2hRomDesc[] = {
	{ "sz2h.03",      0x080000, 0xbfeddf5b, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "sz2h.04",      0x080000, 0xea5009fb, 1 | BRF_ESS | BRF_PRG },
	{ "sz2.05",       0x080000, 0x4b442a7c, 1 | BRF_ESS | BRF_PRG },
	{ "sz2.06",       0x080000, 0x5b1d49c0, 1 | BRF_ESS | BRF_PRG },
	{ "sz2b.07",      0x080000, 0x947e8ac6, 1 | BRF_ESS | BRF_PRG },
	{ "sz2b.08",      0x080000, 0x92b66e01, 1 | BRF_ESS | BRF_PRG },

	{ "sz2.13m",      0x400000, 0x4d1f1f22, 3 | BRF_GRA },
	{ "sz2.15m",      0x400000, 0x19cea680, 3 | BRF_GRA },
	{ "sz2.17m",      0x400000, 0xe01b4588, 3 | BRF_GRA },
	{ "sz2.19m",      0x400000, 0x0feeda64, 3 | BRF_GRA },
	{ "sz2.14m",      0x100000, 0x0560c6aa, 3 | BRF_GRA },
	{ "sz2.16m",      0x100000, 0xae940f87, 3 | BRF_GRA },
	{ "sz2.18m",      0x100000, 0x4bc3c8bc, 3 | BRF_GRA },
	{ "sz2.20m",      0x100000, 0x39e674c0, 3 | BRF_GRA },

	{ "sz2.01a",      0x020000, 0x1bc323cf, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sz2.02a",      0x020000, 0xba6a5013, 4 | BRF_ESS | BRF_PRG },

	{ "sz2.11m",      0x200000, 0xaa47a601, 5 | BRF_SND },
	{ "sz2.12m",      0x200000, 0x2237bc53, 5 | BRF_SND },
};

STD_ROM_PICK(Sfz2h) STD_ROM_FN(Sfz2h)

struct BurnDriver BurnDrvCpsSfz2h = {
	"sfz2h", "sfa2", NULL, "1996",
	"Street Fighter Zero 2 (Hispanic 960304)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Sfz2hRomInfo, Sfz2hRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Street Fighter Zero 2 (Oceania 960229)

static struct BurnRomInfo Sfz2nRomDesc[] = {
	{ "sz2n.03",      0x080000, 0x58924741, 1 | BRF_ESS | BRF_PRG},		// 68k program
	{ "sz2n.04",      0x080000, 0x592a17c5, 1 | BRF_ESS | BRF_PRG},
	{ "sz2.05",       0x080000, 0x4b442a7c, 1 | BRF_ESS | BRF_PRG},
	{ "sz2.06",       0x080000, 0x5b1d49c0, 1 | BRF_ESS | BRF_PRG},
	{ "sz2.07",       0x080000, 0x8e184246, 1 | BRF_ESS | BRF_PRG},
	{ "sz2.08",       0x080000, 0x0fe8585d, 1 | BRF_ESS | BRF_PRG},

	{ "sz2.13m",      0x400000, 0x4d1f1f22, 3 | BRF_GRA },
	{ "sz2.15m",      0x400000, 0x19cea680, 3 | BRF_GRA },
	{ "sz2.17m",      0x400000, 0xe01b4588, 3 | BRF_GRA },
	{ "sz2.19m",      0x400000, 0x0feeda64, 3 | BRF_GRA },
	{ "sz2.14m",      0x100000, 0x0560c6aa, 3 | BRF_GRA },
	{ "sz2.16m",      0x100000, 0xae940f87, 3 | BRF_GRA },
	{ "sz2.18m",      0x100000, 0x4bc3c8bc, 3 | BRF_GRA },
	{ "sz2.20m",      0x100000, 0x39e674c0, 3 | BRF_GRA },

	{ "sz2.01a",      0x020000, 0x1bc323cf, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sz2.02a",      0x020000, 0xba6a5013, 4 | BRF_ESS | BRF_PRG },

	{ "sz2.11m",      0x200000, 0xaa47a601, 5 | BRF_SND },
	{ "sz2.12m",      0x200000, 0x2237bc53, 5 | BRF_SND },
};

STD_ROM_PICK(Sfz2n) STD_ROM_FN(Sfz2n)

struct BurnDriver BurnDrvCpsSfz2n = {
	"sfz2n", "sfa2", NULL, "1996",
	"Street Fighter Zero 2 (Oceania 960229)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Sfz2nRomInfo, Sfz2nRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Street Fighter Zero 2 Alpha (Asia 960826)

static struct BurnRomInfo Sfz2alRomDesc[] = {
	{ "szaa.03",      0x080000, 0x88e7023e, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "szaa.04",      0x080000, 0xae8ec36e, 1 | BRF_ESS | BRF_PRG },
	{ "szaa.05",      0x080000, 0xf053a55e, 1 | BRF_ESS | BRF_PRG },
	{ "szaa.06",      0x080000, 0xcfc0e7a8, 1 | BRF_ESS | BRF_PRG },
	{ "szaa.07",      0x080000, 0x5feb8b20, 1 | BRF_ESS | BRF_PRG },
	{ "szaa.08",      0x080000, 0x6eb6d412, 1 | BRF_ESS | BRF_PRG },

	{ "sza.13m",      0x400000, 0x4d1f1f22, 3 | BRF_GRA },
	{ "sza.15m",      0x400000, 0x19cea680, 3 | BRF_GRA },
	{ "sza.17m",      0x400000, 0xe01b4588, 3 | BRF_GRA },
	{ "sza.19m",      0x400000, 0x0feeda64, 3 | BRF_GRA },
	{ "sza.14m",      0x100000, 0x0560c6aa, 3 | BRF_GRA },
	{ "sza.16m",      0x100000, 0xae940f87, 3 | BRF_GRA },
	{ "sza.18m",      0x100000, 0x4bc3c8bc, 3 | BRF_GRA },
	{ "sza.20m",      0x100000, 0x39e674c0, 3 | BRF_GRA },

	{ "sza.01",       0x020000, 0x1bc323cf, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sza.02",       0x020000, 0xba6a5013, 4 | BRF_ESS | BRF_PRG },

	{ "sza.11m",      0x200000, 0xaa47a601, 5 | BRF_SND },
	{ "sza.12m",      0x200000, 0x2237bc53, 5 | BRF_SND },
};

STD_ROM_PICK(Sfz2al) STD_ROM_FN(Sfz2al)

struct BurnDriver BurnDrvCpsSfz2al = {
	"sfz2al", "sfa2", NULL, "1996",
	"Street Fighter Zero 2 Alpha (Asia 960826)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING,2,HARDWARE_CAPCOM_CPS2,
	NULL, Sfz2alRomInfo, Sfz2alRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Street Fighter Zero 2 Alpha (Japan 960805)

static struct BurnRomInfo Sfz2aljRomDesc[] = {
	{ "szaj.03a",     0x080000, 0xa3802fe3, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "szaj.04a",     0x080000, 0xe7ca87c7, 1 | BRF_ESS | BRF_PRG },
	{ "szaj.05a",     0x080000, 0xc88ebf88, 1 | BRF_ESS | BRF_PRG },
	{ "szaj.06a",     0x080000, 0x35ed5b7a, 1 | BRF_ESS | BRF_PRG },
	{ "szaj.07a",     0x080000, 0x975dcb3e, 1 | BRF_ESS | BRF_PRG },
	{ "szaj.08a",     0x080000, 0xdc73f2d7, 1 | BRF_ESS | BRF_PRG },

	{ "sza.13m",      0x400000, 0x4d1f1f22, 3 | BRF_GRA },
	{ "sza.15m",      0x400000, 0x19cea680, 3 | BRF_GRA },
	{ "sza.17m",      0x400000, 0xe01b4588, 3 | BRF_GRA },
	{ "sza.19m",      0x400000, 0x0feeda64, 3 | BRF_GRA },
	{ "sza.14m",      0x100000, 0x0560c6aa, 3 | BRF_GRA },
	{ "sza.16m",      0x100000, 0xae940f87, 3 | BRF_GRA },
	{ "sza.18m",      0x100000, 0x4bc3c8bc, 3 | BRF_GRA },
	{ "sza.20m",      0x100000, 0x39e674c0, 3 | BRF_GRA },

	{ "sza.01",       0x020000, 0x1bc323cf, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sza.02",       0x020000, 0xba6a5013, 4 | BRF_ESS | BRF_PRG },

	{ "sza.11m",      0x200000, 0xaa47a601, 5 | BRF_SND },
	{ "sza.12m",      0x200000, 0x2237bc53, 5 | BRF_SND },
};

STD_ROM_PICK(Sfz2alj) STD_ROM_FN(Sfz2alj)

struct BurnDriver BurnDrvCpsSfz2alj = {
	"sfz2alj", "sfz2al", NULL, "1996",
	"Street Fighter Zero 2 Alpha (Japan 960805)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Sfz2aljRomInfo, Sfz2aljRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Street Fighter Zero 2 Alpha (Hispanic 960813)

static struct BurnRomInfo Sfz2alhRomDesc[] = {
	{ "szah.03",      0x080000, 0x06f93d1d, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "szah.04",      0x080000, 0xe62ee914, 1 | BRF_ESS | BRF_PRG },
	{ "szah.05",      0x080000, 0x2b7f4b20, 1 | BRF_ESS | BRF_PRG },
	{ "sza.06",       0x080000, 0x0abda2fc, 1 | BRF_ESS | BRF_PRG },
	{ "sza.07",       0x080000, 0xe9430762, 1 | BRF_ESS | BRF_PRG },
	{ "sza.08",       0x080000, 0xb65711a9, 1 | BRF_ESS | BRF_PRG },

	{ "sza.13m",      0x400000, 0x4d1f1f22, 3 | BRF_GRA },
	{ "sza.15m",      0x400000, 0x19cea680, 3 | BRF_GRA },
	{ "sza.17m",      0x400000, 0xe01b4588, 3 | BRF_GRA },
	{ "sza.19m",      0x400000, 0x0feeda64, 3 | BRF_GRA },
	{ "sza.14m",      0x100000, 0x0560c6aa, 3 | BRF_GRA },
	{ "sza.16m",      0x100000, 0xae940f87, 3 | BRF_GRA },
	{ "sza.18m",      0x100000, 0x4bc3c8bc, 3 | BRF_GRA },
	{ "sza.20m",      0x100000, 0x39e674c0, 3 | BRF_GRA },

	{ "sza.01",       0x020000, 0x1bc323cf, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sza.02",       0x020000, 0xba6a5013, 4 | BRF_ESS | BRF_PRG },

	{ "sza.11m",      0x200000, 0xaa47a601, 5 | BRF_SND },
	{ "sza.12m",      0x200000, 0x2237bc53, 5 | BRF_SND },
};

STD_ROM_PICK(Sfz2alh) STD_ROM_FN(Sfz2alh)

struct BurnDriver BurnDrvCpsSfz2alh = {
	"sfz2alh", "sfz2al", NULL, "1996",
	"Street Fighter Zero 2 Alpha (Hispanic 960813)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Sfz2alhRomInfo, Sfz2alhRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Street Fighter Zero 2 Alpha (Brazil 960813)

static struct BurnRomInfo Sfz2albRomDesc[] = {
	{ "szab.03",      0x080000, 0xcb436eca, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "szab.04",      0x080000, 0x14534bea, 1 | BRF_ESS | BRF_PRG },
	{ "szab.05",      0x080000, 0x7fb10658, 1 | BRF_ESS | BRF_PRG },
	{ "sza.06",       0x080000, 0x0abda2fc, 1 | BRF_ESS | BRF_PRG },
	{ "sza.07",       0x080000, 0xe9430762, 1 | BRF_ESS | BRF_PRG },
	{ "sza.08",       0x080000, 0xb65711a9, 1 | BRF_ESS | BRF_PRG },

	{ "sza.13m",      0x400000, 0x4d1f1f22, 3 | BRF_GRA },
	{ "sza.15m",      0x400000, 0x19cea680, 3 | BRF_GRA },
	{ "sza.17m",      0x400000, 0xe01b4588, 3 | BRF_GRA },
	{ "sza.19m",      0x400000, 0x0feeda64, 3 | BRF_GRA },
	{ "sza.14m",      0x100000, 0x0560c6aa, 3 | BRF_GRA },
	{ "sza.16m",      0x100000, 0xae940f87, 3 | BRF_GRA },
	{ "sza.18m",      0x100000, 0x4bc3c8bc, 3 | BRF_GRA },
	{ "sza.20m",      0x100000, 0x39e674c0, 3 | BRF_GRA },

	{ "sza.01",       0x020000, 0x1bc323cf, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sza.02",       0x020000, 0xba6a5013, 4 | BRF_ESS | BRF_PRG },

	{ "sza.11m",      0x200000, 0xaa47a601, 5 | BRF_SND },
	{ "sza.12m",      0x200000, 0x2237bc53, 5 | BRF_SND },
};

STD_ROM_PICK(Sfz2alb) STD_ROM_FN(Sfz2alb)

struct BurnDriver BurnDrvCpsSfz2alb = {
	"sfz2alb", "sfz2al", NULL, "1996",
	"Street Fighter Zero 2 Alpha (Brazil 960813)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Sfz2albRomInfo, Sfz2albRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Street Fighter Zero 2 Alpha (Asia 960826, Phoenix Edition)

static struct BurnRomInfo Sfz2aldRomDesc[] = {
	{ "szaad.03",      0x80000, 0x89F9483B, 1 | BRF_ESS | BRF_PRG },
	{ "szaad.04",      0x80000, 0xaef27ae5, 1 | BRF_ESS | BRF_PRG },
	{ "szaa.05",       0x80000, 0xf053a55e, 1 | BRF_ESS | BRF_PRG },
	{ "szaa.06",       0x80000, 0xcfc0e7a8, 1 | BRF_ESS | BRF_PRG },
	{ "szaa.07",       0x80000, 0x5feb8b20, 1 | BRF_ESS | BRF_PRG },
	{ "szaa.08",       0x80000, 0x6eb6d412, 1 | BRF_ESS | BRF_PRG },

	{ "sz2.13m",      0x400000, 0x4d1f1f22, 3 | BRF_GRA },
	{ "sz2.15m",      0x400000, 0x19cea680, 3 | BRF_GRA },
	{ "sz2.17m",      0x400000, 0xe01b4588, 3 | BRF_GRA },
	{ "sz2.19m",      0x400000, 0x0feeda64, 3 | BRF_GRA },
	{ "sz2.14m",      0x100000, 0x0560c6aa, 3 | BRF_GRA },
	{ "sz2.16m",      0x100000, 0xae940f87, 3 | BRF_GRA },
	{ "sz2.18m",      0x100000, 0x4bc3c8bc, 3 | BRF_GRA },
	{ "sz2.20m",      0x100000, 0x39e674c0, 3 | BRF_GRA },

	{ "sz2.01a",      0x020000, 0x1bc323cf, 4 | BRF_ESS | BRF_PRG },
	{ "sz2.02a",      0x020000, 0xba6a5013, 4 | BRF_ESS | BRF_PRG },

	{ "sz2.11m",      0x200000, 0xaa47a601, 5 | BRF_SND },
	{ "sz2.12m",      0x200000, 0x2237bc53, 5 | BRF_SND },
};

STD_ROM_PICK(Sfz2ald) STD_ROM_FN(Sfz2ald)

struct BurnDriver BurnDrvCpsSfz2ald = {
	"sfz2ald", "sfz2al", NULL, "1996",
	"Street Fighter Zero 2 Alpha (Asia 960826, Phoenix Edition)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE | BDF_BOOTLEG,2,HARDWARE_CAPCOM_CPS2,
	NULL, Sfz2aldRomInfo, Sfz2aldRomName, DrvInputInfo, NULL,
	PhoenixInit, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Street Fighter Alpha 3 (Euro 980904)

static struct BurnRomInfo Sfa3RomDesc[] = {
	{ "sz3e.03c",     0x080000, 0x9762b206, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "sz3e.04c",     0x080000, 0x5ad3f721, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.05c",      0x080000, 0x57fd0a40, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.06c",      0x080000, 0xf6305f8b, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.07c",      0x080000, 0x6eab0f6f, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.08c",      0x080000, 0x910c4a3b, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.09c",      0x080000, 0xb29e5199, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.10b",      0x080000, 0xdeb2ff52, 1 | BRF_ESS | BRF_PRG },

	{ "sz3.13m",      0x400000, 0x0f7a60d9, 3 | BRF_GRA },
	{ "sz3.15m",      0x400000, 0x8e933741, 3 | BRF_GRA },
	{ "sz3.17m",      0x400000, 0xd6e98147, 3 | BRF_GRA },
	{ "sz3.19m",      0x400000, 0xf31a728a, 3 | BRF_GRA },
	{ "sz3.14m",      0x400000, 0x5ff98297, 3 | BRF_GRA },
	{ "sz3.16m",      0x400000, 0x52b5bdee, 3 | BRF_GRA },
	{ "sz3.18m",      0x400000, 0x40631ed5, 3 | BRF_GRA },
	{ "sz3.20m",      0x400000, 0x763409b4, 3 | BRF_GRA },

	{ "sz3.01",       0x020000, 0xde810084, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sz3.02",       0x020000, 0x72445dc4, 4 | BRF_ESS | BRF_PRG },

	{ "sz3.11m",      0x400000, 0x1c89eed1, 5 | BRF_SND },
	{ "sz3.12m",      0x400000, 0xf392b13a, 5 | BRF_SND },
};

STD_ROM_PICK(Sfa3) STD_ROM_FN(Sfa3)

struct BurnDriver BurnDrvCpsSfa3 = {
	"sfa3", NULL, NULL, "1998",
	"Street Fighter Alpha 3 (Euro 980904)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING,2,HARDWARE_CAPCOM_CPS2,
	NULL, Sfa3RomInfo, Sfa3RomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame, Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Street Fighter Alpha 3 (USA 980904)

static struct BurnRomInfo Sfa3uRomDesc[] = {
	{ "sz3u.03c",     0x080000, 0xe007da2e, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "sz3u.04c",     0x080000, 0x5f78f0e7, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.05c",      0x080000, 0x57fd0a40, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.06c",      0x080000, 0xf6305f8b, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.07c",      0x080000, 0x6eab0f6f, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.08c",      0x080000, 0x910c4a3b, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.09c",      0x080000, 0xb29e5199, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.10b",      0x080000, 0xdeb2ff52, 1 | BRF_ESS | BRF_PRG },

	{ "sz3.13m",      0x400000, 0x0f7a60d9, 3 | BRF_GRA },
	{ "sz3.15m",      0x400000, 0x8e933741, 3 | BRF_GRA },
	{ "sz3.17m",      0x400000, 0xd6e98147, 3 | BRF_GRA },
	{ "sz3.19m",      0x400000, 0xf31a728a, 3 | BRF_GRA },
	{ "sz3.14m",      0x400000, 0x5ff98297, 3 | BRF_GRA },
	{ "sz3.16m",      0x400000, 0x52b5bdee, 3 | BRF_GRA },
	{ "sz3.18m",      0x400000, 0x40631ed5, 3 | BRF_GRA },
	{ "sz3.20m",      0x400000, 0x763409b4, 3 | BRF_GRA },

	{ "sz3.01",       0x020000, 0xde810084, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sz3.02",       0x020000, 0x72445dc4, 4 | BRF_ESS | BRF_PRG },

	{ "sz3.11m",      0x400000, 0x1c89eed1, 5 | BRF_SND },
	{ "sz3.12m",      0x400000, 0xf392b13a, 5 | BRF_SND },
};

STD_ROM_PICK(Sfa3u) STD_ROM_FN(Sfa3u)

struct BurnDriver BurnDrvCpsSfa3u = {
	"sfa3u", "sfa3", NULL, "1998",
	"Street Fighter Alpha 3 (USA 980904)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Sfa3uRomInfo, Sfa3uRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame, Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Street Fighter Alpha 3 (USA 980629)

static struct BurnRomInfo Sfa3ur1RomDesc[] = {
	{ "sz3u.03",      0x080000, 0xb5984a19, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "sz3u.04",      0x080000, 0x7e8158ba, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.05",       0x080000, 0x9b21518a, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.06",       0x080000, 0xe7a6c3a7, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.07",       0x080000, 0xec4c0cfd, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.08",       0x080000, 0x5c7e7240, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.09",       0x080000, 0xc5589553, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.10",       0x080000, 0xa9717252, 1 | BRF_ESS | BRF_PRG },

	{ "sz3.13m",      0x400000, 0x0f7a60d9, 3 | BRF_GRA },
	{ "sz3.15m",      0x400000, 0x8e933741, 3 | BRF_GRA },
	{ "sz3.17m",      0x400000, 0xd6e98147, 3 | BRF_GRA },
	{ "sz3.19m",      0x400000, 0xf31a728a, 3 | BRF_GRA },
	{ "sz3.14m",      0x400000, 0x5ff98297, 3 | BRF_GRA },
	{ "sz3.16m",      0x400000, 0x52b5bdee, 3 | BRF_GRA },
	{ "sz3.18m",      0x400000, 0x40631ed5, 3 | BRF_GRA },
	{ "sz3.20m",      0x400000, 0x763409b4, 3 | BRF_GRA },

	{ "sz3.01",       0x020000, 0xde810084, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sz3.02",       0x020000, 0x72445dc4, 4 | BRF_ESS | BRF_PRG },

	{ "sz3.11m",      0x400000, 0x1c89eed1, 5 | BRF_SND },
	{ "sz3.12m",      0x400000, 0xf392b13a, 5 | BRF_SND },
};

STD_ROM_PICK(Sfa3ur1) STD_ROM_FN(Sfa3ur1)

struct BurnDriver BurnDrvCpsSfa3ur1 = {
	"sfa3ur1", "sfa3", NULL, "1998",
	"Street Fighter Alpha 3 (USA 980629)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Sfa3ur1RomInfo, Sfa3ur1RomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame, Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Street Fighter Zero 3 (Japan 980904)

static struct BurnRomInfo Sfz3jRomDesc[] = {
	{ "sz3j.03c",     0x080000, 0xcadf4a51, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "sz3j.04c",     0x080000, 0xfcb31228, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.05c",      0x080000, 0x57fd0a40, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.06c",      0x080000, 0xf6305f8b, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.07c",      0x080000, 0x6eab0f6f, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.08c",      0x080000, 0x910c4a3b, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.09c",      0x080000, 0xb29e5199, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.10b",      0x080000, 0xdeb2ff52, 1 | BRF_ESS | BRF_PRG },

	{ "sz3.13m",      0x400000, 0x0f7a60d9, 3 | BRF_GRA },
	{ "sz3.15m",      0x400000, 0x8e933741, 3 | BRF_GRA },
	{ "sz3.17m",      0x400000, 0xd6e98147, 3 | BRF_GRA },
	{ "sz3.19m",      0x400000, 0xf31a728a, 3 | BRF_GRA },
	{ "sz3.14m",      0x400000, 0x5ff98297, 3 | BRF_GRA },
	{ "sz3.16m",      0x400000, 0x52b5bdee, 3 | BRF_GRA },
	{ "sz3.18m",      0x400000, 0x40631ed5, 3 | BRF_GRA },
	{ "sz3.20m",      0x400000, 0x763409b4, 3 | BRF_GRA },

	{ "sz3.01",       0x020000, 0xde810084, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sz3.02",       0x020000, 0x72445dc4, 4 | BRF_ESS | BRF_PRG },

	{ "sz3.11m",      0x400000, 0x1c89eed1, 5 | BRF_SND },
	{ "sz3.12m",      0x400000, 0xf392b13a, 5 | BRF_SND },
};

STD_ROM_PICK(Sfz3j) STD_ROM_FN(Sfz3j)

struct BurnDriver BurnDrvCpsSfz3j = {
	"sfz3j", "sfa3", NULL, "1998",
	"Street Fighter Zero 3 (Japan 980904)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Sfz3jRomInfo, Sfz3jRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame, Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Street Fighter Zero 3 (Japan 980727)

static struct BurnRomInfo Sfz3jr1RomDesc[] = {
	{ "sz3j.03a",     0x080000, 0x6ee0beae, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "sz3j.04a",     0x080000, 0xa6e2978d, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.05a",      0x080000, 0x05964b7d, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.06a",      0x080000, 0x78ce2179, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.07a",      0x080000, 0x398bf52f, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.08a",      0x080000, 0x866d0588, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.09a",      0x080000, 0x2180892c, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.10",       0x080000, 0xa9717252, 1 | BRF_ESS | BRF_PRG },

	{ "sz3.13m",      0x400000, 0x0f7a60d9, 3 | BRF_GRA },
	{ "sz3.15m",      0x400000, 0x8e933741, 3 | BRF_GRA },
	{ "sz3.17m",      0x400000, 0xd6e98147, 3 | BRF_GRA },
	{ "sz3.19m",      0x400000, 0xf31a728a, 3 | BRF_GRA },
	{ "sz3.14m",      0x400000, 0x5ff98297, 3 | BRF_GRA },
	{ "sz3.16m",      0x400000, 0x52b5bdee, 3 | BRF_GRA },
	{ "sz3.18m",      0x400000, 0x40631ed5, 3 | BRF_GRA },
	{ "sz3.20m",      0x400000, 0x763409b4, 3 | BRF_GRA },

	{ "sz3.01",       0x020000, 0xde810084, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sz3.02",       0x020000, 0x72445dc4, 4 | BRF_ESS | BRF_PRG },

	{ "sz3.11m",      0x400000, 0x1c89eed1, 5 | BRF_SND },
	{ "sz3.12m",      0x400000, 0xf392b13a, 5 | BRF_SND },
};

STD_ROM_PICK(Sfz3jr1) STD_ROM_FN(Sfz3jr1)

struct BurnDriver BurnDrvCpsSfz3jr1 = {
	"sfz3jr1", "sfa3", NULL, "1998",
	"Street Fighter Zero 3 (Japan 980727)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Sfz3jr1RomInfo, Sfz3jr1RomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame, Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Street Fighter Zero 3 (Japan 980629)

static struct BurnRomInfo Sfz3jr2RomDesc[] = {
	{ "sz3j.03",      0x080000, 0xf7cb4b13, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "sz3j.04",      0x080000, 0x0846c29d, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.05",       0x080000, 0x9b21518a, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.06",       0x080000, 0xe7a6c3a7, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.07",       0x080000, 0xec4c0cfd, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.08",       0x080000, 0x5c7e7240, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.09",       0x080000, 0xc5589553, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.10",       0x080000, 0xa9717252, 1 | BRF_ESS | BRF_PRG },

	{ "sz3.13m",      0x400000, 0x0f7a60d9, 3 | BRF_GRA },
	{ "sz3.15m",      0x400000, 0x8e933741, 3 | BRF_GRA },
	{ "sz3.17m",      0x400000, 0xd6e98147, 3 | BRF_GRA },
	{ "sz3.19m",      0x400000, 0xf31a728a, 3 | BRF_GRA },
	{ "sz3.14m",      0x400000, 0x5ff98297, 3 | BRF_GRA },
	{ "sz3.16m",      0x400000, 0x52b5bdee, 3 | BRF_GRA },
	{ "sz3.18m",      0x400000, 0x40631ed5, 3 | BRF_GRA },
	{ "sz3.20m",      0x400000, 0x763409b4, 3 | BRF_GRA },

	{ "sz3.01",       0x020000, 0xde810084, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sz3.02",       0x020000, 0x72445dc4, 4 | BRF_ESS | BRF_PRG },

	{ "sz3.11m",      0x400000, 0x1c89eed1, 5 | BRF_SND },
	{ "sz3.12m",      0x400000, 0xf392b13a, 5 | BRF_SND },
};

STD_ROM_PICK(Sfz3jr2) STD_ROM_FN(Sfz3jr2)

struct BurnDriver BurnDrvCpsSfz3jr2 = {
	"sfz3jr2", "sfa3", NULL, "1998",
	"Street Fighter Zero 3 (Japan 980629)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Sfz3jr2RomInfo, Sfz3jr2RomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame, Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Street Fighter Zero 3 (Asia 980904)

static struct BurnRomInfo sfz3aRomDesc[] = {
	{ "sz3a.03d",     0x080000, 0xd7e140d6, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "sz3a.04d",     0x080000, 0xe06869a2, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.05c",      0x080000, 0x57fd0a40, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.06c",      0x080000, 0xf6305f8b, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.07c",      0x080000, 0x6eab0f6f, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.08c",      0x080000, 0x910c4a3b, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.09c",      0x080000, 0xb29e5199, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.10b",      0x080000, 0xdeb2ff52, 1 | BRF_ESS | BRF_PRG },

	{ "sz3.13m",      0x400000, 0x0f7a60d9, 3 | BRF_GRA },
	{ "sz3.15m",      0x400000, 0x8e933741, 3 | BRF_GRA },
	{ "sz3.17m",      0x400000, 0xd6e98147, 3 | BRF_GRA },
	{ "sz3.19m",      0x400000, 0xf31a728a, 3 | BRF_GRA },
	{ "sz3.14m",      0x400000, 0x5ff98297, 3 | BRF_GRA },
	{ "sz3.16m",      0x400000, 0x52b5bdee, 3 | BRF_GRA },
	{ "sz3.18m",      0x400000, 0x40631ed5, 3 | BRF_GRA },
	{ "sz3.20m",      0x400000, 0x763409b4, 3 | BRF_GRA },

	{ "sz3.01",       0x020000, 0xde810084, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sz3.02",       0x020000, 0x72445dc4, 4 | BRF_ESS | BRF_PRG },

	{ "sz3.11m",      0x400000, 0x1c89eed1, 5 | BRF_SND },
	{ "sz3.12m",      0x400000, 0xf392b13a, 5 | BRF_SND },
};

STD_ROM_PICK(sfz3a) STD_ROM_FN(sfz3a)

struct BurnDriver BurnDrvCpssfz3a = {
	"sfz3a", "sfa3", NULL, "1998",
	"Street Fighter Zero 3 (Asia 980904)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, sfz3aRomInfo, sfz3aRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame, Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Street Fighter Zero 3 (Asia 980701)

static struct BurnRomInfo sfz3ar1RomDesc[] = {
	{ "sz3a.03a",     0x080000, 0x29c681fd, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "sz3a.04",      0x080000, 0x9ddd1484, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.05",       0x080000, 0x9b21518a, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.06",       0x080000, 0xe7a6c3a7, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.07",       0x080000, 0xec4c0cfd, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.08",       0x080000, 0x5c7e7240, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.09",       0x080000, 0xc5589553, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.10",       0x080000, 0xa9717252, 1 | BRF_ESS | BRF_PRG },

	{ "sz3.13m",      0x400000, 0x0f7a60d9, 3 | BRF_GRA },
	{ "sz3.15m",      0x400000, 0x8e933741, 3 | BRF_GRA },
	{ "sz3.17m",      0x400000, 0xd6e98147, 3 | BRF_GRA },
	{ "sz3.19m",      0x400000, 0xf31a728a, 3 | BRF_GRA },
	{ "sz3.14m",      0x400000, 0x5ff98297, 3 | BRF_GRA },
	{ "sz3.16m",      0x400000, 0x52b5bdee, 3 | BRF_GRA },
	{ "sz3.18m",      0x400000, 0x40631ed5, 3 | BRF_GRA },
	{ "sz3.20m",      0x400000, 0x763409b4, 3 | BRF_GRA },

	{ "sz3.01",       0x020000, 0xde810084, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sz3.02",       0x020000, 0x72445dc4, 4 | BRF_ESS | BRF_PRG },

	{ "sz3.11m",      0x400000, 0x1c89eed1, 5 | BRF_SND },
	{ "sz3.12m",      0x400000, 0xf392b13a, 5 | BRF_SND },
};

STD_ROM_PICK(sfz3ar1) STD_ROM_FN(sfz3ar1)

struct BurnDriver BurnDrvCpssfz3ar1 = {
	"sfz3ar1", "sfa3", NULL, "1998",
	"Street Fighter Zero 3 (Asia 980701)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, sfz3ar1RomInfo, sfz3ar1RomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame, Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Street Fighter Alpha 3 (Brazil 980629)

static struct BurnRomInfo Sfa3bRomDesc[] = {
	{ "sz3b.03",	  0x080000, 0x046c9b4d, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "sz3b.04",	  0x080000, 0xda211919, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.05",	  0x080000, 0x9b21518a, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.06",	  0x080000, 0xe7a6c3a7, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.07",	  0x080000, 0xec4c0cfd, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.08",	  0x080000, 0x5c7e7240, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.09",	  0x080000, 0xc5589553, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.10",	  0x080000, 0xa9717252, 1 | BRF_ESS | BRF_PRG },

	{ "sz3.13m",      0x400000, 0x0f7a60d9, 3 | BRF_GRA },
	{ "sz3.15m",      0x400000, 0x8e933741, 3 | BRF_GRA },
	{ "sz3.17m",      0x400000, 0xd6e98147, 3 | BRF_GRA },
	{ "sz3.19m",      0x400000, 0xf31a728a, 3 | BRF_GRA },
	{ "sz3.14m",      0x400000, 0x5ff98297, 3 | BRF_GRA },
	{ "sz3.16m",      0x400000, 0x52b5bdee, 3 | BRF_GRA },
	{ "sz3.18m",      0x400000, 0x40631ed5, 3 | BRF_GRA },
	{ "sz3.20m",      0x400000, 0x763409b4, 3 | BRF_GRA },

	{ "sz3.01",       0x020000, 0xde810084, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sz3.02",       0x020000, 0x72445dc4, 4 | BRF_ESS | BRF_PRG },

	{ "sz3.11m",      0x400000, 0x1c89eed1, 5 | BRF_SND },
	{ "sz3.12m",      0x400000, 0xf392b13a, 5 | BRF_SND },
};

STD_ROM_PICK(Sfa3b) STD_ROM_FN(Sfa3b)

struct BurnDriver BurnDrvCpsSfa3b = {
	"sfa3b", "sfa3", NULL, "1998",
	"Street Fighter Alpha 3 (Brazil 980629)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Sfa3bRomInfo, Sfa3bRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame, Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Street Fighter Alpha 3 (USA 980904, Phoenix Edition)

static struct BurnRomInfo Sfa3udRomDesc[] = {
	{ "sz3ud.03c",     0x80000, 0x6db8add7, 1 | BRF_ESS | BRF_PRG },
	{ "sz3ud.04c",     0x80000, 0xd9c65a26, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.05c",       0x80000, 0x57fd0a40, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.06c",       0x80000, 0xf6305f8b, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.07c",       0x80000, 0x6eab0f6f, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.08c",       0x80000, 0x910c4a3b, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.09c",       0x80000, 0xb29e5199, 1 | BRF_ESS | BRF_PRG },
	{ "sz3.10b",       0x80000, 0xdeb2ff52, 1 | BRF_ESS | BRF_PRG },

	{ "sz3.13m",      0x400000, 0x0f7a60d9, 3 | BRF_GRA },
	{ "sz3.15m",      0x400000, 0x8e933741, 3 | BRF_GRA },
	{ "sz3.17m",      0x400000, 0xd6e98147, 3 | BRF_GRA },
	{ "sz3.19m",      0x400000, 0xf31a728a, 3 | BRF_GRA },
	{ "sz3.14m",      0x400000, 0x5ff98297, 3 | BRF_GRA },
	{ "sz3.16m",      0x400000, 0x52b5bdee, 3 | BRF_GRA },
	{ "sz3.18m",      0x400000, 0x40631ed5, 3 | BRF_GRA },
	{ "sz3.20m",      0x400000, 0x763409b4, 3 | BRF_GRA },

	{ "sz3.01",       0x020000, 0xde810084, 4 | BRF_ESS | BRF_PRG },
	{ "sz3.02",       0x020000, 0x72445dc4, 4 | BRF_ESS | BRF_PRG },

	{ "sz3.11m",      0x400000, 0x1c89eed1, 5 | BRF_SND },
	{ "sz3.12m",      0x400000, 0xf392b13a, 5 | BRF_SND },
};

STD_ROM_PICK(Sfa3ud) STD_ROM_FN(Sfa3ud)

struct BurnDriver BurnDrvCpsSfa3ud = {
	"sfa3ud", "sfa3", NULL, "1998",
	"Street Fighter Alpha 3 (USA 980904, Phoenix Edition)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE | BDF_BOOTLEG,2,HARDWARE_CAPCOM_CPS2,
	NULL, Sfa3udRomInfo, Sfa3udRomName, DrvInputInfo, NULL,
	PhoenixInit, CpsExit,Cps2Frame, Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Super Gem Fighter Mini Mix (USA 970904)

static struct BurnRomInfo SgemfRomDesc[] = {
	{ "pcfu.03",      0x080000, 0xac2e8566, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "pcf.04",       0x080000, 0xf4314c96, 1 | BRF_ESS | BRF_PRG },
	{ "pcf.05",       0x080000, 0x215655f6, 1 | BRF_ESS | BRF_PRG },
	{ "pcf.06",       0x080000, 0xea6f13ea, 1 | BRF_ESS | BRF_PRG },
	{ "pcf.07",       0x080000, 0x5ac6d5ea, 1 | BRF_ESS | BRF_PRG },

	{ "pcf.13m",      0x400000, 0x22d72ab9, 3 | BRF_GRA },
	{ "pcf.15m",      0x400000, 0x16a4813c, 3 | BRF_GRA },
	{ "pcf.17m",      0x400000, 0x1097e035, 3 | BRF_GRA },
	{ "pcf.19m",      0x400000, 0xd362d874, 3 | BRF_GRA },
	{ "pcf.14m",      0x100000, 0x0383897c, 3 | BRF_GRA },
	{ "pcf.16m",      0x100000, 0x76f91084, 3 | BRF_GRA },
	{ "pcf.18m",      0x100000, 0x756c3754, 3 | BRF_GRA },
	{ "pcf.20m",      0x100000, 0x9ec9277d, 3 | BRF_GRA },

	{ "pcf.01",       0x020000, 0x254e5f33, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "pcf.02",       0x020000, 0x6902f4f9, 4 | BRF_ESS | BRF_PRG },

	{ "pcf.11m",      0x400000, 0xa5dea005, 5 | BRF_SND },
	{ "pcf.12m",      0x400000, 0x4ce235fe, 5 | BRF_SND },
};

STD_ROM_PICK(Sgemf) STD_ROM_FN(Sgemf)

struct BurnDriver BurnDrvCpsSgemf = {
	"sgemf", NULL, NULL, "1997",
	"Super Gem Fighter Mini Mix (USA 970904)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING,2,HARDWARE_CAPCOM_CPS2,
	NULL, SgemfRomInfo, SgemfRomName, sgemfInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Super Gem Fighter Mini Mix (USA 970904, Phoenix Edition)

static struct BurnRomInfo SgemfdRomDesc[] = {
	{ "pcfud.03",     0x080000, 0x8b83674a, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "pcfd.04",      0x080000, 0xb58f1d03, 1 | BRF_ESS | BRF_PRG },
	{ "pcf.05",       0x080000, 0x215655f6, 1 | BRF_ESS | BRF_PRG },
	{ "pcf.06",       0x080000, 0xea6f13ea, 1 | BRF_ESS | BRF_PRG },
	{ "pcf.07",       0x080000, 0x5ac6d5ea, 1 | BRF_ESS | BRF_PRG },

	{ "pcf.13m",      0x400000, 0x22d72ab9, 3 | BRF_GRA },
	{ "pcf.15m",      0x400000, 0x16a4813c, 3 | BRF_GRA },
	{ "pcf.17m",      0x400000, 0x1097e035, 3 | BRF_GRA },
	{ "pcf.19m",      0x400000, 0xd362d874, 3 | BRF_GRA },
	{ "pcf.14m",      0x100000, 0x0383897c, 3 | BRF_GRA },
	{ "pcf.16m",      0x100000, 0x76f91084, 3 | BRF_GRA },
	{ "pcf.18m",      0x100000, 0x756c3754, 3 | BRF_GRA },
	{ "pcf.20m",      0x100000, 0x9ec9277d, 3 | BRF_GRA },

	{ "pcf.01",       0x020000, 0x254e5f33, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "pcf.02",       0x020000, 0x6902f4f9, 4 | BRF_ESS | BRF_PRG },

	{ "pcf.11m",      0x400000, 0xa5dea005, 5 | BRF_SND },
	{ "pcf.12m",      0x400000, 0x4ce235fe, 5 | BRF_SND },
};

STD_ROM_PICK(Sgemfd) STD_ROM_FN(Sgemfd)

struct BurnDriver BurnDrvCpsSgemfd = {
	"sgemfd", "sgemf", NULL, "1997",
	"Super Gem Fighter Mini Mix (USA 970904, Phoenix Edition)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE | BDF_BOOTLEG,2,HARDWARE_CAPCOM_CPS2,
	NULL, SgemfdRomInfo, SgemfdRomName, sgemfInputInfo, NULL,
	PhoenixInit, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Pocket Fighter (Japan 970904)

static struct BurnRomInfo PfghtjRomDesc[] = {
	{ "pcfj.03",      0x080000, 0x681da43e, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "pcf.04",       0x080000, 0xf4314c96, 1 | BRF_ESS | BRF_PRG },
	{ "pcf.05",       0x080000, 0x215655f6, 1 | BRF_ESS | BRF_PRG },
	{ "pcf.06",       0x080000, 0xea6f13ea, 1 | BRF_ESS | BRF_PRG },
	{ "pcf.07",       0x080000, 0x5ac6d5ea, 1 | BRF_ESS | BRF_PRG },

	{ "pcf.13m",      0x400000, 0x22d72ab9, 3 | BRF_GRA },
	{ "pcf.15m",      0x400000, 0x16a4813c, 3 | BRF_GRA },
	{ "pcf.17m",      0x400000, 0x1097e035, 3 | BRF_GRA },
	{ "pcf.19m",      0x400000, 0xd362d874, 3 | BRF_GRA },
	{ "pcf.14m",      0x100000, 0x0383897c, 3 | BRF_GRA },
	{ "pcf.16m",      0x100000, 0x76f91084, 3 | BRF_GRA },
	{ "pcf.18m",      0x100000, 0x756c3754, 3 | BRF_GRA },
	{ "pcf.20m",      0x100000, 0x9ec9277d, 3 | BRF_GRA },

	{ "pcf.01",       0x020000, 0x254e5f33, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "pcf.02",       0x020000, 0x6902f4f9, 4 | BRF_ESS | BRF_PRG },

	{ "pcf.11m",      0x400000, 0xa5dea005, 5 | BRF_SND },
	{ "pcf.12m",      0x400000, 0x4ce235fe, 5 | BRF_SND },
};


STD_ROM_PICK(Pfghtj) STD_ROM_FN(Pfghtj)

struct BurnDriver BurnDrvCpsPfghtj = {
	"pfghtj", "sgemf", NULL, "1997",
	"Pocket Fighter (Japan 970904)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, PfghtjRomInfo, PfghtjRomName, sgemfInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Super Gem Fighter Mini Mix (Asia 970904)

static struct BurnRomInfo SgemfaRomDesc[] = {
	{ "pcfa.03",      0x080000, 0xe17c089a, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "pcf.04",       0x080000, 0xf4314c96, 1 | BRF_ESS | BRF_PRG },
	{ "pcf.05",       0x080000, 0x215655f6, 1 | BRF_ESS | BRF_PRG },
	{ "pcf.06",       0x080000, 0xea6f13ea, 1 | BRF_ESS | BRF_PRG },
	{ "pcf.07",       0x080000, 0x5ac6d5ea, 1 | BRF_ESS | BRF_PRG },

	{ "pcf.13m",      0x400000, 0x22d72ab9, 3 | BRF_GRA },
	{ "pcf.15m",      0x400000, 0x16a4813c, 3 | BRF_GRA },
	{ "pcf.17m",      0x400000, 0x1097e035, 3 | BRF_GRA },
	{ "pcf.19m",      0x400000, 0xd362d874, 3 | BRF_GRA },
	{ "pcf.14m",      0x100000, 0x0383897c, 3 | BRF_GRA },
	{ "pcf.16m",      0x100000, 0x76f91084, 3 | BRF_GRA },
	{ "pcf.18m",      0x100000, 0x756c3754, 3 | BRF_GRA },
	{ "pcf.20m",      0x100000, 0x9ec9277d, 3 | BRF_GRA },

	{ "pcf.01",       0x020000, 0x254e5f33, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "pcf.02",       0x020000, 0x6902f4f9, 4 | BRF_ESS | BRF_PRG },

	{ "pcf.11m",      0x400000, 0xa5dea005, 5 | BRF_SND },
	{ "pcf.12m",      0x400000, 0x4ce235fe, 5 | BRF_SND },
};

STD_ROM_PICK(Sgemfa) STD_ROM_FN(Sgemfa)

struct BurnDriver BurnDrvCpsSgemfa = {
	"sgemfa", "sgemf", NULL, "1997",
	"Super Gem Fighter Mini Mix (Asia 970904)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, SgemfaRomInfo, SgemfaRomName, sgemfInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Super Gem Fighter Mini Mix (Hispanic 970904)

static struct BurnRomInfo SgemfhRomDesc[] = {
	{ "pcfh.03",      0x080000, 0xe9103347, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "pcf.04",       0x080000, 0xf4314c96, 1 | BRF_ESS | BRF_PRG },
	{ "pcf.05",       0x080000, 0x215655f6, 1 | BRF_ESS | BRF_PRG },
	{ "pcf.06",       0x080000, 0xea6f13ea, 1 | BRF_ESS | BRF_PRG },
	{ "pcf.07",       0x080000, 0x5ac6d5ea, 1 | BRF_ESS | BRF_PRG },

	{ "pcf.13m",      0x400000, 0x22d72ab9, 3 | BRF_GRA },
	{ "pcf.15m",      0x400000, 0x16a4813c, 3 | BRF_GRA },
	{ "pcf.17m",      0x400000, 0x1097e035, 3 | BRF_GRA },
	{ "pcf.19m",      0x400000, 0xd362d874, 3 | BRF_GRA },
	{ "pcf.14m",      0x100000, 0x0383897c, 3 | BRF_GRA },
	{ "pcf.16m",      0x100000, 0x76f91084, 3 | BRF_GRA },
	{ "pcf.18m",      0x100000, 0x756c3754, 3 | BRF_GRA },
	{ "pcf.20m",      0x100000, 0x9ec9277d, 3 | BRF_GRA },

	{ "pcf.01",       0x020000, 0x254e5f33, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "pcf.02",       0x020000, 0x6902f4f9, 4 | BRF_ESS | BRF_PRG },

	{ "pcf.11m",      0x400000, 0xa5dea005, 5 | BRF_SND },
	{ "pcf.12m",      0x400000, 0x4ce235fe, 5 | BRF_SND },
};

STD_ROM_PICK(Sgemfh) STD_ROM_FN(Sgemfh)

struct BurnDriver BurnDrvCpsSgemfh = {
	"sgemfh", "sgemf", NULL, "1997",
	"Super Gem Fighter Mini Mix (Hispanic 970904)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, SgemfhRomInfo, SgemfhRomName, sgemfInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Super Puzzle Fighter II Turbo (USA 960620)

static struct BurnRomInfo Spf2tRomDesc[] = {
	{ "pzfu.03a",     0x080000, 0x346e62ef, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "pzf.04",       0x080000, 0xb80649e2, 1 | BRF_ESS | BRF_PRG },

	{ "pzf.14m",      0x100000, 0x2d4881cb, 3 | BRF_GRA },
	{ "pzf.16m",      0x100000, 0x4b0fd1be, 3 | BRF_GRA },
	{ "pzf.18m",      0x100000, 0xe43aac33, 3 | BRF_GRA },
	{ "pzf.20m",      0x100000, 0x7f536ff1, 3 | BRF_GRA },

	{ "pzf.01",       0x020000, 0x600fb2a3, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "pzf.02",       0x020000, 0x496076e0, 4 | BRF_ESS | BRF_PRG },

	{ "pzf.11m",      0x200000, 0x78442743, 5 | BRF_SND },
	{ "pzf.12m",      0x200000, 0x399d2c7b, 5 | BRF_SND },
};

STD_ROM_PICK(Spf2t) STD_ROM_FN(Spf2t)

struct BurnDriver BurnDrvCpsSpf2t = {
	"spf2t", NULL, NULL, "1996",
	"Super Puzzle Fighter II Turbo (USA 960620)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING,2,HARDWARE_CAPCOM_CPS2,
	NULL, Spf2tRomInfo, Spf2tRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Super Puzzle Fighter II X (Japan 960531)

static struct BurnRomInfo Spf2xjRomDesc[] = {
	{ "pzfj.03a",     0x080000, 0x2070554a, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "pzf.04",       0x080000, 0xb80649e2, 1 | BRF_ESS | BRF_PRG },

	{ "pzf.14m",      0x100000, 0x2d4881cb, 3 | BRF_GRA },
	{ "pzf.16m",      0x100000, 0x4b0fd1be, 3 | BRF_GRA },
	{ "pzf.18m",      0x100000, 0xe43aac33, 3 | BRF_GRA },
	{ "pzf.20m",      0x100000, 0x7f536ff1, 3 | BRF_GRA },

	{ "pzf.01",       0x020000, 0x600fb2a3, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "pzf.02",       0x020000, 0x496076e0, 4 | BRF_ESS | BRF_PRG },

	{ "pzf.11m",      0x200000, 0x78442743, 5 | BRF_SND },
	{ "pzf.12m",      0x200000, 0x399d2c7b, 5 | BRF_SND },
};

STD_ROM_PICK(Spf2xj) STD_ROM_FN(Spf2xj)

struct BurnDriver BurnDrvCpsSpf2xj = {
	"spf2xj", "spf2t", NULL, "1996",
	"Super Puzzle Fighter II X (Japan 960531)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Spf2xjRomInfo, Spf2xjRomName, spf2xInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Super Puzzle Fighter II Turbo (Asia 960529)

static struct BurnRomInfo Spf2taRomDesc[] = {
	{ "pzfa.03",	  0x080000, 0x3cecfa78, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "pzf.04",	   0x080000, 0xb80649e2, 1 | BRF_ESS | BRF_PRG },

	{ "pzf.14m",      0x100000, 0x2d4881cb, 3 | BRF_GRA },
	{ "pzf.16m",      0x100000, 0x4b0fd1be, 3 | BRF_GRA },
	{ "pzf.18m",      0x100000, 0xe43aac33, 3 | BRF_GRA },
	{ "pzf.20m",      0x100000, 0x7f536ff1, 3 | BRF_GRA },

	{ "pzf.01",       0x020000, 0x600fb2a3, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "pzf.02",       0x020000, 0x496076e0, 4 | BRF_ESS | BRF_PRG },

	{ "pzf.11m",      0x200000, 0x78442743, 5 | BRF_SND },
	{ "pzf.12m",      0x200000, 0x399d2c7b, 5 | BRF_SND },
};

STD_ROM_PICK(Spf2ta) STD_ROM_FN(Spf2ta)

struct BurnDriver BurnDrvCpsSpf2ta = {
	"spf2ta", "spf2t", NULL, "1996",
	"Super Puzzle Fighter II Turbo (Asia 960529)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Spf2taRomInfo, Spf2taRomName, spf2xInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Super Puzzle Fighter II Turbo (Hispanic 960531)

static struct BurnRomInfo Spf2thRomDesc[] = {
	{ "pzfh.03",	  0x080000, 0x20510f2d, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "pzf.04",	      0x080000, 0xb80649e2, 1 | BRF_ESS | BRF_PRG },

	{ "pzf.14m",      0x100000, 0x2d4881cb, 3 | BRF_GRA },
	{ "pzf.16m",      0x100000, 0x4b0fd1be, 3 | BRF_GRA },
	{ "pzf.18m",      0x100000, 0xe43aac33, 3 | BRF_GRA },
	{ "pzf.20m",      0x100000, 0x7f536ff1, 3 | BRF_GRA },

	{ "pzf.01",       0x020000, 0x600fb2a3, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "pzf.02",       0x020000, 0x496076e0, 4 | BRF_ESS | BRF_PRG },

	{ "pzf.11m",      0x200000, 0x78442743, 5 | BRF_SND },
	{ "pzf.12m",      0x200000, 0x399d2c7b, 5 | BRF_SND },
};

STD_ROM_PICK(Spf2th) STD_ROM_FN(Spf2th)

struct BurnDriver BurnDrvCpsSpf2th = {
	"spf2th", "spf2t", NULL, "1996",
	"Super Puzzle Fighter II Turbo (Hispanic 960531)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Spf2thRomInfo, Spf2thRomName, spf2xInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Super Puzzle Fighter II X (Japan 960531, Phoenix Edition)

static struct BurnRomInfo Spf2xjdRomDesc[] = {
	{ "pzfjd.03a",     0x80000, 0x5e85ed08, 1 | BRF_ESS | BRF_PRG },
	{ "pzf.04",        0x80000, 0xb80649e2, 1 | BRF_ESS | BRF_PRG },

	{ "pzf.14m",      0x100000, 0x2d4881cb, 3 | BRF_GRA },			 // 3
	{ "pzf.16m",      0x100000, 0x4b0fd1be, 3 | BRF_GRA },
	{ "pzf.18m",      0x100000, 0xe43aac33, 3 | BRF_GRA },
	{ "pzf.20m",      0x100000, 0x7f536ff1, 3 | BRF_GRA },

	{ "pzf.01",       0x020000, 0x600fb2a3, 4 | BRF_ESS | BRF_PRG }, // 7
	{ "pzf.02",       0x020000, 0x496076e0, 4 | BRF_ESS | BRF_PRG },

	{ "pzf.11m",      0x200000, 0x78442743, 5 | BRF_SND },
	{ "pzf.12m",      0x200000, 0x399d2c7b, 5 | BRF_SND },
};

STD_ROM_PICK(Spf2xjd) STD_ROM_FN(Spf2xjd)

struct BurnDriver BurnDrvCpsSpf2xjd = {
	"spf2xjd", "spf2t", NULL, "1996",
	"Super Puzzle Fighter II X (Japan 960531, Phoenix Edition)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE | BDF_BOOTLEG,2,HARDWARE_CAPCOM_CPS2,
	NULL, Spf2xjdRomInfo, Spf2xjdRomName, spf2xInputInfo, NULL,
	PhoenixInit, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Super Street Fighter II: The New Challengers (World 930911)

static struct BurnRomInfo Ssf2RomDesc[] = {
	{ "ssfe.03",      0x080000, 0xa597745d, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "ssfe.04",      0x080000, 0xb082aa67, 1 | BRF_ESS | BRF_PRG },
	{ "ssfe.05",      0x080000, 0x02b9c137, 1 | BRF_ESS | BRF_PRG },
	{ "ssfe.06",      0x080000, 0x70d470c5, 1 | BRF_ESS | BRF_PRG },
	{ "ssfe.07",      0x080000, 0x2409001d, 1 | BRF_ESS | BRF_PRG },

	{ "ssf.13m",      0x200000, 0xcf94d275, 3 | BRF_GRA },
	{ "ssf.15m",      0x200000, 0x5eb703af, 3 | BRF_GRA },
	{ "ssf.17m",      0x200000, 0xffa60e0f, 3 | BRF_GRA },
	{ "ssf.19m",      0x200000, 0x34e825c5, 3 | BRF_GRA },
	{ "ssf.14m",      0x100000, 0xb7cc32e7, 3 | BRF_GRA },
	{ "ssf.16m",      0x100000, 0x8376ad18, 3 | BRF_GRA },
	{ "ssf.18m",      0x100000, 0xf5b1b336, 3 | BRF_GRA },
	{ "ssf.20m",      0x100000, 0x459d5c6b, 3 | BRF_GRA },

	{ "ssf.01",       0x020000, 0xeb247e8c, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "ssf.q01",      0x080000, 0xa6f9da5c, 5 | BRF_SND },
	{ "ssf.q02",      0x080000, 0x8c66ae26, 5 | BRF_SND },
	{ "ssf.q03",      0x080000, 0x695cc2ca, 5 | BRF_SND },
	{ "ssf.q04",      0x080000, 0x9d9ebe32, 5 | BRF_SND },
	{ "ssf.q05",      0x080000, 0x4770e7b7, 5 | BRF_SND },
	{ "ssf.q06",      0x080000, 0x4e79c951, 5 | BRF_SND },
	{ "ssf.q07",      0x080000, 0xcdd14313, 5 | BRF_SND },
	{ "ssf.q08",      0x080000, 0x6f5a088c, 5 | BRF_SND },
};

STD_ROM_PICK(Ssf2) STD_ROM_FN(Ssf2)

static int Ssf2Init()
{
	Ssf2 = 1;
	return Cps2Init();
}

static int Ssf2Exit()
{
	Ssf2 = 0;
	return CpsExit();
}

static int Ssf2PhoenixInit()
{
	Ssf2 = 1;
	return PhoenixInit();
}

struct BurnDriver BurnDrvCpsSsf2 = {
	"ssf2", NULL, NULL, "1993",
	"Super Street Fighter II: The New Challengers (World 930911)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING,2,HARDWARE_CAPCOM_CPS2,
	NULL, Ssf2RomInfo, Ssf2RomName, DrvInputInfo, NULL,
	Ssf2Init, Ssf2Exit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Super Street Fighter II: The New Challengers (USA 930911)

static struct BurnRomInfo Ssf2uRomDesc[] = {
	{ "ssfu.03a",     0x080000, 0x72f29c33, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "ssfu.04a",     0x080000, 0x935cea44, 1 | BRF_ESS | BRF_PRG },
	{ "ssfu.05",      0x080000, 0xa0acb28a, 1 | BRF_ESS | BRF_PRG },
	{ "ssfu.06",      0x080000, 0x47413dcf, 1 | BRF_ESS | BRF_PRG },
	{ "ssfu.07",      0x080000, 0xe6066077, 1 | BRF_ESS | BRF_PRG },

	{ "ssf.13m",      0x200000, 0xcf94d275, 3 | BRF_GRA },
	{ "ssf.15m",      0x200000, 0x5eb703af, 3 | BRF_GRA },
	{ "ssf.17m",      0x200000, 0xffa60e0f, 3 | BRF_GRA },
	{ "ssf.19m",      0x200000, 0x34e825c5, 3 | BRF_GRA },
	{ "ssf.14m",      0x100000, 0xb7cc32e7, 3 | BRF_GRA },
	{ "ssf.16m",      0x100000, 0x8376ad18, 3 | BRF_GRA },
	{ "ssf.18m",      0x100000, 0xf5b1b336, 3 | BRF_GRA },
	{ "ssf.20m",      0x100000, 0x459d5c6b, 3 | BRF_GRA },

	{ "ssf.01",       0x020000, 0xeb247e8c, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "ssf.q01",      0x080000, 0xa6f9da5c, 5 | BRF_SND },
	{ "ssf.q02",      0x080000, 0x8c66ae26, 5 | BRF_SND },
	{ "ssf.q03",      0x080000, 0x695cc2ca, 5 | BRF_SND },
	{ "ssf.q04",      0x080000, 0x9d9ebe32, 5 | BRF_SND },
	{ "ssf.q05",      0x080000, 0x4770e7b7, 5 | BRF_SND },
	{ "ssf.q06",      0x080000, 0x4e79c951, 5 | BRF_SND },
	{ "ssf.q07",      0x080000, 0xcdd14313, 5 | BRF_SND },
	{ "ssf.q08",      0x080000, 0x6f5a088c, 5 | BRF_SND },
};

STD_ROM_PICK(Ssf2u) STD_ROM_FN(Ssf2u)

struct BurnDriver BurnDrvCpsSsf2u = {
	"ssf2u", "ssf2", NULL, "1993",
	"Super Street Fighter II: The New Challengers (USA 930911)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Ssf2uRomInfo, Ssf2uRomName, DrvInputInfo, NULL,
	Ssf2Init, Ssf2Exit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Super Street Fighter II: The New Challengers (USA 930911, Phoenix Edition)

static struct BurnRomInfo Ssf2udRomDesc[] = {
	{ "ssfud.03a",    0x080000, 0xFAD5DAF8, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "ssfud.04a",    0x080000, 0x0D31AF65, 1 | BRF_ESS | BRF_PRG },
	{ "ssfud.05",     0x080000, 0x75C651EF, 1 | BRF_ESS | BRF_PRG },
	{ "ssfud.06",     0x080000, 0x85C3EC00, 1 | BRF_ESS | BRF_PRG },
	{ "ssfud.07",     0x080000, 0x247E2504, 1 | BRF_ESS | BRF_PRG },

	{ "ssf.13m",      0x200000, 0xcf94d275, 3 | BRF_GRA },
	{ "ssf.15m",      0x200000, 0x5eb703af, 3 | BRF_GRA },
	{ "ssf.17m",      0x200000, 0xffa60e0f, 3 | BRF_GRA },
	{ "ssf.19m",      0x200000, 0x34e825c5, 3 | BRF_GRA },
	{ "ssf.14m",      0x100000, 0xb7cc32e7, 3 | BRF_GRA },
	{ "ssf.16m",      0x100000, 0x8376ad18, 3 | BRF_GRA },
	{ "ssf.18m",      0x100000, 0xf5b1b336, 3 | BRF_GRA },
	{ "ssf.20m",      0x100000, 0x459d5c6b, 3 | BRF_GRA },

	{ "ssf.01",       0x020000, 0xeb247e8c, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "ssf.q01",      0x080000, 0xa6f9da5c, 5 | BRF_SND },
	{ "ssf.q02",      0x080000, 0x8c66ae26, 5 | BRF_SND },
	{ "ssf.q03",      0x080000, 0x695cc2ca, 5 | BRF_SND },
	{ "ssf.q04",      0x080000, 0x9d9ebe32, 5 | BRF_SND },
	{ "ssf.q05",      0x080000, 0x4770e7b7, 5 | BRF_SND },
	{ "ssf.q06",      0x080000, 0x4e79c951, 5 | BRF_SND },
	{ "ssf.q07",      0x080000, 0xcdd14313, 5 | BRF_SND },
	{ "ssf.q08",      0x080000, 0x6f5a088c, 5 | BRF_SND },
};

STD_ROM_PICK(Ssf2ud) STD_ROM_FN(Ssf2ud)

struct BurnDriver BurnDrvCpsSsf2ud = {
	"ssf2ud", "ssf2", NULL, "1993",
	"Super Street Fighter II: The New Challengers (USA 930911, Phoenix Edition)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE | BDF_BOOTLEG, 2, HARDWARE_CAPCOM_CPS2,
	NULL, Ssf2udRomInfo, Ssf2udRomName, DrvInputInfo, NULL,
	Ssf2PhoenixInit, Ssf2Exit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Super Street Fighter II: The New Challengers (Asia 931005)

static struct BurnRomInfo Ssf2aRomDesc[] = {
	{ "ssfa.03b",     0x080000, 0x83a059bf, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "ssfa.04a",     0x080000, 0x5d873642, 1 | BRF_ESS | BRF_PRG },
	{ "ssfa.05",      0x080000, 0xf8fb4de2, 1 | BRF_ESS | BRF_PRG },
	{ "ssfa.06b",     0x080000, 0x3185d19d, 1 | BRF_ESS | BRF_PRG },
	{ "ssfa.07",      0x080000, 0x36e29217, 1 | BRF_ESS | BRF_PRG },

	{ "ssf.13m",      0x200000, 0xcf94d275, 3 | BRF_GRA },
	{ "ssf.15m",      0x200000, 0x5eb703af, 3 | BRF_GRA },
	{ "ssf.17m",      0x200000, 0xffa60e0f, 3 | BRF_GRA },
	{ "ssf.19m",      0x200000, 0x34e825c5, 3 | BRF_GRA },
	{ "ssf.14m",      0x100000, 0xb7cc32e7, 3 | BRF_GRA },
	{ "ssf.16m",      0x100000, 0x8376ad18, 3 | BRF_GRA },
	{ "ssf.18m",      0x100000, 0xf5b1b336, 3 | BRF_GRA },
	{ "ssf.20m",      0x100000, 0x459d5c6b, 3 | BRF_GRA },

	{ "ssf.01",       0x020000, 0xeb247e8c, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "ssf.q01",      0x080000, 0xa6f9da5c, 5 | BRF_SND },
	{ "ssf.q02",      0x080000, 0x8c66ae26, 5 | BRF_SND },
	{ "ssf.q03",      0x080000, 0x695cc2ca, 5 | BRF_SND },
	{ "ssf.q04",      0x080000, 0x9d9ebe32, 5 | BRF_SND },
	{ "ssf.q05",      0x080000, 0x4770e7b7, 5 | BRF_SND },
	{ "ssf.q06",      0x080000, 0x4e79c951, 5 | BRF_SND },
	{ "ssf.q07",      0x080000, 0xcdd14313, 5 | BRF_SND },
	{ "ssf.q08",      0x080000, 0x6f5a088c, 5 | BRF_SND },
};

STD_ROM_PICK(Ssf2a) STD_ROM_FN(Ssf2a)

struct BurnDriver BurnDrvCpsSsf2a = {
	"ssf2a", "ssf2", NULL, "1993",
	"Super Street Fighter II: The New Challengers (Asia 931005)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Ssf2aRomInfo, Ssf2aRomName, DrvInputInfo, NULL,
	Ssf2Init, Ssf2Exit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Super Street Fighter II: The New Challengers (Asia 930914)

static struct BurnRomInfo Ssf2ar1RomDesc[] = {
	{ "ssfa.03a",     0x080000, 0xd2a3c520, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "ssfa.04a",     0x080000, 0x5d873642, 1 | BRF_ESS | BRF_PRG },
	{ "ssfa.05",      0x080000, 0xf8fb4de2, 1 | BRF_ESS | BRF_PRG },
	{ "ssfa.06",      0x080000, 0xaa8acee7, 1 | BRF_ESS | BRF_PRG },
	{ "ssfa.07",      0x080000, 0x36e29217, 1 | BRF_ESS | BRF_PRG },

	{ "ssf.13m",      0x200000, 0xcf94d275, 3 | BRF_GRA },
	{ "ssf.15m",      0x200000, 0x5eb703af, 3 | BRF_GRA },
	{ "ssf.17m",      0x200000, 0xffa60e0f, 3 | BRF_GRA },
	{ "ssf.19m",      0x200000, 0x34e825c5, 3 | BRF_GRA },
	{ "ssf.14m",      0x100000, 0xb7cc32e7, 3 | BRF_GRA },
	{ "ssf.16m",      0x100000, 0x8376ad18, 3 | BRF_GRA },
	{ "ssf.18m",      0x100000, 0xf5b1b336, 3 | BRF_GRA },
	{ "ssf.20m",      0x100000, 0x459d5c6b, 3 | BRF_GRA },

	{ "ssf.01",       0x020000, 0xeb247e8c, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "ssf.q01",      0x080000, 0xa6f9da5c, 5 | BRF_SND },
	{ "ssf.q02",      0x080000, 0x8c66ae26, 5 | BRF_SND },
	{ "ssf.q03",      0x080000, 0x695cc2ca, 5 | BRF_SND },
	{ "ssf.q04",      0x080000, 0x9d9ebe32, 5 | BRF_SND },
	{ "ssf.q05",      0x080000, 0x4770e7b7, 5 | BRF_SND },
	{ "ssf.q06",      0x080000, 0x4e79c951, 5 | BRF_SND },
	{ "ssf.q07",      0x080000, 0xcdd14313, 5 | BRF_SND },
	{ "ssf.q08",      0x080000, 0x6f5a088c, 5 | BRF_SND },
};

STD_ROM_PICK(Ssf2ar1) STD_ROM_FN(Ssf2ar1)

struct BurnDriver BurnDrvCpsSsf2ar1 = {
	"ssf2ar1", "ssf2", NULL, "1993",
	"Super Street Fighter II: The New Challengers (Asia 930914)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Ssf2ar1RomInfo, Ssf2ar1RomName, DrvInputInfo, NULL,
	Ssf2Init, Ssf2Exit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Super Street Fighter II: The New Challengers (Japan 931005)

static struct BurnRomInfo Ssf2jRomDesc[] = {
	{ "ssfj.03b",     0x080000, 0x5c2e356d, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "ssfj.04a",     0x080000, 0x013bd55c, 1 | BRF_ESS | BRF_PRG },
	{ "ssfj.05",      0x080000, 0x0918d19a, 1 | BRF_ESS | BRF_PRG },
	{ "ssfj.06b",     0x080000, 0x014e0c6d, 1 | BRF_ESS | BRF_PRG },
	{ "ssfj.07",      0x080000, 0xeb6a9b1b, 1 | BRF_ESS | BRF_PRG },

	{ "ssf.13m",      0x200000, 0xcf94d275, 3 | BRF_GRA },
	{ "ssf.15m",      0x200000, 0x5eb703af, 3 | BRF_GRA },
	{ "ssf.17m",      0x200000, 0xffa60e0f, 3 | BRF_GRA },
	{ "ssf.19m",      0x200000, 0x34e825c5, 3 | BRF_GRA },
	{ "ssf.14m",      0x100000, 0xb7cc32e7, 3 | BRF_GRA },
	{ "ssf.16m",      0x100000, 0x8376ad18, 3 | BRF_GRA },
	{ "ssf.18m",      0x100000, 0xf5b1b336, 3 | BRF_GRA },
	{ "ssf.20m",      0x100000, 0x459d5c6b, 3 | BRF_GRA },

	{ "ssf.01",       0x020000, 0xeb247e8c, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "ssf.q01",      0x080000, 0xa6f9da5c, 5 | BRF_SND },
	{ "ssf.q02",      0x080000, 0x8c66ae26, 5 | BRF_SND },
	{ "ssf.q03",      0x080000, 0x695cc2ca, 5 | BRF_SND },
	{ "ssf.q04",      0x080000, 0x9d9ebe32, 5 | BRF_SND },
	{ "ssf.q05",      0x080000, 0x4770e7b7, 5 | BRF_SND },
	{ "ssf.q06",      0x080000, 0x4e79c951, 5 | BRF_SND },
	{ "ssf.q07",      0x080000, 0xcdd14313, 5 | BRF_SND },
	{ "ssf.q08",      0x080000, 0x6f5a088c, 5 | BRF_SND },
};

STD_ROM_PICK(Ssf2j) STD_ROM_FN(Ssf2j)

struct BurnDriver BurnDrvCpsSsf2j = {
	"ssf2j", "ssf2", NULL, "1993",
	"Super Street Fighter II: The New Challengers (Japan 931005)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Ssf2jRomInfo, Ssf2jRomName, DrvInputInfo, NULL,
	Ssf2Init, Ssf2Exit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Super Street Fighter II: The New Challengers (Japan 930911)

static struct BurnRomInfo Ssf2jr1RomDesc[] = {
	{ "ssfj.03a",     0x080000, 0x0bbf1304, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "ssfj.04a",     0x080000, 0x013bd55c, 1 | BRF_ESS | BRF_PRG },
	{ "ssfj.05",      0x080000, 0x0918d19a, 1 | BRF_ESS | BRF_PRG },
	{ "ssfj.06",      0x080000, 0xd808a6cd, 1 | BRF_ESS | BRF_PRG },
	{ "ssfj.07",      0x080000, 0xeb6a9b1b, 1 | BRF_ESS | BRF_PRG },

	{ "ssf.13m",      0x200000, 0xcf94d275, 3 | BRF_GRA },
	{ "ssf.15m",      0x200000, 0x5eb703af, 3 | BRF_GRA },
	{ "ssf.17m",      0x200000, 0xffa60e0f, 3 | BRF_GRA },
	{ "ssf.19m",      0x200000, 0x34e825c5, 3 | BRF_GRA },
	{ "ssf.14m",      0x100000, 0xb7cc32e7, 3 | BRF_GRA },
	{ "ssf.16m",      0x100000, 0x8376ad18, 3 | BRF_GRA },
	{ "ssf.18m",      0x100000, 0xf5b1b336, 3 | BRF_GRA },
	{ "ssf.20m",      0x100000, 0x459d5c6b, 3 | BRF_GRA },

	{ "ssf.01",       0x020000, 0xeb247e8c, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "ssf.q01",      0x080000, 0xa6f9da5c, 5 | BRF_SND },
	{ "ssf.q02",      0x080000, 0x8c66ae26, 5 | BRF_SND },
	{ "ssf.q03",      0x080000, 0x695cc2ca, 5 | BRF_SND },
	{ "ssf.q04",      0x080000, 0x9d9ebe32, 5 | BRF_SND },
	{ "ssf.q05",      0x080000, 0x4770e7b7, 5 | BRF_SND },
	{ "ssf.q06",      0x080000, 0x4e79c951, 5 | BRF_SND },
	{ "ssf.q07",      0x080000, 0xcdd14313, 5 | BRF_SND },
	{ "ssf.q08",      0x080000, 0x6f5a088c, 5 | BRF_SND },
};

STD_ROM_PICK(Ssf2jr1) STD_ROM_FN(Ssf2jr1)

struct BurnDriver BurnDrvCpsSsf2jr1 = {
	"ssf2jr1", "ssf2", NULL, "1993",
	"Super Street Fighter II: The New Challengers (Japan 930911)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Ssf2jr1RomInfo, Ssf2jr1RomName, DrvInputInfo, NULL,
	Ssf2Init, Ssf2Exit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Super Street Fighter II: The New Challengers (Japan 930910)

static struct BurnRomInfo Ssf2jr2RomDesc[] = {
	{ "ssfj.03",      0x080000, 0x7eb0efed, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "ssfj.04",      0x080000, 0xd7322164, 1 | BRF_ESS | BRF_PRG },
	{ "ssfj.05",      0x080000, 0x0918d19a, 1 | BRF_ESS | BRF_PRG },
	{ "ssfj.06",      0x080000, 0xd808a6cd, 1 | BRF_ESS | BRF_PRG },
	{ "ssfj.07",      0x080000, 0xeb6a9b1b, 1 | BRF_ESS | BRF_PRG },

	{ "ssf.13m",      0x200000, 0xcf94d275, 3 | BRF_GRA },
	{ "ssf.15m",      0x200000, 0x5eb703af, 3 | BRF_GRA },
	{ "ssf.17m",      0x200000, 0xffa60e0f, 3 | BRF_GRA },
	{ "ssf.19m",      0x200000, 0x34e825c5, 3 | BRF_GRA },
	{ "ssf.14m",      0x100000, 0xb7cc32e7, 3 | BRF_GRA },
	{ "ssf.16m",      0x100000, 0x8376ad18, 3 | BRF_GRA },
	{ "ssf.18m",      0x100000, 0xf5b1b336, 3 | BRF_GRA },
	{ "ssf.20m",      0x100000, 0x459d5c6b, 3 | BRF_GRA },

	{ "ssf.01",       0x020000, 0xeb247e8c, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "ssf.q01",      0x080000, 0xa6f9da5c, 5 | BRF_SND },
	{ "ssf.q02",      0x080000, 0x8c66ae26, 5 | BRF_SND },
	{ "ssf.q03",      0x080000, 0x695cc2ca, 5 | BRF_SND },
	{ "ssf.q04",      0x080000, 0x9d9ebe32, 5 | BRF_SND },
	{ "ssf.q05",      0x080000, 0x4770e7b7, 5 | BRF_SND },
	{ "ssf.q06",      0x080000, 0x4e79c951, 5 | BRF_SND },
	{ "ssf.q07",      0x080000, 0xcdd14313, 5 | BRF_SND },
	{ "ssf.q08",      0x080000, 0x6f5a088c, 5 | BRF_SND },
};

STD_ROM_PICK(Ssf2jr2) STD_ROM_FN(Ssf2jr2)

struct BurnDriver BurnDrvCpsSsf2jr2 = {
	"ssf2jr2", "ssf2", NULL, "1993",
	"Super Street Fighter II: The New Challengers (Japan 930910)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Ssf2jr2RomInfo, Ssf2jr2RomName, DrvInputInfo, NULL,
	Ssf2Init, Ssf2Exit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Super Street Fighter II: The New Challengers (Hispanic 930911)

static struct BurnRomInfo Ssf2hRomDesc[] = {
	{ "ssfh.03",      0x080000, 0xb086b355, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "ssfh.04",      0x080000, 0x1e629b29, 1 | BRF_ESS | BRF_PRG },
	{ "ssfh.05",      0x080000, 0xb5997e10, 1 | BRF_ESS | BRF_PRG },
	{ "ssfh.06",      0x080000, 0x793b8fad, 1 | BRF_ESS | BRF_PRG },
	{ "ssfh.07",      0x080000, 0xcbb92ac3, 1 | BRF_ESS | BRF_PRG },

	{ "ssf.13m",      0x200000, 0xcf94d275, 3 | BRF_GRA },
	{ "ssf.15m",      0x200000, 0x5eb703af, 3 | BRF_GRA },
	{ "ssf.17m",      0x200000, 0xffa60e0f, 3 | BRF_GRA },
	{ "ssf.19m",      0x200000, 0x34e825c5, 3 | BRF_GRA },
	{ "ssf.14m",      0x100000, 0xb7cc32e7, 3 | BRF_GRA },
	{ "ssf.16m",      0x100000, 0x8376ad18, 3 | BRF_GRA },
	{ "ssf.18m",      0x100000, 0xf5b1b336, 3 | BRF_GRA },
	{ "ssf.20m",      0x100000, 0x459d5c6b, 3 | BRF_GRA },

	{ "ssf.01",       0x020000, 0xeb247e8c, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "ssf.q01",      0x080000, 0xa6f9da5c, 5 | BRF_SND },
	{ "ssf.q02",      0x080000, 0x8c66ae26, 5 | BRF_SND },
	{ "ssf.q03",      0x080000, 0x695cc2ca, 5 | BRF_SND },
	{ "ssf.q04",      0x080000, 0x9d9ebe32, 5 | BRF_SND },
	{ "ssf.q05",      0x080000, 0x4770e7b7, 5 | BRF_SND },
	{ "ssf.q06",      0x080000, 0x4e79c951, 5 | BRF_SND },
	{ "ssf.q07",      0x080000, 0xcdd14313, 5 | BRF_SND },
	{ "ssf.q08",      0x080000, 0x6f5a088c, 5 | BRF_SND },
};

STD_ROM_PICK(Ssf2h) STD_ROM_FN(Ssf2h)

struct BurnDriver BurnDrvCpsSsf2h = {
	"ssf2h", "ssf2", NULL, "1993",
	"Super Street Fighter II: The New Challengers (Hispanic 930911)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Ssf2hRomInfo, Ssf2hRomName, DrvInputInfo, NULL,
	Ssf2Init, Ssf2Exit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Super Street Fighter II: The Tournament Battle (World 931119)

static struct BurnRomInfo Ssf2tbRomDesc[] = {
	{ "ssfe.3tc",     0x080000, 0x496a8409, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "ssfe.4tc",     0x080000, 0x4b45c18b, 1 | BRF_ESS | BRF_PRG },
	{ "ssfe.5t",      0x080000, 0x6a9c6444, 1 | BRF_ESS | BRF_PRG },
	{ "ssfe.6tb",     0x080000, 0xe4944fc3, 1 | BRF_ESS | BRF_PRG },
	{ "ssfe.7t",      0x080000, 0x2c9f4782, 1 | BRF_ESS | BRF_PRG },

	{ "ssf.13m",      0x200000, 0xcf94d275, 3 | BRF_GRA },
	{ "ssf.15m",      0x200000, 0x5eb703af, 3 | BRF_GRA },
	{ "ssf.17m",      0x200000, 0xffa60e0f, 3 | BRF_GRA },
	{ "ssf.19m",      0x200000, 0x34e825c5, 3 | BRF_GRA },
	{ "ssf.14m",      0x100000, 0xb7cc32e7, 3 | BRF_GRA },
	{ "ssf.16m",      0x100000, 0x8376ad18, 3 | BRF_GRA },
	{ "ssf.18m",      0x100000, 0xf5b1b336, 3 | BRF_GRA },
	{ "ssf.20m",      0x100000, 0x459d5c6b, 3 | BRF_GRA },

	{ "ssf.01",       0x020000, 0xeb247e8c, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "ssf.q01",      0x080000, 0xa6f9da5c, 5 | BRF_SND },
	{ "ssf.q02",      0x080000, 0x8c66ae26, 5 | BRF_SND },
	{ "ssf.q03",      0x080000, 0x695cc2ca, 5 | BRF_SND },
	{ "ssf.q04",      0x080000, 0x9d9ebe32, 5 | BRF_SND },
	{ "ssf.q05",      0x080000, 0x4770e7b7, 5 | BRF_SND },
	{ "ssf.q06",      0x080000, 0x4e79c951, 5 | BRF_SND },
	{ "ssf.q07",      0x080000, 0xcdd14313, 5 | BRF_SND },
	{ "ssf.q08",      0x080000, 0x6f5a088c, 5 | BRF_SND },
};

STD_ROM_PICK(Ssf2tb) STD_ROM_FN(Ssf2tb)

static int Ssf2tbInit()
{
	Ssf2tb = 1;

	return Ssf2Init();
}

static int Ssf2tbExit()
{
	Ssf2tb = 0;

	return Ssf2Exit();
}

static int Ssf2tbPhoenixInit()
{
	Ssf2tb = 1;

	return Ssf2PhoenixInit();
}

struct BurnDriver BurnDrvCpsSsf2tb = {
	"ssf2tb", "ssf2", NULL, "1993",
	"Super Street Fighter II: The Tournament Battle (World 931119)\0", "Linkup feature not implemented", "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Ssf2tbRomInfo, Ssf2tbRomName, DrvInputInfo, NULL,
	Ssf2tbInit, Ssf2tbExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Super Street Fighter II: The Tournament Battle (World 931119, Phoenix Edition)

static struct BurnRomInfo Ssf2tbdRomDesc[] = {
	{ "ssfed.3tc",    0x080000, 0x5d86caf8, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "ssfed.4tc",    0x080000, 0xf6e1f98d, 1 | BRF_ESS | BRF_PRG },
	{ "ssfed.5t",     0x080000, 0x75c651ef, 1 | BRF_ESS | BRF_PRG },
	{ "ssfed.6tb",    0x080000, 0x9adac7d7, 1 | BRF_ESS | BRF_PRG },
	{ "ssfed.7t",     0x080000, 0x84f54db3, 1 | BRF_ESS | BRF_PRG },

	{ "ssf.13m",      0x200000, 0xcf94d275, 3 | BRF_GRA },
	{ "ssf.15m",      0x200000, 0x5eb703af, 3 | BRF_GRA },
	{ "ssf.17m",      0x200000, 0xffa60e0f, 3 | BRF_GRA },
	{ "ssf.19m",      0x200000, 0x34e825c5, 3 | BRF_GRA },
	{ "ssf.14m",      0x100000, 0xb7cc32e7, 3 | BRF_GRA },
	{ "ssf.16m",      0x100000, 0x8376ad18, 3 | BRF_GRA },
	{ "ssf.18m",      0x100000, 0xf5b1b336, 3 | BRF_GRA },
	{ "ssf.20m",      0x100000, 0x459d5c6b, 3 | BRF_GRA },

	{ "ssf.01",       0x020000, 0xeb247e8c, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "ssf.q01",      0x080000, 0xa6f9da5c, 5 | BRF_SND },
	{ "ssf.q02",      0x080000, 0x8c66ae26, 5 | BRF_SND },
	{ "ssf.q03",      0x080000, 0x695cc2ca, 5 | BRF_SND },
	{ "ssf.q04",      0x080000, 0x9d9ebe32, 5 | BRF_SND },
	{ "ssf.q05",      0x080000, 0x4770e7b7, 5 | BRF_SND },
	{ "ssf.q06",      0x080000, 0x4e79c951, 5 | BRF_SND },
	{ "ssf.q07",      0x080000, 0xcdd14313, 5 | BRF_SND },
	{ "ssf.q08",      0x080000, 0x6f5a088c, 5 | BRF_SND },
};

STD_ROM_PICK(Ssf2tbd) STD_ROM_FN(Ssf2tbd)

struct BurnDriver BurnDrvCpsSsf2tbd = {
	"ssf2tbd", "ssf2", NULL, "1993",
	"Super Street Fighter II: The Tournament Battle (World 931119, Phoenix Edition)\0", "Linkup feature not implemented", "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE | BDF_BOOTLEG,2,HARDWARE_CAPCOM_CPS2,
	NULL, Ssf2tbdRomInfo, Ssf2tbdRomName, DrvInputInfo, NULL,
	Ssf2tbPhoenixInit, Ssf2tbExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Super Street Fighter II: The Tournament Battle (World 930911)

static struct BurnRomInfo ssf2tbr1RomDesc[] = {
	{ "ssfe.3t",      0x080000, 0x1e018e34, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "ssfe.4t",      0x080000, 0xac92efaf, 1 | BRF_ESS | BRF_PRG },
	{ "ssfe.5t",      0x080000, 0x6a9c6444, 1 | BRF_ESS | BRF_PRG },
	{ "ssfe.6t",      0x080000, 0xf442562b, 1 | BRF_ESS | BRF_PRG },
	{ "ssfe.7t",      0x080000, 0x2c9f4782, 1 | BRF_ESS | BRF_PRG },

	{ "ssf.13m",      0x200000, 0xcf94d275, 3 | BRF_GRA },
	{ "ssf.15m",      0x200000, 0x5eb703af, 3 | BRF_GRA },
	{ "ssf.17m",      0x200000, 0xffa60e0f, 3 | BRF_GRA },
	{ "ssf.19m",      0x200000, 0x34e825c5, 3 | BRF_GRA },
	{ "ssf.14m",      0x100000, 0xb7cc32e7, 3 | BRF_GRA },
	{ "ssf.16m",      0x100000, 0x8376ad18, 3 | BRF_GRA },
	{ "ssf.18m",      0x100000, 0xf5b1b336, 3 | BRF_GRA },
	{ "ssf.20m",      0x100000, 0x459d5c6b, 3 | BRF_GRA },

	{ "ssf.01",       0x020000, 0xeb247e8c, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "ssf.q01",      0x080000, 0xa6f9da5c, 5 | BRF_SND },
	{ "ssf.q02",      0x080000, 0x8c66ae26, 5 | BRF_SND },
	{ "ssf.q03",      0x080000, 0x695cc2ca, 5 | BRF_SND },
	{ "ssf.q04",      0x080000, 0x9d9ebe32, 5 | BRF_SND },
	{ "ssf.q05",      0x080000, 0x4770e7b7, 5 | BRF_SND },
	{ "ssf.q06",      0x080000, 0x4e79c951, 5 | BRF_SND },
	{ "ssf.q07",      0x080000, 0xcdd14313, 5 | BRF_SND },
	{ "ssf.q08",      0x080000, 0x6f5a088c, 5 | BRF_SND },
};

STD_ROM_PICK(ssf2tbr1) STD_ROM_FN(ssf2tbr1)

struct BurnDriver BurnDrvCpsssf2tbr1 = {
	"ssf2tbr1", "ssf2", NULL, "1993",
	"Super Street Fighter II: The Tournament Battle (World 930911)\0", "Linkup feature not implemented", "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, ssf2tbr1RomInfo, ssf2tbr1RomName, DrvInputInfo, NULL,
	Ssf2tbInit, Ssf2tbExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Super Street Fighter II: The Tournament Battle (Japan 930911)

static struct BurnRomInfo Ssf2tbjRomDesc[] = {
	{ "ssfj.3t",      0x080000, 0x980d4450, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "ssfj.4t",      0x080000, 0xb4dc1906, 1 | BRF_ESS | BRF_PRG },
	{ "ssfj.5t",      0x080000, 0xa7e35fbc, 1 | BRF_ESS | BRF_PRG },
	{ "ssfj.6t",      0x080000, 0xcb592b30, 1 | BRF_ESS | BRF_PRG },
	{ "ssfj.7t",      0x080000, 0x1f239515, 1 | BRF_ESS | BRF_PRG },

	{ "ssf.13m",      0x200000, 0xcf94d275, 3 | BRF_GRA },
	{ "ssf.15m",      0x200000, 0x5eb703af, 3 | BRF_GRA },
	{ "ssf.17m",      0x200000, 0xffa60e0f, 3 | BRF_GRA },
	{ "ssf.19m",      0x200000, 0x34e825c5, 3 | BRF_GRA },
	{ "ssf.14m",      0x100000, 0xb7cc32e7, 3 | BRF_GRA },
	{ "ssf.16m",      0x100000, 0x8376ad18, 3 | BRF_GRA },
	{ "ssf.18m",      0x100000, 0xf5b1b336, 3 | BRF_GRA },
	{ "ssf.20m",      0x100000, 0x459d5c6b, 3 | BRF_GRA },

	{ "ssf.01",       0x020000, 0xeb247e8c, 4 | BRF_ESS | BRF_PRG },	// z80 program

	{ "ssf.q01",      0x080000, 0xa6f9da5c, 5 | BRF_SND },
	{ "ssf.q02",      0x080000, 0x8c66ae26, 5 | BRF_SND },
	{ "ssf.q03",      0x080000, 0x695cc2ca, 5 | BRF_SND },
	{ "ssf.q04",      0x080000, 0x9d9ebe32, 5 | BRF_SND },
	{ "ssf.q05",      0x080000, 0x4770e7b7, 5 | BRF_SND },
	{ "ssf.q06",      0x080000, 0x4e79c951, 5 | BRF_SND },
	{ "ssf.q07",      0x080000, 0xcdd14313, 5 | BRF_SND },
	{ "ssf.q08",      0x080000, 0x6f5a088c, 5 | BRF_SND },
};

STD_ROM_PICK(Ssf2tbj) STD_ROM_FN(Ssf2tbj)

struct BurnDriver BurnDrvCpsSsf2tbj = {
	"ssf2tbj", "ssf2", NULL, "1993",
	"Super Street Fighter II: The Tournament Battle (Japan 930911)\0", "Linkup feature not implemented", "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Ssf2tbjRomInfo, Ssf2tbjRomName, DrvInputInfo, NULL,
	Ssf2tbInit, Ssf2tbExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Super Street Fighter II Turbo (World 940223)

static struct BurnRomInfo Ssf2tRomDesc[] = {
	{ "sfxe.03c",     0x080000, 0x2fa1f396, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "sfxe.04a",     0x080000, 0xd0bc29c6, 1 | BRF_ESS | BRF_PRG },
	{ "sfxe.05",      0x080000, 0x65222964, 1 | BRF_ESS | BRF_PRG },
	{ "sfxe.06a",     0x080000, 0x8fe9f531, 1 | BRF_ESS | BRF_PRG },
	{ "sfxe.07",      0x080000, 0x8a7d0cb6, 1 | BRF_ESS | BRF_PRG },
	{ "sfxe.08",      0x080000, 0x74c24062, 1 | BRF_ESS | BRF_PRG },
	{ "sfx.09",       0x080000, 0x642fae3f, 1 | BRF_ESS | BRF_PRG },

	{ "ssf.13m",      0x200000, 0xcf94d275, 3 | BRF_GRA },
	{ "ssf.15m",      0x200000, 0x5eb703af, 3 | BRF_GRA },
	{ "ssf.17m",      0x200000, 0xffa60e0f, 3 | BRF_GRA },
	{ "ssf.19m",      0x200000, 0x34e825c5, 3 | BRF_GRA },
	{ "ssf.14m",      0x100000, 0xb7cc32e7, 3 | BRF_GRA },
	{ "ssf.16m",      0x100000, 0x8376ad18, 3 | BRF_GRA },
	{ "ssf.18m",      0x100000, 0xf5b1b336, 3 | BRF_GRA },
	{ "ssf.20m",      0x100000, 0x459d5c6b, 3 | BRF_GRA },
	{ "sfx.21m",      0x100000, 0xe32854af, 3 | BRF_GRA },
	{ "sfx.23m",      0x100000, 0x760f2927, 3 | BRF_GRA },
	{ "sfx.25m",      0x100000, 0x1ee90208, 3 | BRF_GRA },
	{ "sfx.27m",      0x100000, 0xf814400f, 3 | BRF_GRA },

	{ "sfx.01",       0x020000, 0xb47b8835, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sfx.02",       0x020000, 0x0022633f, 4 | BRF_ESS | BRF_PRG },

	{ "sfx.11m",      0x200000, 0x9bdbd476, 5 | BRF_SND },
	{ "sfx.12m",      0x200000, 0xa05e3aab, 5 | BRF_SND },
};

STD_ROM_PICK(Ssf2t) STD_ROM_FN(Ssf2t)

struct BurnDriver BurnDrvCpsSsf2t = {
	"ssf2t", "ssf2", NULL, "1994",
	"Super Street Fighter II Turbo (World 940223)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING,2,HARDWARE_CAPCOM_CPS2,
	NULL, Ssf2tRomInfo, Ssf2tRomName, DrvInputInfo, NULL,
	Ssf2tInit, Ssf2tExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Super Street Fighter II Turbo (USA 940323)

static struct BurnRomInfo Ssf2tuRomDesc[] = {
	{ "sfxu.03e",     0x080000, 0xd6ff689e, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "sfxu.04a",     0x080000, 0x532b5ffd, 1 | BRF_ESS | BRF_PRG },
	{ "sfxu.05",      0x080000, 0xffa3c6de, 1 | BRF_ESS | BRF_PRG },
	{ "sfxu.06b",     0x080000, 0x83f9382b, 1 | BRF_ESS | BRF_PRG },
	{ "sfxu.07a",     0x080000, 0x6ab673e8, 1 | BRF_ESS | BRF_PRG },
	{ "sfxu.08",      0x080000, 0xb3c71810, 1 | BRF_ESS | BRF_PRG },
	{ "sfx.09",       0x080000, 0x642fae3f, 1 | BRF_ESS | BRF_PRG },

	{ "ssf.13m",      0x200000, 0xcf94d275, 3 | BRF_GRA },
	{ "ssf.15m",      0x200000, 0x5eb703af, 3 | BRF_GRA },
	{ "ssf.17m",      0x200000, 0xffa60e0f, 3 | BRF_GRA },
	{ "ssf.19m",      0x200000, 0x34e825c5, 3 | BRF_GRA },
	{ "ssf.14m",      0x100000, 0xb7cc32e7, 3 | BRF_GRA },
	{ "ssf.16m",      0x100000, 0x8376ad18, 3 | BRF_GRA },
	{ "ssf.18m",      0x100000, 0xf5b1b336, 3 | BRF_GRA },
	{ "ssf.20m",      0x100000, 0x459d5c6b, 3 | BRF_GRA },
	{ "sfx.21m",      0x100000, 0xe32854af, 3 | BRF_GRA },
	{ "sfx.23m",      0x100000, 0x760f2927, 3 | BRF_GRA },
	{ "sfx.25m",      0x100000, 0x1ee90208, 3 | BRF_GRA },
	{ "sfx.27m",      0x100000, 0xf814400f, 3 | BRF_GRA },

	{ "sfx.01",       0x020000, 0xb47b8835, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sfx.02",       0x020000, 0x0022633f, 4 | BRF_ESS | BRF_PRG },

	{ "sfx.11m",      0x200000, 0x9bdbd476, 5 | BRF_SND },
	{ "sfx.12m",      0x200000, 0xa05e3aab, 5 | BRF_SND },
};

STD_ROM_PICK(Ssf2tu) STD_ROM_FN(Ssf2tu)

struct BurnDriver BurnDrvCpsSsf2tu = {
	"ssf2tu", "ssf2t", NULL, "1994",
	"Super Street Fighter II Turbo (USA 940323)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Ssf2tuRomInfo, Ssf2tuRomName, DrvInputInfo, NULL,
	Ssf2tInit, Ssf2tExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Super Street Fighter II Turbo (USA 940223)

static struct BurnRomInfo Ssf2tur1RomDesc[] = {
	{ "sfxu.03c",     0x080000, 0x86e4a335, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "sfxu.04a",     0x080000, 0x532b5ffd, 1 | BRF_ESS | BRF_PRG },
	{ "sfxu.05",      0x080000, 0xffa3c6de, 1 | BRF_ESS | BRF_PRG },
	{ "sfxu.06a",     0x080000, 0xe4c04c99, 1 | BRF_ESS | BRF_PRG },
	{ "sfxu.07",      0x080000, 0xd8199e41, 1 | BRF_ESS | BRF_PRG },
	{ "sfxu.08",      0x080000, 0xb3c71810, 1 | BRF_ESS | BRF_PRG },
	{ "sfx.09",       0x080000, 0x642fae3f, 1 | BRF_ESS | BRF_PRG },

	{ "ssf.13m",      0x200000, 0xcf94d275, 3 | BRF_GRA },
	{ "ssf.15m",      0x200000, 0x5eb703af, 3 | BRF_GRA },
	{ "ssf.17m",      0x200000, 0xffa60e0f, 3 | BRF_GRA },
	{ "ssf.19m",      0x200000, 0x34e825c5, 3 | BRF_GRA },
	{ "ssf.14m",      0x100000, 0xb7cc32e7, 3 | BRF_GRA },
	{ "ssf.16m",      0x100000, 0x8376ad18, 3 | BRF_GRA },
	{ "ssf.18m",      0x100000, 0xf5b1b336, 3 | BRF_GRA },
	{ "ssf.20m",      0x100000, 0x459d5c6b, 3 | BRF_GRA },
	{ "sfx.21m",      0x100000, 0xe32854af, 3 | BRF_GRA },
	{ "sfx.23m",      0x100000, 0x760f2927, 3 | BRF_GRA },
	{ "sfx.25m",      0x100000, 0x1ee90208, 3 | BRF_GRA },
	{ "sfx.27m",      0x100000, 0xf814400f, 3 | BRF_GRA },

	{ "sfx.01",       0x020000, 0xb47b8835, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sfx.02",       0x020000, 0x0022633f, 4 | BRF_ESS | BRF_PRG },

	{ "sfx.11m",      0x200000, 0x9bdbd476, 5 | BRF_SND },
	{ "sfx.12m",      0x200000, 0xa05e3aab, 5 | BRF_SND },
};

STD_ROM_PICK(Ssf2tur1) STD_ROM_FN(Ssf2tur1)

struct BurnDriver BurnDrvCpsSsf2tur1 = {
	"ssf2tur1", "ssf2t", NULL, "1994",
	"Super Street Fighter II Turbo (USA 940223)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Ssf2tur1RomInfo, Ssf2tur1RomName, DrvInputInfo, NULL,
	Ssf2tInit, Ssf2tExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Super Street Fighter II Turbo (Asia 940223)

static struct BurnRomInfo Ssf2taRomDesc[] = {
	{ "sfxa.03c",     0x080000, 0x04b9ff34, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "sfxa.04a",     0x080000, 0x16ea5f7a, 1 | BRF_ESS | BRF_PRG },
	{ "sfxa.05",      0x080000, 0x53d61f0c, 1 | BRF_ESS | BRF_PRG },
	{ "sfxa.06a",     0x080000, 0x066d09b5, 1 | BRF_ESS | BRF_PRG },
	{ "sfxa.07",      0x080000, 0xa428257b, 1 | BRF_ESS | BRF_PRG },
	{ "sfxa.08",      0x080000, 0x39be596c, 1 | BRF_ESS | BRF_PRG },
	{ "sfx.09",       0x080000, 0x642fae3f, 1 | BRF_ESS | BRF_PRG },

	{ "ssf.13m",      0x200000, 0xcf94d275, 3 | BRF_GRA },
	{ "ssf.15m",      0x200000, 0x5eb703af, 3 | BRF_GRA },
	{ "ssf.17m",      0x200000, 0xffa60e0f, 3 | BRF_GRA },
	{ "ssf.19m",      0x200000, 0x34e825c5, 3 | BRF_GRA },
	{ "ssf.14m",      0x100000, 0xb7cc32e7, 3 | BRF_GRA },
	{ "ssf.16m",      0x100000, 0x8376ad18, 3 | BRF_GRA },
	{ "ssf.18m",      0x100000, 0xf5b1b336, 3 | BRF_GRA },
	{ "ssf.20m",      0x100000, 0x459d5c6b, 3 | BRF_GRA },
	{ "sfx.21m",      0x100000, 0xe32854af, 3 | BRF_GRA },
	{ "sfx.23m",      0x100000, 0x760f2927, 3 | BRF_GRA },
	{ "sfx.25m",      0x100000, 0x1ee90208, 3 | BRF_GRA },
	{ "sfx.27m",      0x100000, 0xf814400f, 3 | BRF_GRA },

	{ "sfx.01",       0x020000, 0xb47b8835, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sfx.02",       0x020000, 0x0022633f, 4 | BRF_ESS | BRF_PRG },

	{ "sfx.11m",      0x200000, 0x9bdbd476, 5 | BRF_SND },
	{ "sfx.12m",      0x200000, 0xa05e3aab, 5 | BRF_SND },
};

STD_ROM_PICK(Ssf2ta) STD_ROM_FN(Ssf2ta)

struct BurnDriver BurnDrvCpsSsf2ta = {
	"ssf2ta", "ssf2t", NULL, "1994",
	"Super Street Fighter II Turbo (Asia 940223)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Ssf2taRomInfo, Ssf2taRomName, DrvInputInfo, NULL,
	Ssf2tInit, Ssf2tExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Super Street Fighter II X: Grand Master Challenge (Japan 940223)

static struct BurnRomInfo Ssf2xjRomDesc[] = {
	{ "sfxj.03c",     0x080000, 0xa7417b79, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "sfxj.04a",     0x080000, 0xaf7767b4, 1 | BRF_ESS | BRF_PRG },
	{ "sfxj.05",      0x080000, 0xf4ff18f5, 1 | BRF_ESS | BRF_PRG },
	{ "sfxj.06a",     0x080000, 0x260d0370, 1 | BRF_ESS | BRF_PRG },
	{ "sfxj.07",      0x080000, 0x1324d02a, 1 | BRF_ESS | BRF_PRG },
	{ "sfxj.08",      0x080000, 0x2de76f10, 1 | BRF_ESS | BRF_PRG },
	{ "sfx.09",       0x080000, 0x642fae3f, 1 | BRF_ESS | BRF_PRG },

	{ "ssf.13m",      0x200000, 0xcf94d275, 3 | BRF_GRA },
	{ "ssf.15m",      0x200000, 0x5eb703af, 3 | BRF_GRA },
	{ "ssf.17m",      0x200000, 0xffa60e0f, 3 | BRF_GRA },
	{ "ssf.19m",      0x200000, 0x34e825c5, 3 | BRF_GRA },
	{ "ssf.14m",      0x100000, 0xb7cc32e7, 3 | BRF_GRA },
	{ "ssf.16m",      0x100000, 0x8376ad18, 3 | BRF_GRA },
	{ "ssf.18m",      0x100000, 0xf5b1b336, 3 | BRF_GRA },
	{ "ssf.20m",      0x100000, 0x459d5c6b, 3 | BRF_GRA },
	{ "sfx.21m",      0x100000, 0xe32854af, 3 | BRF_GRA },
	{ "sfx.23m",      0x100000, 0x760f2927, 3 | BRF_GRA },
	{ "sfx.25m",      0x100000, 0x1ee90208, 3 | BRF_GRA },
	{ "sfx.27m",      0x100000, 0xf814400f, 3 | BRF_GRA },

	{ "sfx.01",       0x020000, 0xb47b8835, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sfx.02",       0x020000, 0x0022633f, 4 | BRF_ESS | BRF_PRG },

	{ "sfx.11m",      0x200000, 0x9bdbd476, 5 | BRF_SND },
	{ "sfx.12m",      0x200000, 0xa05e3aab, 5 | BRF_SND },
};

STD_ROM_PICK(Ssf2xj) STD_ROM_FN(Ssf2xj)

struct BurnDriver BurnDrvCpsSsf2xj = {
	"ssf2xj", "ssf2t", NULL, "1994",
	"Super Street Fighter II X: Grand Master Challenge (Japan 940223)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Ssf2xjRomInfo, Ssf2xjRomName, DrvInputInfo, NULL,
	Ssf2tInit, Ssf2tExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Super Street Fighter II X: Grand Master Challenge (Japan 940223, Phoenix Edition)

static struct BurnRomInfo Ssf2xjdRomDesc[] = {
	{ "sfxjd.03c",    0x080000, 0x316de996, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "sfxjd.04a",    0x080000, 0x9bf3bb2e, 1 | BRF_ESS | BRF_PRG },
	{ "sfxjd.05",     0x080000, 0xc63358d0, 1 | BRF_ESS | BRF_PRG },
	{ "sfxjd.06a",    0x080000, 0xccb29808, 1 | BRF_ESS | BRF_PRG },
	{ "sfxjd.07",     0x080000, 0x61f94982, 1 | BRF_ESS | BRF_PRG },
	{ "sfxjd.08",     0x080000, 0xd399c36c, 1 | BRF_ESS | BRF_PRG },
	{ "sfxd.09",      0x080000, 0x0b3a6196, 1 | BRF_ESS | BRF_PRG },

	{ "ssf.13m",      0x200000, 0xcf94d275, 3 | BRF_GRA },
	{ "ssf.15m",      0x200000, 0x5eb703af, 3 | BRF_GRA },
	{ "ssf.17m",      0x200000, 0xffa60e0f, 3 | BRF_GRA },
	{ "ssf.19m",      0x200000, 0x34e825c5, 3 | BRF_GRA },
	{ "ssf.14m",      0x100000, 0xb7cc32e7, 3 | BRF_GRA },
	{ "ssf.16m",      0x100000, 0x8376ad18, 3 | BRF_GRA },
	{ "ssf.18m",      0x100000, 0xf5b1b336, 3 | BRF_GRA },
	{ "ssf.20m",      0x100000, 0x459d5c6b, 3 | BRF_GRA },
	{ "sfx.21m",      0x100000, 0xe32854af, 3 | BRF_GRA },
	{ "sfx.23m",      0x100000, 0x760f2927, 3 | BRF_GRA },
	{ "sfx.25m",      0x100000, 0x1ee90208, 3 | BRF_GRA },
	{ "sfx.27m",      0x100000, 0xf814400f, 3 | BRF_GRA },

	{ "sfx.01",       0x020000, 0xb47b8835, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "sfx.02",       0x020000, 0x0022633f, 4 | BRF_ESS | BRF_PRG },

	{ "sfx.11m",      0x200000, 0x9bdbd476, 5 | BRF_SND },
	{ "sfx.12m",      0x200000, 0xa05e3aab, 5 | BRF_SND },
};

STD_ROM_PICK(Ssf2xjd) STD_ROM_FN(Ssf2xjd)

struct BurnDriver BurnDrvCpsSsf2xjd = {
	"ssf2xjd", "ssf2t", NULL, "1994",
	"Super Street Fighter II X: Grand Master Challenge (Japan 940223, Phoenix Edition)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE | BDF_BOOTLEG,2,HARDWARE_CAPCOM_CPS2,
	NULL, Ssf2xjdRomInfo, Ssf2xjdRomName, DrvInputInfo, NULL,
	Ssf2tPhoenixInit, Ssf2tExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Vampire Hunter 2: Darkstalkers Revenge (Japan 970929)

static struct BurnRomInfo Vhunt2RomDesc[] = {
	{ "vh2j.03a",     0x080000, 0x9ae8f186, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "vh2j.04a",     0x080000, 0xe2fabf53, 1 | BRF_ESS | BRF_PRG },
	{ "vh2j.05",      0x080000, 0xde34f624, 1 | BRF_ESS | BRF_PRG },
	{ "vh2j.06",      0x080000, 0x6a3b9897, 1 | BRF_ESS | BRF_PRG },
	{ "vh2j.07",      0x080000, 0xb021c029, 1 | BRF_ESS | BRF_PRG },
	{ "vh2j.08",      0x080000, 0xac873dff, 1 | BRF_ESS | BRF_PRG },
	{ "vh2j.09",      0x080000, 0xeaefce9c, 1 | BRF_ESS | BRF_PRG },
	{ "vh2j.10",      0x080000, 0x11730952, 1 | BRF_ESS | BRF_PRG },

	{ "vh2.13m",      0x400000, 0x3b02ddaa, 3 | BRF_GRA },
	{ "vh2.15m",      0x400000, 0x4e40de66, 3 | BRF_GRA },
	{ "vh2.17m",      0x400000, 0xb31d00c9, 3 | BRF_GRA },
	{ "vh2.19m",      0x400000, 0x149be3ab, 3 | BRF_GRA },
	{ "vh2.14m",      0x400000, 0xcd09bd63, 3 | BRF_GRA },
	{ "vh2.16m",      0x400000, 0xe0182c15, 3 | BRF_GRA },
	{ "vh2.18m",      0x400000, 0x778dc4f6, 3 | BRF_GRA },
	{ "vh2.20m",      0x400000, 0x605d9d1d, 3 | BRF_GRA },

	{ "vh2.01",       0x020000, 0x67b9f779, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "vh2.02",       0x020000, 0xaaf15fcb, 4 | BRF_ESS | BRF_PRG },

	{ "vh2.11m",      0x400000, 0x38922efd, 5 | BRF_SND },
	{ "vh2.12m",      0x400000, 0x6e2430af, 5 | BRF_SND },
};

STD_ROM_PICK(Vhunt2) STD_ROM_FN(Vhunt2)

struct BurnDriver BurnDrvCpsVhunt2 = {
	"vhunt2", NULL, NULL, "1997",
	"Vampire Hunter 2: Darkstalkers Revenge (Japan 970929)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING,2,HARDWARE_CAPCOM_CPS2,
	NULL, Vhunt2RomInfo, Vhunt2RomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Vampire Hunter 2: Darkstalkers Revenge (Japan 970913)

static struct BurnRomInfo Vhunt2r1RomDesc[] = {
	{ "vh2j.03",      0x080000, 0x1a5feb13, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "vh2j.04",      0x080000, 0x434611a5, 1 | BRF_ESS | BRF_PRG },
	{ "vh2j.05",      0x080000, 0xde34f624, 1 | BRF_ESS | BRF_PRG },
	{ "vh2j.06",      0x080000, 0x6a3b9897, 1 | BRF_ESS | BRF_PRG },
	{ "vh2j.07",      0x080000, 0xb021c029, 1 | BRF_ESS | BRF_PRG },
	{ "vh2j.08",      0x080000, 0xac873dff, 1 | BRF_ESS | BRF_PRG },
	{ "vh2j.09",      0x080000, 0xeaefce9c, 1 | BRF_ESS | BRF_PRG },
	{ "vh2j.10",      0x080000, 0x11730952, 1 | BRF_ESS | BRF_PRG },

	{ "vh2.13m",      0x400000, 0x3b02ddaa, 3 | BRF_GRA },
	{ "vh2.15m",      0x400000, 0x4e40de66, 3 | BRF_GRA },
	{ "vh2.17m",      0x400000, 0xb31d00c9, 3 | BRF_GRA },
	{ "vh2.19m",      0x400000, 0x149be3ab, 3 | BRF_GRA },
	{ "vh2.14m",      0x400000, 0xcd09bd63, 3 | BRF_GRA },
	{ "vh2.16m",      0x400000, 0xe0182c15, 3 | BRF_GRA },
	{ "vh2.18m",      0x400000, 0x778dc4f6, 3 | BRF_GRA },
	{ "vh2.20m",      0x400000, 0x605d9d1d, 3 | BRF_GRA },

	{ "vh2.01",       0x020000, 0x67b9f779, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "vh2.02",       0x020000, 0xaaf15fcb, 4 | BRF_ESS | BRF_PRG },

	{ "vh2.11m",      0x400000, 0x38922efd, 5 | BRF_SND },
	{ "vh2.12m",      0x400000, 0x6e2430af, 5 | BRF_SND },
};

STD_ROM_PICK(Vhunt2r1) STD_ROM_FN(Vhunt2r1)

struct BurnDriver BurnDrvCpsVhunt2r1 = {
	"vhunt2r1", "vhunt2", NULL, "1997",
	"Vampire Hunter 2: Darkstalkers Revenge (Japan 970913)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Vhunt2r1RomInfo, Vhunt2r1RomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Vampire Savior: The Lord of Vampire (Euro 970519)

static struct BurnRomInfo VsavRomDesc[] = {
	{ "vm3e.03d",     0x080000, 0xf5962a8c, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "vm3e.04d",     0x080000, 0x21b40ea2, 1 | BRF_ESS | BRF_PRG },
	{ "vm3.05a",      0x080000, 0x4118e00f, 1 | BRF_ESS | BRF_PRG },
	{ "vm3.06a",      0x080000, 0x2f4fd3a9, 1 | BRF_ESS | BRF_PRG },
	{ "vm3.07b",      0x080000, 0xcbda91b8, 1 | BRF_ESS | BRF_PRG },
	{ "vm3.08a",      0x080000, 0x6ca47259, 1 | BRF_ESS | BRF_PRG },
	{ "vm3.09b",      0x080000, 0xf4a339e3, 1 | BRF_ESS | BRF_PRG },
	{ "vm3.10b",      0x080000, 0xfffbb5b8, 1 | BRF_ESS | BRF_PRG },

	{ "vm3.13m",      0x400000, 0xfd8a11eb, 3 | BRF_GRA },
	{ "vm3.15m",      0x400000, 0xdd1e7d4e, 3 | BRF_GRA },
	{ "vm3.17m",      0x400000, 0x6b89445e, 3 | BRF_GRA },
	{ "vm3.19m",      0x400000, 0x3830fdc7, 3 | BRF_GRA },
	{ "vm3.14m",      0x400000, 0xc1a28e6c, 3 | BRF_GRA },
	{ "vm3.16m",      0x400000, 0x194a7304, 3 | BRF_GRA },
	{ "vm3.18m",      0x400000, 0xdf9a9f47, 3 | BRF_GRA },
	{ "vm3.20m",      0x400000, 0xc22fc3d9, 3 | BRF_GRA },

	{ "vm3.01",       0x020000, 0xf778769b, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "vm3.02",       0x020000, 0xcc09faa1, 4 | BRF_ESS | BRF_PRG },

	{ "vm3.11m",      0x400000, 0xe80e956e, 5 | BRF_SND },
	{ "vm3.12m",      0x400000, 0x9cd71557, 5 | BRF_SND },
};

STD_ROM_PICK(Vsav) STD_ROM_FN(Vsav)

struct BurnDriver BurnDrvCpsVsav = {
	"vsav", NULL, NULL, "1997",
	"Vampire Savior: The Lord of Vampire (Euro 970519)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING,2,HARDWARE_CAPCOM_CPS2,
	NULL, VsavRomInfo, VsavRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Vampire Savior: The Lord of Vampire (USA 970519)

static struct BurnRomInfo VsavuRomDesc[] = {
	{ "vm3u.03d",     0x080000, 0x1f295274, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "vm3u.04d",     0x080000, 0xc46adf81, 1 | BRF_ESS | BRF_PRG },
	{ "vm3.05a",      0x080000, 0x4118e00f, 1 | BRF_ESS | BRF_PRG },
	{ "vm3.06a",      0x080000, 0x2f4fd3a9, 1 | BRF_ESS | BRF_PRG },
	{ "vm3.07b",      0x080000, 0xcbda91b8, 1 | BRF_ESS | BRF_PRG },
	{ "vm3.08a",      0x080000, 0x6ca47259, 1 | BRF_ESS | BRF_PRG },
	{ "vm3.09b",      0x080000, 0xf4a339e3, 1 | BRF_ESS | BRF_PRG },
	{ "vm3.10b",      0x080000, 0xfffbb5b8, 1 | BRF_ESS | BRF_PRG },

	{ "vm3.13m",      0x400000, 0xfd8a11eb, 3 | BRF_GRA },
	{ "vm3.15m",      0x400000, 0xdd1e7d4e, 3 | BRF_GRA },
	{ "vm3.17m",      0x400000, 0x6b89445e, 3 | BRF_GRA },
	{ "vm3.19m",      0x400000, 0x3830fdc7, 3 | BRF_GRA },
	{ "vm3.14m",      0x400000, 0xc1a28e6c, 3 | BRF_GRA },
	{ "vm3.16m",      0x400000, 0x194a7304, 3 | BRF_GRA },
	{ "vm3.18m",      0x400000, 0xdf9a9f47, 3 | BRF_GRA },
	{ "vm3.20m",      0x400000, 0xc22fc3d9, 3 | BRF_GRA },

	{ "vm3.01",       0x020000, 0xf778769b, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "vm3.02",       0x020000, 0xcc09faa1, 4 | BRF_ESS | BRF_PRG },

	{ "vm3.11m",      0x400000, 0xe80e956e, 5 | BRF_SND },
	{ "vm3.12m",      0x400000, 0x9cd71557, 5 | BRF_SND },
};

STD_ROM_PICK(Vsavu) STD_ROM_FN(Vsavu)

struct BurnDriver BurnDrvCpsVsavu = {
	"vsavu", "vsav", NULL, "1997",
	"Vampire Savior: The Lord of Vampire (USA 970519)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, VsavuRomInfo, VsavuRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Vampire Savior: The Lord of Vampire (Japan 970519)

static struct BurnRomInfo VsavjRomDesc[] = {
	{ "vm3j.03d",     0x080000, 0x2a2e74a4, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "vm3j.04d",     0x080000, 0x1c2427bc, 1 | BRF_ESS | BRF_PRG },
	{ "vm3j.05a",     0x080000, 0x95ce88d5, 1 | BRF_ESS | BRF_PRG },
	{ "vm3j.06b",     0x080000, 0x2c4297e0, 1 | BRF_ESS | BRF_PRG },
	{ "vm3j.07b",     0x080000, 0xa38aaae7, 1 | BRF_ESS | BRF_PRG },
	{ "vm3j.08a",     0x080000, 0x5773e5c9, 1 | BRF_ESS | BRF_PRG },
	{ "vm3j.09b",     0x080000, 0xd064f8b9, 1 | BRF_ESS | BRF_PRG },
	{ "vm3j.10b",     0x080000, 0x434518e9, 1 | BRF_ESS | BRF_PRG },

	{ "vm3.13m",      0x400000, 0xfd8a11eb, 3 | BRF_GRA },
	{ "vm3.15m",      0x400000, 0xdd1e7d4e, 3 | BRF_GRA },
	{ "vm3.17m",      0x400000, 0x6b89445e, 3 | BRF_GRA },
	{ "vm3.19m",      0x400000, 0x3830fdc7, 3 | BRF_GRA },
	{ "vm3.14m",      0x400000, 0xc1a28e6c, 3 | BRF_GRA },
	{ "vm3.16m",      0x400000, 0x194a7304, 3 | BRF_GRA },
	{ "vm3.18m",      0x400000, 0xdf9a9f47, 3 | BRF_GRA },
	{ "vm3.20m",      0x400000, 0xc22fc3d9, 3 | BRF_GRA },

	{ "vm3.01",       0x020000, 0xf778769b, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "vm3.02",       0x020000, 0xcc09faa1, 4 | BRF_ESS | BRF_PRG },

	{ "vm3.11m",      0x400000, 0xe80e956e, 5 | BRF_SND },
	{ "vm3.12m",      0x400000, 0x9cd71557, 5 | BRF_SND },
};

STD_ROM_PICK(Vsavj) STD_ROM_FN(Vsavj)

struct BurnDriver BurnDrvCpsVsavj = {
	"vsavj", "vsav", NULL, "1997",
	"Vampire Savior: The Lord of Vampire (Japan 970519)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, VsavjRomInfo, VsavjRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Vampire Savior: The Lord of Vampire (Asia 970519)

static struct BurnRomInfo VsavaRomDesc[] = {
	{ "vm3a.03d",     0x080000, 0x44c1198f, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "vm3a.04d",     0x080000, 0x2218b781, 1 | BRF_ESS | BRF_PRG },
	{ "vm3.05a",      0x080000, 0x4118e00f, 1 | BRF_ESS | BRF_PRG },
	{ "vm3.06a",      0x080000, 0x2f4fd3a9, 1 | BRF_ESS | BRF_PRG },
	{ "vm3.07b",      0x080000, 0xcbda91b8, 1 | BRF_ESS | BRF_PRG },
	{ "vm3.08a",      0x080000, 0x6ca47259, 1 | BRF_ESS | BRF_PRG },
	{ "vm3.09b",      0x080000, 0xf4a339e3, 1 | BRF_ESS | BRF_PRG },
	{ "vm3.10b",      0x080000, 0xfffbb5b8, 1 | BRF_ESS | BRF_PRG },

	{ "vm3.13m",      0x400000, 0xfd8a11eb, 3 | BRF_GRA },
	{ "vm3.15m",      0x400000, 0xdd1e7d4e, 3 | BRF_GRA },
	{ "vm3.17m",      0x400000, 0x6b89445e, 3 | BRF_GRA },
	{ "vm3.19m",      0x400000, 0x3830fdc7, 3 | BRF_GRA },
	{ "vm3.14m",      0x400000, 0xc1a28e6c, 3 | BRF_GRA },
	{ "vm3.16m",      0x400000, 0x194a7304, 3 | BRF_GRA },
	{ "vm3.18m",      0x400000, 0xdf9a9f47, 3 | BRF_GRA },
	{ "vm3.20m",      0x400000, 0xc22fc3d9, 3 | BRF_GRA },

	{ "vm3.01",       0x020000, 0xf778769b, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "vm3.02",       0x020000, 0xcc09faa1, 4 | BRF_ESS | BRF_PRG },

	{ "vm3.11m",      0x400000, 0xe80e956e, 5 | BRF_SND },
	{ "vm3.12m",      0x400000, 0x9cd71557, 5 | BRF_SND },
};

STD_ROM_PICK(Vsava) STD_ROM_FN(Vsava)

struct BurnDriver BurnDrvCpsVsava = {
	"vsava", "vsav", NULL, "1997",
	"Vampire Savior: The Lord of Vampire (Asia 970519)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, VsavaRomInfo, VsavaRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Vampire Savior: The Lord of Vampire (Hispanic 970519)

static struct BurnRomInfo VsavhRomDesc[] = {
	{ "vm3h.03a",     0x080000, 0x7cc62df8, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "vm3h.04d",     0x080000, 0xd716f3b5, 1 | BRF_ESS | BRF_PRG },
	{ "vm3.05a",      0x080000, 0x4118e00f, 1 | BRF_ESS | BRF_PRG },
	{ "vm3.06a",      0x080000, 0x2f4fd3a9, 1 | BRF_ESS | BRF_PRG },
	{ "vm3.07b",      0x080000, 0xcbda91b8, 1 | BRF_ESS | BRF_PRG },
	{ "vm3.08a",      0x080000, 0x6ca47259, 1 | BRF_ESS | BRF_PRG },
	{ "vm3.09b",      0x080000, 0xf4a339e3, 1 | BRF_ESS | BRF_PRG },
	{ "vm3.10b",      0x080000, 0xfffbb5b8, 1 | BRF_ESS | BRF_PRG },

	{ "vm3.13m",      0x400000, 0xfd8a11eb, 3 | BRF_GRA },
	{ "vm3.15m",      0x400000, 0xdd1e7d4e, 3 | BRF_GRA },
	{ "vm3.17m",      0x400000, 0x6b89445e, 3 | BRF_GRA },
	{ "vm3.19m",      0x400000, 0x3830fdc7, 3 | BRF_GRA },
	{ "vm3.14m",      0x400000, 0xc1a28e6c, 3 | BRF_GRA },
	{ "vm3.16m",      0x400000, 0x194a7304, 3 | BRF_GRA },
	{ "vm3.18m",      0x400000, 0xdf9a9f47, 3 | BRF_GRA },
	{ "vm3.20m",      0x400000, 0xc22fc3d9, 3 | BRF_GRA },

	{ "vm3.01",       0x020000, 0xf778769b, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "vm3.02",       0x020000, 0xcc09faa1, 4 | BRF_ESS | BRF_PRG },

	{ "vm3.11m",      0x400000, 0xe80e956e, 5 | BRF_SND },
	{ "vm3.12m",      0x400000, 0x9cd71557, 5 | BRF_SND },
};

STD_ROM_PICK(Vsavh) STD_ROM_FN(Vsavh)

struct BurnDriver BurnDrvCpsVsavh = {
	"vsavh", "vsav", NULL, "1997",
	"Vampire Savior: The Lord of Vampire (Hispanic 970519)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, VsavhRomInfo, VsavhRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Vampire Savior: The Lord of Vampire (Euro 970519, Phoenix Edition)

static struct BurnRomInfo VsavdRomDesc[] = {
	{ "vm3ed.03d",     0x80000, 0x97d805e3, 1 | BRF_ESS | BRF_PRG },
	{ "vm3ed.04d",     0x80000, 0x5e07fdce, 1 | BRF_ESS | BRF_PRG },
	{ "vm3.05a",       0x80000, 0x4118e00f, 1 | BRF_ESS | BRF_PRG },
	{ "vm3.06a",       0x80000, 0x2f4fd3a9, 1 | BRF_ESS | BRF_PRG },
	{ "vm3.07b",       0x80000, 0xcbda91b8, 1 | BRF_ESS | BRF_PRG },
	{ "vm3.08a",       0x80000, 0x6ca47259, 1 | BRF_ESS | BRF_PRG },
	{ "vm3.09b",       0x80000, 0xf4a339e3, 1 | BRF_ESS | BRF_PRG },
	{ "vm3.10b",       0x80000, 0xfffbb5b8, 1 | BRF_ESS | BRF_PRG },

	{ "vm3.13m",      0x400000, 0xfd8a11eb, 3 | BRF_GRA },
	{ "vm3.15m",      0x400000, 0xdd1e7d4e, 3 | BRF_GRA },
	{ "vm3.17m",      0x400000, 0x6b89445e, 3 | BRF_GRA },
	{ "vm3.19m",      0x400000, 0x3830fdc7, 3 | BRF_GRA },
	{ "vm3.14m",      0x400000, 0xc1a28e6c, 3 | BRF_GRA },
	{ "vm3.16m",      0x400000, 0x194a7304, 3 | BRF_GRA },
	{ "vm3.18m",      0x400000, 0xdf9a9f47, 3 | BRF_GRA },
	{ "vm3.20m",      0x400000, 0xc22fc3d9, 3 | BRF_GRA },

	{ "vm3.01",       0x020000, 0xf778769b, 4 | BRF_ESS | BRF_PRG },
	{ "vm3.02",       0x020000, 0xcc09faa1, 4 | BRF_ESS | BRF_PRG },

	{ "vm3.11m",      0x400000, 0xe80e956e, 5 | BRF_SND },
	{ "vm3.12m",      0x400000, 0x9cd71557, 5 | BRF_SND },
};

STD_ROM_PICK(Vsavd) STD_ROM_FN(Vsavd)

struct BurnDriver BurnDrvCpsVsavd = {
	"vsavd", "vsav", NULL, "1997",
	"Vampire Savior: The Lord of Vampire (Euro 970519, Phoenix Edition)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE | BDF_BOOTLEG,2,HARDWARE_CAPCOM_CPS2,
	NULL, VsavdRomInfo, VsavdRomName, DrvInputInfo, NULL,
	PhoenixInit, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// Vampire Savior 2: The Lord of Vampire (Japan 970913)

static struct BurnRomInfo Vsav2RomDesc[] = {
	{ "vs2j.03",      0x080000, 0x89fd86b4, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "vs2j.04",      0x080000, 0x107c091b, 1 | BRF_ESS | BRF_PRG },
	{ "vs2j.05",      0x080000, 0x61979638, 1 | BRF_ESS | BRF_PRG },
	{ "vs2j.06",      0x080000, 0xf37c5bc2, 1 | BRF_ESS | BRF_PRG },
	{ "vs2j.07",      0x080000, 0x8f885809, 1 | BRF_ESS | BRF_PRG },
	{ "vs2j.08",      0x080000, 0x2018c120, 1 | BRF_ESS | BRF_PRG },
	{ "vs2j.09",      0x080000, 0xfac3c217, 1 | BRF_ESS | BRF_PRG },
	{ "vs2j.10",      0x080000, 0xeb490213, 1 | BRF_ESS | BRF_PRG },

	{ "vs2.13m",      0x400000, 0x5c852f52, 3 | BRF_GRA },
	{ "vs2.15m",      0x400000, 0xa20f58af, 3 | BRF_GRA },
	{ "vs2.17m",      0x400000, 0x39db59ad, 3 | BRF_GRA },
	{ "vs2.19m",      0x400000, 0x00c763a7, 3 | BRF_GRA },
	{ "vs2.14m",      0x400000, 0xcd09bd63, 3 | BRF_GRA },
	{ "vs2.16m",      0x400000, 0xe0182c15, 3 | BRF_GRA },
	{ "vs2.18m",      0x400000, 0x778dc4f6, 3 | BRF_GRA },
	{ "vs2.20m",      0x400000, 0x605d9d1d, 3 | BRF_GRA },

	{ "vs2.01",       0x020000, 0x35190139, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "vs2.02",       0x020000, 0xc32dba09, 4 | BRF_ESS | BRF_PRG },

	{ "vs2.11m",      0x400000, 0xd67e47b7, 5 | BRF_SND },
	{ "vs2.12m",      0x400000, 0x6d020a14, 5 | BRF_SND },
};

STD_ROM_PICK(Vsav2) STD_ROM_FN(Vsav2)

struct BurnDriver BurnDrvCpsVsav2 = {
	"vsav2", NULL, NULL, "1997",
	"Vampire Savior 2: The Lord of Vampire (Japan 970913)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING,2,HARDWARE_CAPCOM_CPS2,
	NULL, Vsav2RomInfo, Vsav2RomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// X-Men: Children of the Atom (Euro 950105)

static struct BurnRomInfo XmcotaRomDesc[] = {
	{ "xmne.03e",     0x080000, 0xa9a09b09, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "xmne.04e",     0x080000, 0x52fa2106, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.05a",      0x080000, 0xac0d7759, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.06a",      0x080000, 0x1b86a328, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.07a",      0x080000, 0x2c142a44, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.08a",      0x080000, 0xf712d44f, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.09a",      0x080000, 0x9241cae8, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.10a",      0x080000, 0x53c0eab9, 1 | BRF_ESS | BRF_PRG },

	{ "xmn.13m",      0x400000, 0xbf4df073, 3 | BRF_GRA },
	{ "xmn.15m",      0x400000, 0x4d7e4cef, 3 | BRF_GRA },
	{ "xmn.17m",      0x400000, 0x513eea17, 3 | BRF_GRA },
	{ "xmn.19m",      0x400000, 0xd23897fc, 3 | BRF_GRA },
	{ "xmn.14m",      0x400000, 0x778237b7, 3 | BRF_GRA },
	{ "xmn.16m",      0x400000, 0x67b36948, 3 | BRF_GRA },
	{ "xmn.18m",      0x400000, 0x015a7c4c, 3 | BRF_GRA },
	{ "xmn.20m",      0x400000, 0x9dde2758, 3 | BRF_GRA },

	{ "xmn.01a",      0x020000, 0x40f479ea, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "xmn.02a",      0x020000, 0x39d9b5ad, 4 | BRF_ESS | BRF_PRG },

	{ "xmn.11m",      0x200000, 0xc848a6bc, 5 | BRF_SND },
	{ "xmn.12m",      0x200000, 0x729c188f, 5 | BRF_SND },
};

STD_ROM_PICK(Xmcota) STD_ROM_FN(Xmcota)

static int XmcotaInit()
{
	Xmcota = 1;
	return Cps2Init();
}

static int XmcotaExit()
{
	Xmcota = 0;
	return CpsExit();
}

static int XmcotaPhoenixInit()
{
	Xmcota = 1;
	return PhoenixInit();
}

struct BurnDriver BurnDrvCpsXmcota = {
	"xmcota", NULL, NULL, "1995",
	"X-Men: Children of the Atom (Euro 950105)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING,2,HARDWARE_CAPCOM_CPS2,
	NULL, XmcotaRomInfo, XmcotaRomName, DrvInputInfo, NULL,
	XmcotaInit, XmcotaExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// X-Men: Children of the Atom (USA 950105)

static struct BurnRomInfo XmcotauRomDesc[] = {
	{ "xmnu.03e",     0x080000, 0x0bafeb0e, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "xmnu.04e",     0x080000, 0xc29bdae3, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.05a",      0x080000, 0xac0d7759, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.06a",      0x080000, 0x1b86a328, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.07a",      0x080000, 0x2c142a44, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.08a",      0x080000, 0xf712d44f, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.09a",      0x080000, 0x9241cae8, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.10a",      0x080000, 0x53c0eab9, 1 | BRF_ESS | BRF_PRG },

	{ "xmn.13m",      0x400000, 0xbf4df073, 3 | BRF_GRA },
	{ "xmn.15m",      0x400000, 0x4d7e4cef, 3 | BRF_GRA },
	{ "xmn.17m",      0x400000, 0x513eea17, 3 | BRF_GRA },
	{ "xmn.19m",      0x400000, 0xd23897fc, 3 | BRF_GRA },
	{ "xmn.14m",      0x400000, 0x778237b7, 3 | BRF_GRA },
	{ "xmn.16m",      0x400000, 0x67b36948, 3 | BRF_GRA },
	{ "xmn.18m",      0x400000, 0x015a7c4c, 3 | BRF_GRA },
	{ "xmn.20m",      0x400000, 0x9dde2758, 3 | BRF_GRA },

	{ "xmn.01a",      0x020000, 0x40f479ea, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "xmn.02a",      0x020000, 0x39d9b5ad, 4 | BRF_ESS | BRF_PRG },

	{ "xmn.11m",      0x200000, 0xc848a6bc, 5 | BRF_SND },
	{ "xmn.12m",      0x200000, 0x729c188f, 5 | BRF_SND },
};

STD_ROM_PICK(Xmcotau) STD_ROM_FN(Xmcotau)

struct BurnDriver BurnDrvCpsXmcotau = {
	"xmcotau", "xmcota", NULL, "1995",
	"X-Men: Children of the Atom (USA 950105)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, XmcotauRomInfo, XmcotauRomName, DrvInputInfo, NULL,
	XmcotaInit, XmcotaExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// X-Men: Children of the Atom (Hispanic 950331)

static struct BurnRomInfo XmcotahRomDesc[] = {
	{ "xmnh.03",      0x080000, 0xe4b85a90, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "xmnh.04",      0x080000, 0x7dfe1406, 1 | BRF_ESS | BRF_PRG },
	{ "xmnh.05",      0x080000, 0x87b0ed0f, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.06a",      0x080000, 0x1b86a328, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.07a",      0x080000, 0x2c142a44, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.08a",      0x080000, 0xf712d44f, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.09a",      0x080000, 0x9241cae8, 1 | BRF_ESS | BRF_PRG },
	{ "xmnh.10",      0x080000, 0xcb36b0a4, 1 | BRF_ESS | BRF_PRG },

	{ "xmn.13m",      0x400000, 0xbf4df073, 3 | BRF_GRA },
	{ "xmn.15m",      0x400000, 0x4d7e4cef, 3 | BRF_GRA },
	{ "xmn.17m",      0x400000, 0x513eea17, 3 | BRF_GRA },
	{ "xmn.19m",      0x400000, 0xd23897fc, 3 | BRF_GRA },
	{ "xmn.14m",      0x400000, 0x778237b7, 3 | BRF_GRA },
	{ "xmn.16m",      0x400000, 0x67b36948, 3 | BRF_GRA },
	{ "xmn.18m",      0x400000, 0x015a7c4c, 3 | BRF_GRA },
	{ "xmn.20m",      0x400000, 0x9dde2758, 3 | BRF_GRA },

	{ "xmn.01a",      0x020000, 0x40f479ea, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "xmn.02a",      0x020000, 0x39d9b5ad, 4 | BRF_ESS | BRF_PRG },

	{ "xmn.11m",      0x200000, 0xc848a6bc, 5 | BRF_SND },
	{ "xmn.12m",      0x200000, 0x729c188f, 5 | BRF_SND },
};

STD_ROM_PICK(Xmcotah) STD_ROM_FN(Xmcotah)

struct BurnDriver BurnDrvCpsXmcotah = {
	"xmcotah", "xmcota", NULL, "1995",
	"X-Men: Children of the Atom (Hispanic 950331)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE, 2,HARDWARE_CAPCOM_CPS2,
	NULL, XmcotahRomInfo, XmcotahRomName, DrvInputInfo, NULL,
	XmcotaInit, XmcotaExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// X-Men: Children of the Atom (Japan 950105)

static struct BurnRomInfo XmcotajRomDesc[] = {
	{ "xmnj.03e",     0x080000, 0x0df29f5f, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "xmnj.04e",     0x080000, 0x4a65833b, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.05a",      0x080000, 0xac0d7759, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.06a",      0x080000, 0x1b86a328, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.07a",      0x080000, 0x2c142a44, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.08a",      0x080000, 0xf712d44f, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.09a",      0x080000, 0x9241cae8, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.10a",      0x080000, 0x53c0eab9, 1 | BRF_ESS | BRF_PRG },

	{ "xmn.13m",      0x400000, 0xbf4df073, 3 | BRF_GRA },
	{ "xmn.15m",      0x400000, 0x4d7e4cef, 3 | BRF_GRA },
	{ "xmn.17m",      0x400000, 0x513eea17, 3 | BRF_GRA },
	{ "xmn.19m",      0x400000, 0xd23897fc, 3 | BRF_GRA },
	{ "xmn.14m",      0x400000, 0x778237b7, 3 | BRF_GRA },
	{ "xmn.16m",      0x400000, 0x67b36948, 3 | BRF_GRA },
	{ "xmn.18m",      0x400000, 0x015a7c4c, 3 | BRF_GRA },
	{ "xmn.20m",      0x400000, 0x9dde2758, 3 | BRF_GRA },

	{ "xmn.01a",      0x020000, 0x40f479ea, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "xmn.02a",      0x020000, 0x39d9b5ad, 4 | BRF_ESS | BRF_PRG },

	{ "xmn.11m",      0x200000, 0xc848a6bc, 5 | BRF_SND },
	{ "xmn.12m",      0x200000, 0x729c188f, 5 | BRF_SND },
};

STD_ROM_PICK(Xmcotaj) STD_ROM_FN(Xmcotaj)

struct BurnDriver BurnDrvCpsXmcotaj = {
	"xmcotaj", "xmcota", NULL, "1994",
	"X-Men: Children of the Atom (Japan 950105)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, XmcotajRomInfo, XmcotajRomName, DrvInputInfo, NULL,
	XmcotaInit, XmcotaExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// X-Men: Children of the Atom (Japan 941222)

static struct BurnRomInfo Xmcotaj1RomDesc[] = {
	{ "xmnj.03d",     0x080000, 0x79086d62, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "xmnj.04d",     0x080000, 0x38eed613, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.05",       0x080000, 0xc3ed62a2, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.06",       0x080000, 0xf03c52e1, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.07",       0x080000, 0x325626b1, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.08",       0x080000, 0x7194ea10, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.09",       0x080000, 0xae946df3, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.10",       0x080000, 0x32a6be1d, 1 | BRF_ESS | BRF_PRG },

	{ "xmn.13m",      0x400000, 0xbf4df073, 3 | BRF_GRA },
	{ "xmn.15m",      0x400000, 0x4d7e4cef, 3 | BRF_GRA },
	{ "xmn.17m",      0x400000, 0x513eea17, 3 | BRF_GRA },
	{ "xmn.19m",      0x400000, 0xd23897fc, 3 | BRF_GRA },
	{ "xmn.14m",      0x400000, 0x778237b7, 3 | BRF_GRA },
	{ "xmn.16m",      0x400000, 0x67b36948, 3 | BRF_GRA },
	{ "xmn.18m",      0x400000, 0x015a7c4c, 3 | BRF_GRA },
	{ "xmn.20m",      0x400000, 0x9dde2758, 3 | BRF_GRA },

	{ "xmn.01a",      0x020000, 0x40f479ea, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "xmn.02a",      0x020000, 0x39d9b5ad, 4 | BRF_ESS | BRF_PRG },

	{ "xmn.11m",      0x200000, 0xc848a6bc, 5 | BRF_SND },
	{ "xmn.12m",      0x200000, 0x729c188f, 5 | BRF_SND },
};

STD_ROM_PICK(Xmcotaj1) STD_ROM_FN(Xmcotaj1)

struct BurnDriver BurnDrvCpsXmcotaj1 = {
	"xmcotaj1", "xmcota", NULL, "1994",
	"X-Men: Children of the Atom (Japan 941222)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Xmcotaj1RomInfo, Xmcotaj1RomName, DrvInputInfo, NULL,
	XmcotaInit, XmcotaExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// X-Men: Children of the Atom (Japan 941219)

static struct BurnRomInfo Xmcotaj2RomDesc[] = {
	{ "xmnj.03b",     0x080000, 0xc8175fb3, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "xmnj.04b",     0x080000, 0x54b3fba3, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.05",       0x080000, 0xc3ed62a2, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.06",       0x080000, 0xf03c52e1, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.07",       0x080000, 0x325626b1, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.08",       0x080000, 0x7194ea10, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.09",       0x080000, 0xae946df3, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.10",       0x080000, 0x32a6be1d, 1 | BRF_ESS | BRF_PRG },

	{ "xmn.13m",      0x400000, 0xbf4df073, 3 | BRF_GRA },
	{ "xmn.15m",      0x400000, 0x4d7e4cef, 3 | BRF_GRA },
	{ "xmn.17m",      0x400000, 0x513eea17, 3 | BRF_GRA },
	{ "xmn.19m",      0x400000, 0xd23897fc, 3 | BRF_GRA },
	{ "xmn.14m",      0x400000, 0x778237b7, 3 | BRF_GRA },
	{ "xmn.16m",      0x400000, 0x67b36948, 3 | BRF_GRA },
	{ "xmn.18m",      0x400000, 0x015a7c4c, 3 | BRF_GRA },
	{ "xmn.20m",      0x400000, 0x9dde2758, 3 | BRF_GRA },

	{ "xmn.01a",      0x020000, 0x40f479ea, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "xmn.02a",      0x020000, 0x39d9b5ad, 4 | BRF_ESS | BRF_PRG },

	{ "xmn.11m",      0x200000, 0xc848a6bc, 5 | BRF_SND },
	{ "xmn.12m",      0x200000, 0x729c188f, 5 | BRF_SND },
};

STD_ROM_PICK(Xmcotaj2) STD_ROM_FN(Xmcotaj2)

struct BurnDriver BurnDrvCpsXmcotaj2 = {
	"xmcotaj2", "xmcota", NULL, "1994",
	"X-Men: Children of the Atom (Japan 941219)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Xmcotaj2RomInfo, Xmcotaj2RomName, DrvInputInfo, NULL,
	XmcotaInit, XmcotaExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// X-Men: Children of the Atom (Japan 941217)

static struct BurnRomInfo Xmcotaj3RomDesc[] = {
	{ "xmnj.03a",     0x080000, 0x00761611, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "xmnj.04a",     0x080000, 0x614d3f60, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.05",       0x080000, 0xc3ed62a2, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.06",       0x080000, 0xf03c52e1, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.07",       0x080000, 0x325626b1, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.08",       0x080000, 0x7194ea10, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.09",       0x080000, 0xae946df3, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.10",       0x080000, 0x32a6be1d, 1 | BRF_ESS | BRF_PRG },

	{ "xmn.13m",      0x400000, 0xbf4df073, 3 | BRF_GRA },
	{ "xmn.15m",      0x400000, 0x4d7e4cef, 3 | BRF_GRA },
	{ "xmn.17m",      0x400000, 0x513eea17, 3 | BRF_GRA },
	{ "xmn.19m",      0x400000, 0xd23897fc, 3 | BRF_GRA },
	{ "xmn.14m",      0x400000, 0x778237b7, 3 | BRF_GRA },
	{ "xmn.16m",      0x400000, 0x67b36948, 3 | BRF_GRA },
	{ "xmn.18m",      0x400000, 0x015a7c4c, 3 | BRF_GRA },
	{ "xmn.20m",      0x400000, 0x9dde2758, 3 | BRF_GRA },

	{ "xmn.01a",      0x020000, 0x40f479ea, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "xmn.02a",      0x020000, 0x39d9b5ad, 4 | BRF_ESS | BRF_PRG },

	{ "xmn.11m",      0x200000, 0xc848a6bc, 5 | BRF_SND },
	{ "xmn.12m",      0x200000, 0x729c188f, 5 | BRF_SND },
};

STD_ROM_PICK(Xmcotaj3) STD_ROM_FN(Xmcotaj3)

struct BurnDriver BurnDrvCpsXmcotaj3 = {
	"xmcotaj3", "xmcota", NULL, "1994",
	"X-Men: Children of the Atom (Japan 941217)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Xmcotaj3RomInfo, Xmcotaj3RomName, DrvInputInfo, NULL,
	XmcotaInit, XmcotaExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// X-Men: Children of the Atom (Japan 941208 rent version)

static struct BurnRomInfo XmcotajrRomDesc[] = {
	{ "xmno.03a",     0x080000, 0x7ab19acf, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "xmno.04a",     0x080000, 0x7615dd21, 1 | BRF_ESS | BRF_PRG },
	{ "xmno.05a",     0x080000, 0x0303d672, 1 | BRF_ESS | BRF_PRG },
	{ "xmno.06a",     0x080000, 0x332839a5, 1 | BRF_ESS | BRF_PRG },
	{ "xmno.07",      0x080000, 0x6255e8d5, 1 | BRF_ESS | BRF_PRG },
	{ "xmno.08",      0x080000, 0xb8ebe77c, 1 | BRF_ESS | BRF_PRG },
	{ "xmno.09",      0x080000, 0x5440d950, 1 | BRF_ESS | BRF_PRG },
	{ "xmno.10a",     0x080000, 0xb8296966, 1 | BRF_ESS | BRF_PRG },

	{ "xmn.13m",      0x400000, 0xbf4df073, 3 | BRF_GRA },
	{ "xmn.15m",      0x400000, 0x4d7e4cef, 3 | BRF_GRA },
	{ "xmn.17m",      0x400000, 0x513eea17, 3 | BRF_GRA },
	{ "xmn.19m",      0x400000, 0xd23897fc, 3 | BRF_GRA },
	{ "xmn.14m",      0x400000, 0x778237b7, 3 | BRF_GRA },
	{ "xmn.16m",      0x400000, 0x67b36948, 3 | BRF_GRA },
	{ "xmn.18m",      0x400000, 0x015a7c4c, 3 | BRF_GRA },
	{ "xmn.20m",      0x400000, 0x9dde2758, 3 | BRF_GRA },

	{ "xmn.01",       0x020000, 0x7178336e, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "xmn.02",       0x020000, 0x0ec58501, 4 | BRF_ESS | BRF_PRG },

	{ "xmn.11m",      0x200000, 0xc848a6bc, 5 | BRF_SND },
	{ "xmn.12m",      0x200000, 0x729c188f, 5 | BRF_SND },
};

STD_ROM_PICK(Xmcotajr) STD_ROM_FN(Xmcotajr)

struct BurnDriver BurnDrvCpsXmcotajr = {
	"xmcotajr", "xmcota", NULL, "1994",
	"X-Men: Children of the Atom (Japan 941208 rent version)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, XmcotajrRomInfo, XmcotajrRomName, DrvInputInfo, NULL,
	XmcotaInit, XmcotaExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// X-Men: Children of the Atom (Asia 941217)

static struct BurnRomInfo XmcotaaRomDesc[] = {
	{ "xmna.03a",     0x080000, 0x7df8b27e, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "xmna.04a",     0x080000, 0xb44e30a7, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.05",       0x080000, 0xc3ed62a2, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.06",       0x080000, 0xf03c52e1, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.07",       0x080000, 0x325626b1, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.08",       0x080000, 0x7194ea10, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.09",       0x080000, 0xae946df3, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.10",       0x080000, 0x32a6be1d, 1 | BRF_ESS | BRF_PRG },

	{ "xmn.13m",      0x400000, 0xbf4df073, 3 | BRF_GRA },
	{ "xmn.15m",      0x400000, 0x4d7e4cef, 3 | BRF_GRA },
	{ "xmn.17m",      0x400000, 0x513eea17, 3 | BRF_GRA },
	{ "xmn.19m",      0x400000, 0xd23897fc, 3 | BRF_GRA },
	{ "xmn.14m",      0x400000, 0x778237b7, 3 | BRF_GRA },
	{ "xmn.16m",      0x400000, 0x67b36948, 3 | BRF_GRA },
	{ "xmn.18m",      0x400000, 0x015a7c4c, 3 | BRF_GRA },
	{ "xmn.20m",      0x400000, 0x9dde2758, 3 | BRF_GRA },

	{ "xmn.01a",      0x020000, 0x40f479ea, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "xmn.02a",      0x020000, 0x39d9b5ad, 4 | BRF_ESS | BRF_PRG },

	{ "xmn.11m",      0x200000, 0xc848a6bc, 5 | BRF_SND },
	{ "xmn.12m",      0x200000, 0x729c188f, 5 | BRF_SND },
};


STD_ROM_PICK(Xmcotaa) STD_ROM_FN(Xmcotaa)

struct BurnDriver BurnDrvCpsXmcotaa = {
	"xmcotaa", "xmcota", NULL, "1995",
	"X-Men: Children of the Atom (Asia 941217)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, XmcotaaRomInfo, XmcotaaRomName, DrvInputInfo, NULL,
	XmcotaInit, XmcotaExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// X-Men: Children of the Atom (Euro 950105, Phoenix Edition)

static struct BurnRomInfo XmcotadRomDesc[] = {
	{ "xmned.03e",     0x80000, 0xbef56003, 1 | BRF_ESS | BRF_PRG }, // 68000 code
	{ "xmned.04e",     0x80000, 0xb1a21fa6, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.05a",       0x80000, 0xac0d7759, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.06a",       0x80000, 0x1b86a328, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.07a",       0x80000, 0x2c142a44, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.08a",       0x80000, 0xf712d44f, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.09a",       0x80000, 0x9241cae8, 1 | BRF_ESS | BRF_PRG },
	{ "xmn.10a",       0x80000, 0x53c0eab9, 1 | BRF_ESS | BRF_PRG },

	{ "xmn.13m",      0x400000, 0xbf4df073, 3 | BRF_GRA },			 // Graphics
	{ "xmn.15m",      0x400000, 0x4d7e4cef, 3 | BRF_GRA },
	{ "xmn.17m",      0x400000, 0x513eea17, 3 | BRF_GRA },
	{ "xmn.19m",      0x400000, 0xd23897fc, 3 | BRF_GRA },
	{ "xmn.14m",      0x400000, 0x778237b7, 3 | BRF_GRA },
	{ "xmn.16m",      0x400000, 0x67b36948, 3 | BRF_GRA },
	{ "xmn.18m",      0x400000, 0x015a7c4c, 3 | BRF_GRA },
	{ "xmn.20m",      0x400000, 0x9dde2758, 3 | BRF_GRA },

	{ "xmn.01a",      0x020000, 0x40f479ea, 4 | BRF_ESS | BRF_PRG }, // Z80 code
	{ "xmn.02a",      0x020000, 0x39d9b5ad, 4 | BRF_ESS | BRF_PRG },

	{ "xmn.11m",      0x200000, 0xc848a6bc, 5 | BRF_SND },			 // QSound data
	{ "xmn.12m",      0x200000, 0x729c188f, 5 | BRF_SND },
};

STD_ROM_PICK(Xmcotad) STD_ROM_FN(Xmcotad)

struct BurnDriver BurnDrvCpsXmcotad = {
	"xmcotad", "xmcota", NULL, "1995",
	"X-Men: Children of the Atom (Euro 950105, Phoenix Edition)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE | BDF_BOOTLEG,2,HARDWARE_CAPCOM_CPS2,
	NULL, XmcotadRomInfo, XmcotadRomName, DrvInputInfo, NULL,
	XmcotaPhoenixInit, XmcotaExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// X-Men vs Street Fighter (Euro 961004)

static struct BurnRomInfo XmvsfRomDesc[] = {
	{ "xvse.03f",     0x080000, 0xdb06413f, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "xvse.04f",     0x080000, 0xef015aef, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.05a",      0x080000, 0x7db6025d, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.06a",      0x080000, 0xe8e2c75c, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.07",       0x080000, 0x08f0abed, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.08",       0x080000, 0x81929675, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.09",       0x080000, 0x9641f36b, 1 | BRF_ESS | BRF_PRG },

	{ "xvs.13m",      0x400000, 0xf6684efd, 3 | BRF_GRA },
	{ "xvs.15m",      0x400000, 0x29109221, 3 | BRF_GRA },
	{ "xvs.17m",      0x400000, 0x92db3474, 3 | BRF_GRA },
	{ "xvs.19m",      0x400000, 0x3733473c, 3 | BRF_GRA },
	{ "xvs.14m",      0x400000, 0xbcac2e41, 3 | BRF_GRA },
	{ "xvs.16m",      0x400000, 0xea04a272, 3 | BRF_GRA },
	{ "xvs.18m",      0x400000, 0xb0def86a, 3 | BRF_GRA },
	{ "xvs.20m",      0x400000, 0x4b40ff9f, 3 | BRF_GRA },

	{ "xvs.01",       0x020000, 0x3999e93a, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "xvs.02",       0x020000, 0x101bdee9, 4 | BRF_ESS | BRF_PRG },

	{ "xvs.11m",      0x200000, 0x9cadcdbc, 5 | BRF_SND },
	{ "xvs.12m",      0x200000, 0x7b11e460, 5 | BRF_SND },
};

STD_ROM_PICK(Xmvsf) STD_ROM_FN(Xmvsf)

struct BurnDriver BurnDrvCpsXmvsf = {
	"xmvsf", NULL, NULL, "1996",
	"X-Men vs Street Fighter (Euro 961004)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING,2,HARDWARE_CAPCOM_CPS2,
	NULL, XmvsfRomInfo, XmvsfRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// X-Men vs Street Fighter (Euro 960910)

static struct BurnRomInfo Xmvsfr1RomDesc[] = {
	{ "xvse.03d",     0x080000, 0x5ae5bd3b, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "xvse.04d",     0x080000, 0x5eb9c02e, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.05a",      0x080000, 0x7db6025d, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.06a",      0x080000, 0xe8e2c75c, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.07",       0x080000, 0x08f0abed, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.08",       0x080000, 0x81929675, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.09",       0x080000, 0x9641f36b, 1 | BRF_ESS | BRF_PRG },

	{ "xvs.13m",      0x400000, 0xf6684efd, 3 | BRF_GRA },
	{ "xvs.15m",      0x400000, 0x29109221, 3 | BRF_GRA },
	{ "xvs.17m",      0x400000, 0x92db3474, 3 | BRF_GRA },
	{ "xvs.19m",      0x400000, 0x3733473c, 3 | BRF_GRA },
	{ "xvs.14m",      0x400000, 0xbcac2e41, 3 | BRF_GRA },
	{ "xvs.16m",      0x400000, 0xea04a272, 3 | BRF_GRA },
	{ "xvs.18m",      0x400000, 0xb0def86a, 3 | BRF_GRA },
	{ "xvs.20m",      0x400000, 0x4b40ff9f, 3 | BRF_GRA },

	{ "xvs.01",       0x020000, 0x3999e93a, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "xvs.02",       0x020000, 0x101bdee9, 4 | BRF_ESS | BRF_PRG },

	{ "xvs.11m",      0x200000, 0x9cadcdbc, 5 | BRF_SND },
	{ "xvs.12m",      0x200000, 0x7b11e460, 5 | BRF_SND },
};

STD_ROM_PICK(Xmvsfr1) STD_ROM_FN(Xmvsfr1)

struct BurnDriver BurnDrvCpsXmvsfr1 = {
	"xmvsfr1", "xmvsf", NULL, "1996",
	"X-Men vs Street Fighter (Euro 960910)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Xmvsfr1RomInfo, Xmvsfr1RomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// X-Men vs Street Fighter (USA 961023)

static struct BurnRomInfo XmvsfuRomDesc[] = {
	{ "xvsu.03k",     0x080000, 0x8739ef61, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "xvsu.04k",     0x080000, 0xe11d35c1, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.05a",      0x080000, 0x7db6025d, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.06a",      0x080000, 0xe8e2c75c, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.07",       0x080000, 0x08f0abed, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.08",       0x080000, 0x81929675, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.09",       0x080000, 0x9641f36b, 1 | BRF_ESS | BRF_PRG },

	{ "xvs.13m",      0x400000, 0xf6684efd, 3 | BRF_GRA },
	{ "xvs.15m",      0x400000, 0x29109221, 3 | BRF_GRA },
	{ "xvs.17m",      0x400000, 0x92db3474, 3 | BRF_GRA },
	{ "xvs.19m",      0x400000, 0x3733473c, 3 | BRF_GRA },
	{ "xvs.14m",      0x400000, 0xbcac2e41, 3 | BRF_GRA },
	{ "xvs.16m",      0x400000, 0xea04a272, 3 | BRF_GRA },
	{ "xvs.18m",      0x400000, 0xb0def86a, 3 | BRF_GRA },
	{ "xvs.20m",      0x400000, 0x4b40ff9f, 3 | BRF_GRA },

	{ "xvs.01",       0x020000, 0x3999e93a, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "xvs.02",       0x020000, 0x101bdee9, 4 | BRF_ESS | BRF_PRG },

	{ "xvs.11m",      0x200000, 0x9cadcdbc, 5 | BRF_SND },
	{ "xvs.12m",      0x200000, 0x7b11e460, 5 | BRF_SND },
};

STD_ROM_PICK(Xmvsfu) STD_ROM_FN(Xmvsfu)

struct BurnDriver BurnDrvCpsXmvsfu = {
	"xmvsfu", "xmvsf", NULL, "1996",
	"X-Men vs Street Fighter (USA 961023)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, XmvsfuRomInfo, XmvsfuRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// X-Men vs Street Fighter (USA 961004)

static struct BurnRomInfo Xmvsfur1RomDesc[] = {
	{ "xvsu.03h",     0x080000, 0x5481155a, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "xvsu.04h",     0x080000, 0x1e236388, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.05a",      0x080000, 0x7db6025d, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.06a",      0x080000, 0xe8e2c75c, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.07",       0x080000, 0x08f0abed, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.08",       0x080000, 0x81929675, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.09",       0x080000, 0x9641f36b, 1 | BRF_ESS | BRF_PRG },

	{ "xvs.13m",      0x400000, 0xf6684efd, 3 | BRF_GRA },
	{ "xvs.15m",      0x400000, 0x29109221, 3 | BRF_GRA },
	{ "xvs.17m",      0x400000, 0x92db3474, 3 | BRF_GRA },
	{ "xvs.19m",      0x400000, 0x3733473c, 3 | BRF_GRA },
	{ "xvs.14m",      0x400000, 0xbcac2e41, 3 | BRF_GRA },
	{ "xvs.16m",      0x400000, 0xea04a272, 3 | BRF_GRA },
	{ "xvs.18m",      0x400000, 0xb0def86a, 3 | BRF_GRA },
	{ "xvs.20m",      0x400000, 0x4b40ff9f, 3 | BRF_GRA },

	{ "xvs.01",       0x020000, 0x3999e93a, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "xvs.02",       0x020000, 0x101bdee9, 4 | BRF_ESS | BRF_PRG },

	{ "xvs.11m",      0x200000, 0x9cadcdbc, 5 | BRF_SND },
	{ "xvs.12m",      0x200000, 0x7b11e460, 5 | BRF_SND },
};

STD_ROM_PICK(Xmvsfur1) STD_ROM_FN(Xmvsfur1)

struct BurnDriver BurnDrvCpsXmvsfur1 = {
	"xmvsfur1", "xmvsf", NULL, "1996",
	"X-Men vs Street Fighter (USA 961004)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Xmvsfur1RomInfo, Xmvsfur1RomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// X-Men vs Street Fighter (Japan 961004)

static struct BurnRomInfo XmvsfjRomDesc[] = {
	{ "xvsj.03i",     0x080000, 0xef24da96, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "xvsj.04i",     0x080000, 0x70a59b35, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.05a",      0x080000, 0x7db6025d, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.06a",      0x080000, 0xe8e2c75c, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.07",       0x080000, 0x08f0abed, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.08",       0x080000, 0x81929675, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.09",       0x080000, 0x9641f36b, 1 | BRF_ESS | BRF_PRG },

	{ "xvs.13m",      0x400000, 0xf6684efd, 3 | BRF_GRA },
	{ "xvs.15m",      0x400000, 0x29109221, 3 | BRF_GRA },
	{ "xvs.17m",      0x400000, 0x92db3474, 3 | BRF_GRA },
	{ "xvs.19m",      0x400000, 0x3733473c, 3 | BRF_GRA },
	{ "xvs.14m",      0x400000, 0xbcac2e41, 3 | BRF_GRA },
	{ "xvs.16m",      0x400000, 0xea04a272, 3 | BRF_GRA },
	{ "xvs.18m",      0x400000, 0xb0def86a, 3 | BRF_GRA },
	{ "xvs.20m",      0x400000, 0x4b40ff9f, 3 | BRF_GRA },

	{ "xvs.01",       0x020000, 0x3999e93a, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "xvs.02",       0x020000, 0x101bdee9, 4 | BRF_ESS | BRF_PRG },

	{ "xvs.11m",      0x200000, 0x9cadcdbc, 5 | BRF_SND },
	{ "xvs.12m",      0x200000, 0x7b11e460, 5 | BRF_SND },
};

STD_ROM_PICK(Xmvsfj) STD_ROM_FN(Xmvsfj)

struct BurnDriver BurnDrvCpsXmvsfj = {
	"xmvsfj", "xmvsf", NULL, "1996",
	"X-Men vs Street Fighter (Japan 961004)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, XmvsfjRomInfo, XmvsfjRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// X-Men vs Street Fighter (Japan 960910)

static struct BurnRomInfo Xmvsfjr1RomDesc[] = {
	{ "xvsj.03d",     0x080000, 0xbeb81de9, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "xvsj.04d",     0x080000, 0x23d11271, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.05a",      0x080000, 0x7db6025d, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.06a",      0x080000, 0xe8e2c75c, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.07",       0x080000, 0x08f0abed, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.08",       0x080000, 0x81929675, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.09",       0x080000, 0x9641f36b, 1 | BRF_ESS | BRF_PRG },

	{ "xvs.13m",      0x400000, 0xf6684efd, 3 | BRF_GRA },
	{ "xvs.15m",      0x400000, 0x29109221, 3 | BRF_GRA },
	{ "xvs.17m",      0x400000, 0x92db3474, 3 | BRF_GRA },
	{ "xvs.19m",      0x400000, 0x3733473c, 3 | BRF_GRA },
	{ "xvs.14m",      0x400000, 0xbcac2e41, 3 | BRF_GRA },
	{ "xvs.16m",      0x400000, 0xea04a272, 3 | BRF_GRA },
	{ "xvs.18m",      0x400000, 0xb0def86a, 3 | BRF_GRA },
	{ "xvs.20m",      0x400000, 0x4b40ff9f, 3 | BRF_GRA },

	{ "xvs.01",       0x020000, 0x3999e93a, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "xvs.02",       0x020000, 0x101bdee9, 4 | BRF_ESS | BRF_PRG },

	{ "xvs.11m",      0x200000, 0x9cadcdbc, 5 | BRF_SND },
	{ "xvs.12m",      0x200000, 0x7b11e460, 5 | BRF_SND },
};

STD_ROM_PICK(Xmvsfjr1) STD_ROM_FN(Xmvsfjr1)

struct BurnDriver BurnDrvCpsXmvsfjr1 = {
	"xmvsfjr1", "xmvsf", NULL, "1996",
	"X-Men vs Street Fighter (Japan 960910)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Xmvsfjr1RomInfo, Xmvsfjr1RomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// X-Men vs Street Fighter (Japan 960909)

static struct BurnRomInfo Xmvsfjr2RomDesc[] = {
	{ "xvsj.03c",     0x080000, 0x180656a1, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "xvsj.04c",     0x080000, 0x5832811c, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.05",       0x080000, 0x030e0e1e, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.06",       0x080000, 0x5d04a8ff, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.07",       0x080000, 0x08f0abed, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.08",       0x080000, 0x81929675, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.09",       0x080000, 0x9641f36b, 1 | BRF_ESS | BRF_PRG },

	{ "xvs.13m",      0x400000, 0xf6684efd, 3 | BRF_GRA },
	{ "xvs.15m",      0x400000, 0x29109221, 3 | BRF_GRA },
	{ "xvs.17m",      0x400000, 0x92db3474, 3 | BRF_GRA },
	{ "xvs.19m",      0x400000, 0x3733473c, 3 | BRF_GRA },
	{ "xvs.14m",      0x400000, 0xbcac2e41, 3 | BRF_GRA },
	{ "xvs.16m",      0x400000, 0xea04a272, 3 | BRF_GRA },
	{ "xvs.18m",      0x400000, 0xb0def86a, 3 | BRF_GRA },
	{ "xvs.20m",      0x400000, 0x4b40ff9f, 3 | BRF_GRA },

	{ "xvs.01",       0x020000, 0x3999e93a, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "xvs.02",       0x020000, 0x101bdee9, 4 | BRF_ESS | BRF_PRG },

	{ "xvs.11m",      0x200000, 0x9cadcdbc, 5 | BRF_SND },
	{ "xvs.12m",      0x200000, 0x7b11e460, 5 | BRF_SND },
};

STD_ROM_PICK(Xmvsfjr2) STD_ROM_FN(Xmvsfjr2)

struct BurnDriver BurnDrvCpsXmvsfjr2 = {
	"xmvsfjr2", "xmvsf", NULL, "1996",
	"X-Men vs Street Fighter (Japan 960909)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Xmvsfjr2RomInfo, Xmvsfjr2RomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// X-Men vs Street Fighter (Asia 961023)

static struct BurnRomInfo XmvsfaRomDesc[] = {
	{ "xvsa.03",      0x080000, 0xd0cca7a8, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "xvsa.04",      0x080000, 0x8c8e76fd, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.05a",      0x080000, 0x7db6025d, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.06a",      0x080000, 0xe8e2c75c, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.07",       0x080000, 0x08f0abed, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.08",       0x080000, 0x81929675, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.09",       0x080000, 0x9641f36b, 1 | BRF_ESS | BRF_PRG },

	{ "xvs.13m",      0x400000, 0xf6684efd, 3 | BRF_GRA },
	{ "xvs.15m",      0x400000, 0x29109221, 3 | BRF_GRA },
	{ "xvs.17m",      0x400000, 0x92db3474, 3 | BRF_GRA },
	{ "xvs.19m",      0x400000, 0x3733473c, 3 | BRF_GRA },
	{ "xvs.14m",      0x400000, 0xbcac2e41, 3 | BRF_GRA },
	{ "xvs.16m",      0x400000, 0xea04a272, 3 | BRF_GRA },
	{ "xvs.18m",      0x400000, 0xb0def86a, 3 | BRF_GRA },
	{ "xvs.20m",      0x400000, 0x4b40ff9f, 3 | BRF_GRA },

	{ "xvs.01",       0x020000, 0x3999e93a, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "xvs.02",       0x020000, 0x101bdee9, 4 | BRF_ESS | BRF_PRG },

	{ "xvs.11m",      0x200000, 0x9cadcdbc, 5 | BRF_SND },
	{ "xvs.12m",      0x200000, 0x7b11e460, 5 | BRF_SND },
};

STD_ROM_PICK(Xmvsfa) STD_ROM_FN(Xmvsfa)

struct BurnDriver BurnDrvCpsXmvsfa = {
	"xmvsfa", "xmvsf", NULL, "1996",
	"X-Men vs Street Fighter (Asia 961023)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, XmvsfaRomInfo, XmvsfaRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// X-Men vs Street Fighter (Asia 960919)

static struct BurnRomInfo Xmvsfar1RomDesc[] = {
	{ "xvsa.03e",     0x080000, 0x9bdde21c, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "xvsa.04e",     0x080000, 0x33300edf, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.05a",      0x080000, 0x7db6025d, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.06a",      0x080000, 0xe8e2c75c, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.07",       0x080000, 0x08f0abed, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.08",       0x080000, 0x81929675, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.09",       0x080000, 0x9641f36b, 1 | BRF_ESS | BRF_PRG },

	{ "xvs.13m",      0x400000, 0xf6684efd, 3 | BRF_GRA },
	{ "xvs.15m",      0x400000, 0x29109221, 3 | BRF_GRA },
	{ "xvs.17m",      0x400000, 0x92db3474, 3 | BRF_GRA },
	{ "xvs.19m",      0x400000, 0x3733473c, 3 | BRF_GRA },
	{ "xvs.14m",      0x400000, 0xbcac2e41, 3 | BRF_GRA },
	{ "xvs.16m",      0x400000, 0xea04a272, 3 | BRF_GRA },
	{ "xvs.18m",      0x400000, 0xb0def86a, 3 | BRF_GRA },
	{ "xvs.20m",      0x400000, 0x4b40ff9f, 3 | BRF_GRA },

	{ "xvs.01",       0x020000, 0x3999e93a, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "xvs.02",       0x020000, 0x101bdee9, 4 | BRF_ESS | BRF_PRG },

	{ "xvs.11m",      0x200000, 0x9cadcdbc, 5 | BRF_SND },
	{ "xvs.12m",      0x200000, 0x7b11e460, 5 | BRF_SND },
};

STD_ROM_PICK(Xmvsfar1) STD_ROM_FN(Xmvsfar1)

struct BurnDriver BurnDrvCpsXmvsfar1 = {
	"xmvsfar1", "xmvsf", NULL, "1996",
	"X-Men vs Street Fighter (Asia 960919)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, Xmvsfar1RomInfo, Xmvsfar1RomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// X-Men vs Street Fighter (Hispanic 961004)

static struct BurnRomInfo XmvsfhRomDesc[] = {
	{ "xvsh.03a",     0x080000, 0xd4fffb04, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "xvsh.04a",     0x080000, 0x1b4ea638, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.05a",      0x080000, 0x7db6025d, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.06a",      0x080000, 0xe8e2c75c, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.07",       0x080000, 0x08f0abed, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.08",       0x080000, 0x81929675, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.09",       0x080000, 0x9641f36b, 1 | BRF_ESS | BRF_PRG },

	{ "xvs.13m",      0x400000, 0xf6684efd, 3 | BRF_GRA },
	{ "xvs.15m",      0x400000, 0x29109221, 3 | BRF_GRA },
	{ "xvs.17m",      0x400000, 0x92db3474, 3 | BRF_GRA },
	{ "xvs.19m",      0x400000, 0x3733473c, 3 | BRF_GRA },
	{ "xvs.14m",      0x400000, 0xbcac2e41, 3 | BRF_GRA },
	{ "xvs.16m",      0x400000, 0xea04a272, 3 | BRF_GRA },
	{ "xvs.18m",      0x400000, 0xb0def86a, 3 | BRF_GRA },
	{ "xvs.20m",      0x400000, 0x4b40ff9f, 3 | BRF_GRA },

	{ "xvs.01",       0x020000, 0x3999e93a, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "xvs.02",       0x020000, 0x101bdee9, 4 | BRF_ESS | BRF_PRG },

	{ "xvs.11m",      0x200000, 0x9cadcdbc, 5 | BRF_SND },
	{ "xvs.12m",      0x200000, 0x7b11e460, 5 | BRF_SND },
};

STD_ROM_PICK(Xmvsfh) STD_ROM_FN(Xmvsfh)

struct BurnDriver BurnDrvCpsXmvsfh = {
	"xmvsfh", "xmvsf", NULL, "1996",
	"X-Men vs Street Fighter (Hispanic 961004)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, XmvsfhRomInfo, XmvsfhRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// X-Men vs Street Fighter (Brazil 961023)

static struct BurnRomInfo XmvsfbRomDesc[] = {
	{ "xvsb.03h",     0x080000, 0x05baccca, 1 | BRF_ESS | BRF_PRG },	// 68k program
	{ "xvsb.04h",     0x080000, 0xe350c755, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.05a",      0x080000, 0x7db6025d, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.06a",      0x080000, 0xe8e2c75c, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.07",       0x080000, 0x08f0abed, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.08",       0x080000, 0x81929675, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.09",       0x080000, 0x9641f36b, 1 | BRF_ESS | BRF_PRG },

	{ "xvs.13m",      0x400000, 0xf6684efd, 3 | BRF_GRA },
	{ "xvs.15m",      0x400000, 0x29109221, 3 | BRF_GRA },
	{ "xvs.17m",      0x400000, 0x92db3474, 3 | BRF_GRA },
	{ "xvs.19m",      0x400000, 0x3733473c, 3 | BRF_GRA },
	{ "xvs.14m",      0x400000, 0xbcac2e41, 3 | BRF_GRA },
	{ "xvs.16m",      0x400000, 0xea04a272, 3 | BRF_GRA },
	{ "xvs.18m",      0x400000, 0xb0def86a, 3 | BRF_GRA },
	{ "xvs.20m",      0x400000, 0x4b40ff9f, 3 | BRF_GRA },

	{ "xvs.01",       0x020000, 0x3999e93a, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "xvs.02",       0x020000, 0x101bdee9, 4 | BRF_ESS | BRF_PRG },

	{ "xvs.11m",      0x200000, 0x9cadcdbc, 5 | BRF_SND },
	{ "xvs.12m",      0x200000, 0x7b11e460, 5 | BRF_SND },
};

STD_ROM_PICK(Xmvsfb) STD_ROM_FN(Xmvsfb)

struct BurnDriver BurnDrvCpsXmvsfb = {
	"xmvsfb", "xmvsf", NULL, "1996",
	"X-Men vs Street Fighter (Brazil 961023)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE,2,HARDWARE_CAPCOM_CPS2,
	NULL, XmvsfbRomInfo, XmvsfbRomName, DrvInputInfo, NULL,
	Cps2Init, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};


// X-Men vs. Street Fighter (USA 961004, Phoenix Edition)

static struct BurnRomInfo Xmvsfu1dRomDesc[] = {
	{ "xvsud.03h",    0x80000, 0x4e2e76b7, 1 | BRF_ESS | BRF_PRG },		// 68k program
	{ "xvsud.04h",    0x80000, 0x290c61a7, 1 | BRF_ESS | BRF_PRG },
	{ "xvsd.05a",     0x80000, 0xde347b11, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.06a",      0x80000, 0xe8e2c75c, 1 | BRF_ESS | BRF_PRG },
	{ "xvsd.07",      0x80000, 0xf761ded7, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.08",       0x80000, 0x81929675, 1 | BRF_ESS | BRF_PRG },
	{ "xvs.09",       0x80000, 0x9641f36b, 1 | BRF_ESS | BRF_PRG },

	{ "xvs.13m",      0x400000, 0xf6684efd, 3 | BRF_GRA },
	{ "xvs.15m",      0x400000, 0x29109221, 3 | BRF_GRA },
	{ "xvs.17m",      0x400000, 0x92db3474, 3 | BRF_GRA },
	{ "xvs.19m",      0x400000, 0x3733473c, 3 | BRF_GRA },
	{ "xvs.14m",      0x400000, 0xbcac2e41, 3 | BRF_GRA },
	{ "xvs.16m",      0x400000, 0xea04a272, 3 | BRF_GRA },
	{ "xvs.18m",      0x400000, 0xb0def86a, 3 | BRF_GRA },
	{ "xvs.20m",      0x400000, 0x4b40ff9f, 3 | BRF_GRA },

	{ "xvs.01",       0x020000, 0x3999e93a, 4 | BRF_ESS | BRF_PRG },	// z80 program
	{ "xvs.02",       0x020000, 0x101bdee9, 4 | BRF_ESS | BRF_PRG },

	{ "xvs.11m",      0x200000, 0x9cadcdbc, 5 | BRF_SND },
	{ "xvs.12m",      0x200000, 0x7b11e460, 5 | BRF_SND },
};

STD_ROM_PICK(Xmvsfu1d) STD_ROM_FN(Xmvsfu1d)

struct BurnDriver BurnDrvCpsXmvsfu1d = {
	"xmvsfu1d", "xmvsf", NULL, "1996",
	"X-Men vs. Street Fighter (USA 961004, Phoenix Edition)\0", NULL, "Capcom", "CPS2",
	NULL, NULL, NULL, NULL,
	BDF_GAME_WORKING | BDF_CLONE | BDF_BOOTLEG,2,HARDWARE_CAPCOM_CPS2,
	NULL, Xmvsfu1dRomInfo, Xmvsfu1dRomName, DrvInputInfo, NULL,
	PhoenixInit, CpsExit,Cps2Frame,Cps2Redraw,CpsAreaScan,
	&CpsRecalcPal,384,224,4,3
};

