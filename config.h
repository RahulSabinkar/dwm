/* See LICENSE file for copyright and license details. */
#define BROWSER "firefox"
#define TERMINAL "st"
/* appearance */
static const unsigned int borderpx  = 3;  /* border pixel of windows */
static const unsigned int snap      = 32; /* snap pixel */
static const unsigned int gappih    = 0; /* horiz inner gap between windows */
static const unsigned int gappiv    = 0; /* vert inner gap between windows */
static const unsigned int gappoh    = 0; /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 0; /* vert outer gap between windows and screen edge */
static const int smartgaps          = 0;  /* 1 means no outer gap when there is only one window */
/* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systraypinning = 0;
static const unsigned int systrayspacing = 2; /* systray spacing */
/* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int systraypinningfailfirst = 1;
static const int showsystray        = 1; /* 0 means no systray */
static const int swallowfloating    = 0; /* 1 means swallow floating windows by default */
static const int showbar            = 1; /* 0 means no bar */
static const int topbar             = 1; /* 0 means bottom bar */
static const int vertpad            = 0; /* vertical padding of bar */
static const int sidepad            = 0; /* horizontal padding of bar */
static const char *fonts[]          = {
    /* For normal text */
    "JetBrainsMono:size=10",
    /* For Font Awesome Icons */
    "Font Awesome 6 Free Solid:style=Solid:pixelsize=14:antialiasing=true:autohint=true",
    "Font Awesome 6 Brands:style=Regular:pixelsize=14:antialiasing=true:autohint=true",
    "Font Awesome 6 Regular:style=Regular:pixelsize=14:antialiasing=true:autohint=true",
    /* For Nerd Icons */
    /* "SauceCodePro Nerd Font:size=10" */
    /* For Emojis */
    "JoyPixels:pixelsize=14:antialias=true:autohint=true"
};
static const char dmenufont[]       = "JetBrainsMono:size=12";
    /* "SauceCodePro Nerd Font:style=Semibold:size=10:autohint=true"; */
    /* "Hack Nerd Font:pixelsize=14:antialias=true:autohint=true"; */
	/* "JoyPixels:pixelsize=16:antialias=true:autohint=true"; */
 /* background color */
static const char col_gray1[]       = "#222222";
 /* inactive window border color */
static const char col_gray2[]       = "#444444";
 /* font color */
static const char col_gray3[]       = "#bbbbbb";
 /* current tag and current window color */
static const char col_gray4[]       = "#eeeeee";
 /* top bar second color (blue) */
 /* static const char col_cyan[]        = "#005577"; */
/* static const char col_cyan[]        = "#3B7DCB"; */
static const char col_cyan[]        = "#2962FF";
 /* active window border color */
 /* static const char col_red[]         = "#fc0303"; */
/* static const char col_red[]         = "#3B7DCB"; */
static const char col_red[]         = "#2962FF";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_red   },
};

/* tagging */
static const char *tags[] = { "", "", "", "", "", "", "", "", "" };
/* static const char *tags[] = { "", "", "", "", "", "", "", "", "" }; */
/* static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" }; */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class            instance  title           tags mask  isfloating  isterminal  noswallow  monitor */
	{ "Gimp",           NULL,     NULL,           0,         1,          0,           0,        -1 },
	{ "LibreWolf",      NULL,     NULL,           1,         0,          0,          -1,        -1 },
	{ "firefox",        NULL,     NULL,           1,         0,          0,          -1,        -1 },
	{ "Brave-browser",  NULL,     NULL,           1,         0,          0,          -1,        -1 },
	{ "Code",           NULL,     NULL,           1 << 2,    0,          0,          -1,        -1 },
	{ "notion-app",     NULL,     NULL,           1 << 4,    0,          0,          -1,        -1 },
	{ "qBittorrent",    NULL,     NULL,           1 << 5,    0,          0,          -1,        -1 },
	{ "Signal",         NULL,     NULL,           1 << 6,    0,          0,          -1,        -1 },
	{ "Mailspring",     NULL,     NULL,           1 << 6,    0,          0,          -1,        -1 },
	/* { "TelegramDesktop",NULL,     NULL,           1 << 7,    0,          0,          -1,        -1 }, */
	{ "Spotify",        "spotify",     "Spotify",           1 << 7,    0,          0,          -1,        -1 },
	{ "discord",        NULL,     NULL,           1 << 8,    0,          0,          -1,        -1 },
	{ "Ranger",         NULL,     NULL,           0,         0,          1,           0,        -1 },
	{ "St",             NULL,     NULL,           0,         0,          1,           0,        -1 },
	{ NULL,             NULL,     "ranger",       0,         0,          1,           0,        -1 },
	{ "Terminator",     NULL,     NULL,           0,         0,          1,           0,        -1 },
	{ NULL,             NULL,    "Event Tester",  0,         0,          0,           1,        -1 }, /* xev */
};


/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
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

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *roficmd[] = { "rofi", "-show", "drun", NULL };
static const char *dmenucmd[] = {
    "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3,
    "-sb", col_cyan, "-sf", col_gray4, NULL
};
static const char *clipmenucmd[] = {
    "clipmenu", "-i", "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3,
    "-sb", col_cyan, "-sf", col_gray4, NULL
};
static const char *termcmd[]  = { TERMINAL, NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "60x15", NULL };
static const char color_picker[] = "gpick -s -o | xclip -selection clipboard";
/* notification keybindings */
static const char *dunst_close[] = { "dunstctl", "close", NULL};
static const char *dunst_close_all[] = { "dunstctl", "close-all", NULL};
static const char *dunst_history[] = { "dunstctl", "history-pop", NULL};
/* dwmblocks setup */
static const char dwmblocks_config[] = TERMINAL " -e nvim $HOME/.config/dwmblocks/config.h";
static const char volume_toggle_mute[] = "pamixer -t; kill -44 $(pidof dwmblocks)";
static const char volume_down_5[] = "pamixer --allow-boost -d 5; kill -44 $(pidof dwmblocks)";
static const char volume_down_15[] = "pamixer --allow-boost -d 15; kill -44 $(pidof dwmblocks)";
static const char volume_up_5[] = "pamixer --allow-boost -i 5; kill -44 $(pidof dwmblocks)";
static const char volume_up_15[] = "pamixer --allow-boost -i 15; kill -44 $(pidof dwmblocks)";
/* screenshot scripts */
static const char screenshot_full[] =
    "dir=~/media/pictures/screenshots/screenshot-$(date '+%y-%m-%d-%H:%M:%S').png;"
    "maim $dir;"
    "cat $dir | xclip -selection clipboard -t image/png;"
    "notify-send 'Full screenshot taken' "
    "'Stored in ~/media/pictures/screenshots\nAlso copied to clipboard' -i \"$dir\"";
static const char screenshot_window[] =
    "dir=~/media/pictures/screenshots/screenshot-$(date '+%y-%m-%d-%H:%M:%S').png;"
    "maim -i $(xdotool getactivewindow) $dir;"
    "cat $dir | xclip -selection clipboard -t image/png;"
    "notify-send 'Screenshot of window taken' "
    "'Stored in ~/media/pictures/screenshots\nAlso copied to clipboard' -i \"$dir\"";
static const char screenshot_select_save[] =
    "dir=~/media/pictures/screenshots/screenshot-$(date '+%y-%m-%d-%H:%M:%S').png;"
    "maim -u -s $dir;"
    "notify-send 'Selected Screenshot Taken' 'Stored in ~/media/pictures/screenshots' -i \"$dir\"";
static const char screenshot_select_copy[] =
    "dir=/tmp/selected-screenshot.png;"
    "maim -u -s $dir;"
    "cat $dir | xclip -selection clipboard -t image/png;"
    "notify-send 'Copied Screenshot to Clipboard' -i \"$dir\"";
/* screenlock */
static const char screen_lock[] = "slock & xset dpms force off";
#include <X11/XF86keysym.h>
#include "shiftview.c"
static Key keys[] = {
	/* modifier                     key        function        argument */
	/* { MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } }, */
	{ MODKEY,                       XK_d,      spawn,          {.v = roficmd } },
	{ MODKEY,                       XK_grave,  spawn,          SHCMD("dmenuunicode") },
	{ MODKEY,                       XK_c,      spawn,          {.v = clipmenucmd } },
	{ MODKEY,   	                XK_Return, spawn,          {.v = termcmd } },
	{ 0,                            XK_F12,    togglescratch,  {.v = scratchpadcmd } },
	{ MODKEY,   	                XK_w,      spawn,          SHCMD (BROWSER) },
	{ MODKEY|ALTKEY,                XK_f,      spawn,          SHCMD ("firefox") },
	{ MODKEY|ALTKEY,                XK_p,      spawn,          SHCMD ("librewolf -p private") },
	{ MODKEY|ALTKEY,                XK_b,      spawn,          SHCMD ("brave") },
	{ MODKEY|ALTKEY,                XK_c,      spawn,          SHCMD ("chromium") },
	{ MODKEY,   	                XK_s,      spawn,          SHCMD ("signal-desktop") },
	{ MODKEY,   	                XK_e,      spawn,          SHCMD ("pcmanfm") },
	{ MODKEY,   	                XK_r,      spawn,          SHCMD (TERMINAL " -e ranger") },
	{ MODKEY|ALTKEY,                 XK_h,      spawn,          SHCMD (TERMINAL " -e htop") },
	/* { MODKEY,   	                XK_t,      spawn,          SHCMD ("xfce4-taskmanager") }, */
	{ MODKEY|ALTKEY,                XK_i,      spawn,          SHCMD ("$HOME/intellij/bin/idea.sh") },
	{ ALTKEY,   	                XK_x,      spawn,          SHCMD ("xkill") },
	{ MODKEY,                    XK_BackSpace, spawn,          SHCMD("sysact") },
	{ MODKEY|ShiftMask,             XK_n,      spawn,          SHCMD(TERMINAL " -e sudo nmtui") },
	{ MODKEY,                       XK_t,      togglebar,      {0} },
    { MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
    { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_u,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
    { MODKEY|ALTKEY,                XK_equal,  incrgaps,       {.i = +1 } },
	{ MODKEY|ALTKEY,                XK_minus,  incrgaps,       {.i = -1 } },
	{ MODKEY|ALTKEY,                XK_plus,   defaultgaps,    {0} },
	{ MODKEY|ALTKEY,                XK_0,      togglegaps,     {0} },
	/* { MODKEY|Mod4Mask|ShiftMask,    XK_h,      incrogaps,      {.i = +1 } }, */
	/* { MODKEY|Mod4Mask|ShiftMask,    XK_l,      incrogaps,      {.i = -1 } }, */
	/* { MODKEY|Mod4Mask|ControlMask,  XK_h,      incrigaps,      {.i = +1 } }, */
	/* { MODKEY|Mod4Mask|ControlMask,  XK_l,      incrigaps,      {.i = -1 } }, */
	/* { MODKEY,                       XK_y,      incrihgaps,     {.i = +1 } }, */
	/* { MODKEY,                       XK_o,      incrihgaps,     {.i = -1 } }, */
	/* { MODKEY|ControlMask,           XK_y,      incrivgaps,     {.i = +1 } }, */
	/* { MODKEY|ControlMask,           XK_o,      incrivgaps,     {.i = -1 } }, */
	/* { MODKEY|Mod4Mask,              XK_y,      incrohgaps,     {.i = +1 } }, */
	/* { MODKEY|Mod4Mask,              XK_o,      incrohgaps,     {.i = -1 } }, */
	/* { MODKEY|ShiftMask,             XK_y,      incrovgaps,     {.i = +1 } }, */
	/* { MODKEY|ShiftMask,             XK_o,      incrovgaps,     {.i = -1 } }, */
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,             XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ShiftMask,             XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_n,      shiftview,      {.i = +1 } },
	{ MODKEY,                       XK_b,      shiftview,      {.i = -1 } },
	{ MODKEY,                       XK_g,      spawn,          SHCMD(color_picker) },
	{ MODKEY,                       XK_y,      spawn,          SHCMD("yt-stream") },
    { ALTKEY,                       XK_minus,  spawn,          SHCMD(volume_down_5) },
    { ALTKEY|ShiftMask,             XK_minus,  spawn,	       SHCMD(volume_down_15) },
	{ ALTKEY,                       XK_equal,  spawn,	       SHCMD(volume_up_5) },
	{ ALTKEY|ShiftMask,             XK_equal,  spawn,	       SHCMD(volume_up_15) },
	{ 0,				            XK_Print,  spawn,		   SHCMD(screenshot_full) },
	{ ShiftMask,			        XK_Print,  spawn,	   	   SHCMD(screenshot_window) },
	{ ControlMask,			        XK_Print,  spawn,		   SHCMD(screenshot_select_save) },
	{ ControlMask|ShiftMask,	    XK_Print,  spawn,		   SHCMD(screenshot_select_copy) },
	{ ControlMask|MODKEY,	        XK_Print,  spawn,		   SHCMD("maimpick") },
	{ MODKEY,                       XK_F12,    spawn,          SHCMD(screen_lock) },
	{ ALTKEY,                       XK_0,      spawn,          SHCMD(volume_toggle_mute) },
	{ 0,                      XF86XK_HomePage, spawn,          SHCMD(screen_lock) },
	{ 0,                     XF86XK_AudioMute, spawn,          SHCMD(volume_toggle_mute) },
	{ 0,              XF86XK_AudioRaiseVolume, spawn,          SHCMD(volume_up_5) },
	{ 0,              XF86XK_AudioLowerVolume, spawn,          SHCMD(volume_down_5) },
	{ ControlMask,                  XK_space,  spawn,          {.v = dunst_close} },
	{ ControlMask|ShiftMask,        XK_space,  spawn,          {.v = dunst_close_all} },
	{ ControlMask,                  XK_grave,  spawn,          {.v = dunst_history} },
	{ MODKEY,                       XK_c,      spawn,          {.v = clipmenucmd } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
	{ ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
	{ ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
	{ ClkStatusText,        0,              Button4,        sigdwmblocks,   {.i = 4} },
	{ ClkStatusText,        0,              Button5,        sigdwmblocks,   {.i = 5} },
	{ ClkStatusText,        ShiftMask,      Button1,        sigdwmblocks,   {.i = 6} },
	{ ClkStatusText,        ShiftMask,      Button3,        spawn,          SHCMD(dwmblocks_config) },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,    		0,	        	Button4,    	shiftview,  	{.i = -1} },
	{ ClkTagBar,    		0,	        	Button5,    	shiftview,  	{.i = 1} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
