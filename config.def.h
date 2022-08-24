/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 5;        /* horiz inner gap between windows */
static const unsigned int gappiv    = 5;        /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft  = 0;   /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;        /* 0 means no systray */
static const int swallowfloating    = 0;        /* 1 means swallow floating windows by default */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int user_bh            = 24;       /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
static const int focusonwheel       = 0;
static const int use_last_kb		= 0;
static const char *fonts[]          = { "Ubuntu Mono:size=12", "SauceCodePro Nerd Font Mono:size=16:antialias=true:autohint=true", "Noto Color Emoji:pixelsize=14:antialias=true:autohint=true" };
static const char dmenufont[]       = "monospace:size=10";
static char normbgcolor[]           = "#282828";
static char normbordercolor[]       = "#282828";
static char normfgcolor[]           = "#928374";
static char selfgcolor[]            = "#458588";
static char selbordercolor[]        = "#ebdbb2";
static char selbgcolor[]            = "#282828";
static char termcol0[]              = "#282828"; /* Black   */
static char termcol1[]              = "#cc241d"; /* red     */
static char termcol2[]              = "#98971a"; /* green   */
static char termcol3[]              = "#d79921"; /* yellow  */
static char termcol4[]              = "#458588"; /* blue    */
static char termcol5[]              = "#b16286"; /* magenta */
static char termcol6[]              = "#689d6a"; /* cyan    */
static char termcol7[]              = "#a89984"; /* white   */
static char termcol8[]              = "#928374"; /* black   */
static char termcol9[]              = "#fb4934"; /* red     */
static char termcol10[]             = "#b8bb26"; /* green   */
static char termcol11[]             = "#fabd2f"; /* yellow  */
static char termcol12[]             = "#83a598"; /* blue    */
static char termcol13[]             = "#d3869b"; /* magenta */
static char termcol14[]             = "#8ec07c"; /* cyan    */
static char termcol15[]             = "#ebdbb2"; /* white   */
static char *termcolor[] = {
  termcol0,
  termcol1,
  termcol2,
  termcol3,
  termcol4,
  termcol5,
  termcol6,
  termcol7,
  termcol8,
  termcol9,
  termcol10,
  termcol11,
  termcol12,
  termcol13,
  termcol14,
  termcol15,
};
static char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};

/* tagging */
static const char *tags[] = { "", "", "", "嗢", "", "", "", "", "" };
static const char *ntags[] = { "₁", "₂", "₃", "₄", "₅", "₆", "₇", "₈", "₉" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class                instance                    title               tags mask     isfloating   isterminal  noswallow   monitor */
	{ "Alacritty",          NULL,                       NULL,               0,            0,           1,          0,          -1 },
	{ "mpv",                NULL,                       NULL,               0,            1,           0,          0,          -1 },
	{ "Shotwell",           NULL,                       NULL,               0,            1,           0,          0,          -1 },
	{ "Arandr",             NULL,                       NULL,               0,            1,           0,          0,          -1 },
	{ "Sxiv",               NULL,                       NULL,               0,            1,           0,          0,          -1 },
	{ "Tor Browser",        NULL,                       NULL,               0,            1,           0,          0,          -1 },
	{ "Pavucontrol",        NULL,                       NULL,               0,            1,           0,          0,          -1 },
	{ "Bijiben",            NULL,                       NULL,               0,            1,           0,          0,          -1 },
	{ "floating",           NULL,                       NULL,               0,            1,           0,          0,          -1 },
	{ NULL,                 "floating",                 NULL,               0,            1,           0,          0,          -1 },
	{ NULL,                 "qalculate-gtk",            NULL,               0,            1,           0,          0,          -1 },
	{ NULL,                 "keepassxc",                NULL,               0,            1,           0,          0,          -1 },
	{ NULL,                 "gedit",                    NULL,               0,            1,           0,          0,          -1 },
	{ NULL,                 "nm-connection-editor",     NULL,               0,            1,           0,          0,          -1 },
	{ NULL,                 "telegram-desktop",         NULL,               1 << 2,       0,           0,          0,          -1 },
	{ NULL,                 NULL,                       "Event Tester",     0,            1,           0,          1,          -1 },
};

/* layout(s) */
static const float mfact        = 0.65; /* factor of master area size [0.05..0.95] */
static const int nmaster        = 1;    /* number of clients in master area */
static const int resizehints    = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1;    /* 1 will force focus on the fullscreen window */
static const int attachbelow    = 1;    /* 1 means attach after the currently active window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "[M]",      monocle },
	{ "TTT",      bstack },
	{ "###",      nrowgrid },
	{ "|M|",      centeredmaster },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
};

/* key definitions */
#define MODKEY Mod4Mask
#define ALTKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

#define STATUSBAR "dwmblocks"

/* commands */
static char dmenumon[2]            = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]      = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", normbgcolor, "-nf", normfgcolor, "-sb", selbordercolor, "-sf", selfgcolor, NULL };
static const char *clipmenucmd[]   = { "clipmenu", NULL };
static const char *termcmd[]       = { "alacritty", NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "alacritty", "-t", "scratchpad", "-e", "nano", "/tmp/scratchpad", NULL };

static Key keys[] = {
	/* modifier                     key                        function        argument */

	/* applications */
	{ MODKEY,                       XK_r,                      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_y,                      spawn,          {.v = clipmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return,                 spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_grave,                  togglescratch,  {.v = scratchpadcmd } },
	{ MODKEY,                       XK_w,                      spawn,          SHCMD("$BROWSER") },
	{ MODKEY,                       XK_f,                      spawn,          SHCMD("$FILEMANAGER") },
	{ MODKEY,                       XK_c,                      spawn,          SHCMD("qalculate-gtk") },
	{ MODKEY,                       XK_g,                      spawn,          SHCMD("gedit") },

	/* system commands */
	{ ALTKEY,                       XK_F1,                     spawn,          SHCMD("rofr.sh -r") },
	{ MODKEY,                       XK_Escape,                 spawn,          SHCMD("rofr.sh -l") },
	{ MODKEY,                       XK_p,                      spawn,          SHCMD("scrot 'screenshot_%Y%m%d-%H%M%S_$wx$h.png' -e 'mv $f $HOME/'") },	
	{ 0,                            XK_Print,                  spawn,          SHCMD("scrot 'screenshot_%Y%m%d-%H%M%S_$wx$h.png' -e 'mv $f $HOME/'") },	
	{ 0,                            XF86XK_TouchpadToggle,     spawn,          SHCMD("toggle_touchpad") },
	{ 0,                            XF86XK_MonBrightnessUp,    spawn,          SHCMD("xbacklight -inc 5") },
	{ 0,                            XF86XK_MonBrightnessDown,  spawn,          SHCMD("xbacklight -dec 5") },
	{ 0,                            XF86XK_AudioRaiseVolume,   spawn,          SHCMD("pactl set-sink-volume @DEFAULT_SINK@ +5% ; pkill -RTMIN+1 dwmblocks") },
	{ 0,                            XF86XK_AudioLowerVolume,   spawn,          SHCMD("pactl set-sink-volume @DEFAULT_SINK@ -5% ; pkill -RTMIN+1 dwmblocks") },
	{ 0,                            XF86XK_AudioMute,          spawn,          SHCMD("pactl set-sink-mute @DEFAULT_SINK@ toggle ; pkill -RTMIN+1 dwmblocks") },

	/* dwm commands */
	{ MODKEY,                       XK_b,                      togglebar,      {0} },
	{ MODKEY,                       XK_F5,                     xrdb,           {.v = NULL } },
	{ MODKEY|ShiftMask,             XK_q,                      quit,           {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_q,                      quit,           {1} },

	/* client commands */
	{ ALTKEY,                       XK_Tab,                    focusstack,     {.i = PREVSEL } },
	{ MODKEY,                       XK_j,                      focusstack,     {.i = INC(+1) } },
	{ MODKEY,                       XK_k,                      focusstack,     {.i = INC(-1) } },
	{ MODKEY|ShiftMask,             XK_j,                      pushstack,      {.i = INC(+1) } },
	{ MODKEY|ShiftMask,             XK_k,                      pushstack,      {.i = INC(-1) } },
	{ MODKEY,                       XK_equal,                  incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_minus,                  incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_bracketleft,            setmfact,       {.f = -0.02} },
	{ MODKEY,                       XK_bracketright,           setmfact,       {.f = +0.02} },
	{ MODKEY,                       XK_Return,                 zoom,           {0} },
	{ MODKEY|ShiftMask,             XK_space,                  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_c,                      killclient,     {0} },
	{ ALTKEY,                       XK_F4,                     killclient,     {0} },

	/* layout commands */
	{ MODKEY,                       XK_t,                      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_space,                  nextlayout,     {0} },
	{ MODKEY|ShiftMask,             XK_f,                      togglefullscr,  {0} },

	/* tag commands */
	{ MODKEY,                       XK_Right,                  shiftview,      {.i = +1 } },
	{ MODKEY,                       XK_Left,                   shiftview,      {.i = -1 } },
	{ MODKEY,                       XK_Tab,                    view,           {0} },
	{ MODKEY,                       XK_0,                      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,                      tag,            {.ui = ~0 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)

	/* monitor commands */
	{ MODKEY,                       XK_comma,                  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period,                 focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,                  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,                 tagmon,         {.i = +1 } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        nextlayout,     {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[LENGTH(layouts) - 2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigstatusbar,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigstatusbar,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigstatusbar,   {.i = 3} },
	{ ClkStatusText,        0,              Button4,        sigstatusbar,   {.i = 4} },
	{ ClkStatusText,        0,              Button5,        sigstatusbar,   {.i = 5} },
	{ ClkStatusText,        ShiftMask,      Button1,        sigstatusbar,   {.i = 6} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
