VERSION 5.00
Object = "{648A5603-2C6E-101B-82B6-000000000014}#1.1#0"; "MSCOMM32.OCX"
Begin VB.Form Form1 
   BorderStyle     =   3  'Fixed Dialog
   Caption         =   "Bunka"
   ClientHeight    =   7725
   ClientLeft      =   45
   ClientTop       =   435
   ClientWidth     =   19770
   BeginProperty Font 
      Name            =   "宋体"
      Size            =   21.75
      Charset         =   134
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   Icon            =   "Form1.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   Picture         =   "Form1.frx":08CA
   ScaleHeight     =   7725
   ScaleWidth      =   19770
   ShowInTaskbar   =   0   'False
   StartUpPosition =   2  '屏幕中心
   Begin VB.Frame Frame5 
      Caption         =   "Receiver ADF7021"
      Height          =   7455
      Left            =   13440
      TabIndex        =   44
      Top             =   0
      Width           =   6255
      Begin VB.TextBox Text5 
         BackColor       =   &H00FFFFFF&
         Enabled         =   0   'False
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   14.25
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H00FFFFFF&
         Height          =   6435
         Left            =   5350
         MultiLine       =   -1  'True
         TabIndex        =   111
         Top             =   240
         Width           =   810
      End
      Begin VB.ComboBox Combo3 
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   330
         Index           =   4
         ItemData        =   "Form1.frx":0910
         Left            =   240
         List            =   "Form1.frx":0920
         TabIndex        =   109
         Text            =   "Tx CARRIER ONLY"
         Top             =   840
         Width           =   2175
      End
      Begin VB.CommandButton Command11 
         Caption         =   "reset"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   12
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   435
         Left            =   0
         TabIndex        =   108
         Top             =   6960
         Width           =   855
      End
      Begin VB.CommandButton Command10 
         Caption         =   "write"
         Height          =   495
         Left            =   3720
         TabIndex        =   107
         Top             =   6720
         Width           =   1335
      End
      Begin VB.CommandButton Command9 
         Caption         =   "read"
         Height          =   495
         Left            =   1800
         TabIndex        =   106
         Top             =   6720
         Width           =   1215
      End
      Begin VB.Frame Frame6 
         Caption         =   "Updata Registers(0x)--Design special"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   4575
         Left            =   240
         TabIndex        =   53
         Top             =   2040
         Width           =   5055
         Begin VB.CommandButton CommandR 
            Caption         =   "Updata"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   15
            Left            =   3720
            TabIndex        =   101
            Top             =   4155
            Width           =   1095
         End
         Begin VB.TextBox TextR 
            Alignment       =   2  'Center
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   15
            Left            =   3720
            MaxLength       =   8
            TabIndex        =   100
            Top             =   3765
            Width           =   1095
         End
         Begin VB.CommandButton CommandR 
            Caption         =   "Updata"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   14
            Left            =   2520
            TabIndex        =   99
            Top             =   4155
            Width           =   1095
         End
         Begin VB.TextBox TextR 
            Alignment       =   2  'Center
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   14
            Left            =   2520
            MaxLength       =   8
            TabIndex        =   98
            Top             =   3765
            Width           =   1095
         End
         Begin VB.TextBox TextR 
            Alignment       =   2  'Center
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   13
            Left            =   1320
            MaxLength       =   8
            TabIndex        =   97
            Top             =   3765
            Width           =   1095
         End
         Begin VB.CommandButton CommandR 
            Caption         =   "Updata"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   13
            Left            =   1320
            TabIndex        =   96
            Top             =   4155
            Width           =   1095
         End
         Begin VB.TextBox TextR 
            Alignment       =   2  'Center
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   12
            Left            =   120
            MaxLength       =   8
            TabIndex        =   95
            Top             =   3765
            Width           =   1095
         End
         Begin VB.CommandButton CommandR 
            Caption         =   "Updata"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   12
            Left            =   120
            TabIndex        =   94
            Top             =   4155
            Width           =   1095
         End
         Begin VB.CommandButton CommandR 
            Caption         =   "Updata"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   11
            Left            =   3720
            TabIndex        =   89
            Top             =   3075
            Width           =   1095
         End
         Begin VB.TextBox TextR 
            Alignment       =   2  'Center
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   11
            Left            =   3720
            MaxLength       =   8
            TabIndex        =   88
            Top             =   2685
            Width           =   1095
         End
         Begin VB.CommandButton CommandR 
            Caption         =   "Updata"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   10
            Left            =   2520
            TabIndex        =   87
            Top             =   3075
            Width           =   1095
         End
         Begin VB.TextBox TextR 
            Alignment       =   2  'Center
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   10
            Left            =   2520
            MaxLength       =   8
            TabIndex        =   86
            Top             =   2685
            Width           =   1095
         End
         Begin VB.TextBox TextR 
            Alignment       =   2  'Center
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   9
            Left            =   1320
            MaxLength       =   8
            TabIndex        =   85
            Top             =   2685
            Width           =   1095
         End
         Begin VB.CommandButton CommandR 
            Caption         =   "Updata"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   9
            Left            =   1320
            TabIndex        =   84
            Top             =   3075
            Width           =   1095
         End
         Begin VB.TextBox TextR 
            Alignment       =   2  'Center
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   8
            Left            =   120
            MaxLength       =   8
            TabIndex        =   83
            Top             =   2685
            Width           =   1095
         End
         Begin VB.CommandButton CommandR 
            Caption         =   "Updata"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   8
            Left            =   120
            TabIndex        =   82
            Top             =   3075
            Width           =   1095
         End
         Begin VB.CommandButton CommandR 
            Caption         =   "Updata"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   7
            Left            =   3720
            TabIndex        =   77
            Top             =   1995
            Width           =   1095
         End
         Begin VB.TextBox TextR 
            Alignment       =   2  'Center
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   7
            Left            =   3720
            MaxLength       =   8
            TabIndex        =   76
            Top             =   1605
            Width           =   1095
         End
         Begin VB.CommandButton CommandR 
            Caption         =   "Updata"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   6
            Left            =   2520
            TabIndex        =   75
            Top             =   1995
            Width           =   1095
         End
         Begin VB.TextBox TextR 
            Alignment       =   2  'Center
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   6
            Left            =   2520
            MaxLength       =   8
            TabIndex        =   74
            Top             =   1605
            Width           =   1095
         End
         Begin VB.TextBox TextR 
            Alignment       =   2  'Center
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   5
            Left            =   1320
            MaxLength       =   8
            TabIndex        =   73
            Top             =   1605
            Width           =   1095
         End
         Begin VB.CommandButton CommandR 
            Caption         =   "Updata"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   5
            Left            =   1320
            TabIndex        =   72
            Top             =   1995
            Width           =   1095
         End
         Begin VB.TextBox TextR 
            Alignment       =   2  'Center
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   4
            Left            =   120
            MaxLength       =   8
            TabIndex        =   71
            Top             =   1605
            Width           =   1095
         End
         Begin VB.CommandButton CommandR 
            Caption         =   "Updata"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   4
            Left            =   120
            TabIndex        =   70
            Top             =   1995
            Width           =   1095
         End
         Begin VB.CommandButton CommandR 
            Caption         =   "Updata"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   0
            Left            =   120
            TabIndex        =   61
            Top             =   915
            Width           =   1095
         End
         Begin VB.TextBox TextR 
            Alignment       =   2  'Center
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   0
            Left            =   120
            MaxLength       =   8
            TabIndex        =   60
            Top             =   525
            Width           =   1095
         End
         Begin VB.CommandButton CommandR 
            Caption         =   "Updata"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   1
            Left            =   1320
            TabIndex        =   59
            Top             =   915
            Width           =   1095
         End
         Begin VB.TextBox TextR 
            Alignment       =   2  'Center
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   1
            Left            =   1320
            MaxLength       =   8
            TabIndex        =   58
            Top             =   525
            Width           =   1095
         End
         Begin VB.TextBox TextR 
            Alignment       =   2  'Center
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   2
            Left            =   2520
            MaxLength       =   8
            TabIndex        =   57
            Top             =   525
            Width           =   1095
         End
         Begin VB.CommandButton CommandR 
            Caption         =   "Updata"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   2
            Left            =   2520
            TabIndex        =   56
            Top             =   915
            Width           =   1095
         End
         Begin VB.TextBox TextR 
            Alignment       =   2  'Center
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   3
            Left            =   3720
            MaxLength       =   8
            TabIndex        =   55
            Top             =   525
            Width           =   1095
         End
         Begin VB.CommandButton CommandR 
            Caption         =   "Updata"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   3
            Left            =   3720
            TabIndex        =   54
            Top             =   915
            Width           =   1095
         End
         Begin VB.Label Label10 
            Alignment       =   2  'Center
            Caption         =   "Register 15"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   255
            Index           =   15
            Left            =   3720
            TabIndex        =   105
            Top             =   3480
            Width           =   1215
         End
         Begin VB.Label Label10 
            Alignment       =   2  'Center
            Caption         =   "Register 14"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   255
            Index           =   14
            Left            =   2520
            TabIndex        =   104
            Top             =   3480
            Width           =   1215
         End
         Begin VB.Label Label10 
            Alignment       =   2  'Center
            Caption         =   "Register 13"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   255
            Index           =   13
            Left            =   1250
            TabIndex        =   103
            Top             =   3480
            Width           =   1335
         End
         Begin VB.Label Label10 
            Alignment       =   2  'Center
            Caption         =   "Register 12"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   255
            Index           =   12
            Left            =   20
            TabIndex        =   102
            Top             =   3480
            Width           =   1335
         End
         Begin VB.Label Label10 
            Alignment       =   2  'Center
            Caption         =   "Register 11"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   255
            Index           =   11
            Left            =   3720
            TabIndex        =   93
            Top             =   2400
            Width           =   1215
         End
         Begin VB.Label Label10 
            Alignment       =   2  'Center
            Caption         =   "Register 10"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   255
            Index           =   10
            Left            =   2520
            TabIndex        =   92
            Top             =   2400
            Width           =   1215
         End
         Begin VB.Label Label10 
            Alignment       =   2  'Center
            Caption         =   "Register 9"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   255
            Index           =   9
            Left            =   1320
            TabIndex        =   91
            Top             =   2400
            Width           =   1095
         End
         Begin VB.Label Label10 
            Alignment       =   2  'Center
            Caption         =   "Register 8"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   255
            Index           =   8
            Left            =   120
            TabIndex        =   90
            Top             =   2400
            Width           =   1095
         End
         Begin VB.Label Label10 
            Alignment       =   2  'Center
            Caption         =   "Register 7"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   255
            Index           =   7
            Left            =   3720
            TabIndex        =   81
            Top             =   1320
            Width           =   1095
         End
         Begin VB.Label Label10 
            Alignment       =   2  'Center
            Caption         =   "Register 6"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   255
            Index           =   6
            Left            =   2520
            TabIndex        =   80
            Top             =   1320
            Width           =   1095
         End
         Begin VB.Label Label10 
            Alignment       =   2  'Center
            Caption         =   "Register 5"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   255
            Index           =   5
            Left            =   1320
            TabIndex        =   79
            Top             =   1320
            Width           =   1095
         End
         Begin VB.Label Label10 
            Alignment       =   2  'Center
            Caption         =   "Register 4"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   255
            Index           =   4
            Left            =   120
            TabIndex        =   78
            Top             =   1320
            Width           =   1095
         End
         Begin VB.Label Label10 
            Alignment       =   2  'Center
            Caption         =   "Register 3"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   255
            Index           =   3
            Left            =   3720
            TabIndex        =   69
            Top             =   240
            Width           =   1095
         End
         Begin VB.Label Label10 
            Alignment       =   2  'Center
            Caption         =   "Register 2"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   255
            Index           =   2
            Left            =   2520
            TabIndex        =   68
            Top             =   240
            Width           =   1095
         End
         Begin VB.Label Label10 
            Alignment       =   2  'Center
            Caption         =   "Register 1"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            ForeColor       =   &H000000FF&
            Height          =   255
            Index           =   1
            Left            =   1320
            TabIndex        =   67
            Top             =   240
            Width           =   1095
         End
         Begin VB.Label Label10 
            Alignment       =   2  'Center
            Caption         =   "Register 0"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   255
            Index           =   0
            Left            =   120
            TabIndex        =   66
            Top             =   240
            Width           =   1095
         End
      End
      Begin VB.ComboBox Combo3 
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   330
         Index           =   3
         ItemData        =   "Form1.frx":095F
         Left            =   3600
         List            =   "Form1.frx":096F
         TabIndex        =   51
         Text            =   "Icp = 0.3mA"
         Top             =   840
         Width           =   1575
      End
      Begin VB.HScrollBar HScroll1 
         Height          =   300
         Index           =   2
         Left            =   1560
         Max             =   3
         TabIndex        =   45
         Top             =   1320
         Width           =   3615
      End
      Begin VB.Label Label3 
         Caption         =   "Tx/Rx Mode Select"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   270
         Index           =   7
         Left            =   240
         TabIndex        =   110
         Top             =   600
         Width           =   1935
      End
      Begin VB.Image Image3 
         Height          =   735
         Left            =   960
         Top             =   6645
         Width           =   735
      End
      Begin VB.Label Label3 
         Caption         =   "PLL Charge Pump"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   270
         Index           =   6
         Left            =   3600
         TabIndex        =   52
         Top             =   600
         Width           =   1575
      End
      Begin VB.Label Label6 
         Alignment       =   2  'Center
         Caption         =   "Setting 0"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H00FF0000&
         Height          =   255
         Index           =   2
         Left            =   2880
         TabIndex        =   50
         Top             =   1605
         Width           =   1335
      End
      Begin VB.Label Label5 
         Caption         =   "3"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Index           =   2
         Left            =   4920
         TabIndex        =   49
         Top             =   1605
         Width           =   255
      End
      Begin VB.Label Label4 
         Caption         =   "0"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Index           =   2
         Left            =   2280
         TabIndex        =   48
         Top             =   1605
         Width           =   375
      End
      Begin VB.Label Label3 
         Caption         =   "VCO Adjust"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   270
         Index           =   5
         Left            =   240
         TabIndex        =   47
         Top             =   1365
         Width           =   1215
      End
      Begin VB.Label Label8 
         Caption         =   "(Center Frequency)"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Left            =   120
         TabIndex        =   46
         Top             =   1620
         Width           =   1935
      End
   End
   Begin VB.Frame Frame3 
      Caption         =   "Transmitter ADF7012"
      Height          =   6495
      Left            =   6720
      TabIndex        =   14
      Top             =   960
      Width           =   6495
      Begin VB.CommandButton Command8 
         Caption         =   "reset"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   12
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   435
         Left            =   0
         TabIndex        =   43
         Top             =   6000
         Width           =   855
      End
      Begin VB.CommandButton Command7 
         Caption         =   "write"
         Height          =   615
         Left            =   4200
         TabIndex        =   42
         Top             =   5640
         Width           =   1335
      End
      Begin VB.CommandButton Command6 
         Caption         =   "read"
         Height          =   615
         Left            =   1200
         TabIndex        =   41
         Top             =   5640
         Width           =   1335
      End
      Begin VB.ComboBox Combo3 
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   330
         Index           =   2
         ItemData        =   "Form1.frx":09A7
         Left            =   4320
         List            =   "Form1.frx":09B7
         TabIndex        =   39
         Text            =   "1.221kHz"
         Top             =   3120
         Width           =   1575
      End
      Begin VB.ComboBox Combo3 
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   330
         Index           =   1
         ItemData        =   "Form1.frx":09E3
         Left            =   2400
         List            =   "Form1.frx":09F3
         TabIndex        =   37
         Text            =   "< 2.35V"
         Top             =   3120
         Width           =   1575
      End
      Begin VB.ComboBox Combo3 
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   330
         Index           =   0
         ItemData        =   "Form1.frx":0A1B
         Left            =   360
         List            =   "Form1.frx":0A2B
         TabIndex        =   35
         Text            =   "Icp = 0.3mA"
         Top             =   3120
         Width           =   1575
      End
      Begin VB.HScrollBar HScroll1 
         Height          =   300
         Index           =   1
         Left            =   1845
         Max             =   3
         TabIndex        =   29
         Top             =   1800
         Width           =   4455
      End
      Begin VB.HScrollBar HScroll1 
         Height          =   300
         Index           =   0
         Left            =   960
         Max             =   63
         TabIndex        =   24
         Top             =   795
         Width           =   5415
      End
      Begin VB.Frame Frame4 
         Caption         =   "Updata Registers(0x)--Design special"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   1455
         Left            =   120
         TabIndex        =   15
         Top             =   3960
         Width           =   4935
         Begin VB.CommandButton Command5 
            Caption         =   "Updata"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   3
            Left            =   3720
            TabIndex        =   23
            Top             =   1035
            Width           =   1095
         End
         Begin VB.TextBox Text4 
            Alignment       =   2  'Center
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   3
            Left            =   3720
            MaxLength       =   8
            TabIndex        =   22
            Top             =   645
            Width           =   1095
         End
         Begin VB.CommandButton Command5 
            Caption         =   "Updata"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   2
            Left            =   2520
            TabIndex        =   21
            Top             =   1035
            Width           =   1095
         End
         Begin VB.TextBox Text4 
            Alignment       =   2  'Center
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   2
            Left            =   2520
            MaxLength       =   8
            TabIndex        =   20
            Top             =   645
            Width           =   1095
         End
         Begin VB.TextBox Text4 
            Alignment       =   2  'Center
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   1
            Left            =   1320
            MaxLength       =   8
            TabIndex        =   19
            Top             =   645
            Width           =   1095
         End
         Begin VB.CommandButton Command5 
            Caption         =   "Updata"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   1
            Left            =   1320
            TabIndex        =   18
            Top             =   1035
            Width           =   1095
         End
         Begin VB.TextBox Text4 
            Alignment       =   2  'Center
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   0
            Left            =   120
            MaxLength       =   8
            TabIndex        =   17
            Top             =   645
            Width           =   1095
         End
         Begin VB.CommandButton Command5 
            Caption         =   "Updata"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            Height          =   315
            Index           =   0
            Left            =   120
            TabIndex        =   16
            Top             =   1035
            Width           =   1095
         End
         Begin VB.Label Label9 
            Alignment       =   2  'Center
            Caption         =   "Register 3"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            ForeColor       =   &H000000FF&
            Height          =   255
            Index           =   3
            Left            =   3720
            TabIndex        =   65
            Top             =   360
            Width           =   1095
         End
         Begin VB.Label Label9 
            Alignment       =   2  'Center
            Caption         =   "Register 2"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            ForeColor       =   &H000000FF&
            Height          =   255
            Index           =   2
            Left            =   2520
            TabIndex        =   64
            Top             =   360
            Width           =   1095
         End
         Begin VB.Label Label9 
            Alignment       =   2  'Center
            Caption         =   "Register 1"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            ForeColor       =   &H000000FF&
            Height          =   255
            Index           =   1
            Left            =   1320
            TabIndex        =   63
            Top             =   360
            Width           =   1095
         End
         Begin VB.Label Label9 
            Alignment       =   2  'Center
            Caption         =   "Register 0"
            BeginProperty Font 
               Name            =   "宋体"
               Size            =   10.5
               Charset         =   134
               Weight          =   400
               Underline       =   0   'False
               Italic          =   0   'False
               Strikethrough   =   0   'False
            EndProperty
            ForeColor       =   &H000000FF&
            Height          =   255
            Index           =   0
            Left            =   120
            TabIndex        =   62
            Top             =   360
            Width           =   1095
         End
      End
      Begin VB.Image Image2 
         Height          =   735
         Left            =   5400
         Top             =   4440
         Width           =   735
      End
      Begin VB.Label Label3 
         Caption         =   "Frequency Deviation"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   270
         Index           =   4
         Left            =   4320
         TabIndex        =   40
         Top             =   2880
         Width           =   2055
      End
      Begin VB.Label Label3 
         Caption         =   "Battery Measure"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   270
         Index           =   3
         Left            =   2400
         TabIndex        =   38
         Top             =   2880
         Width           =   1575
      End
      Begin VB.Label Label3 
         Caption         =   "PLL Charge Pump"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   270
         Index           =   2
         Left            =   360
         TabIndex        =   36
         Top             =   2880
         Width           =   1575
      End
      Begin VB.Label Label7 
         Caption         =   "(Center Frequency)"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Left            =   120
         TabIndex        =   34
         Top             =   2100
         Width           =   1935
      End
      Begin VB.Label Label3 
         Caption         =   "VCO Adjust"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   270
         Index           =   1
         Left            =   360
         TabIndex        =   33
         Top             =   1845
         Width           =   1215
      End
      Begin VB.Label Label4 
         Caption         =   "0"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Index           =   1
         Left            =   2400
         TabIndex        =   32
         Top             =   2085
         Width           =   375
      End
      Begin VB.Label Label5 
         Caption         =   "3"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Index           =   1
         Left            =   6000
         TabIndex        =   31
         Top             =   2085
         Width           =   255
      End
      Begin VB.Label Label6 
         Alignment       =   2  'Center
         Caption         =   "Setting 0"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H00FF0000&
         Height          =   255
         Index           =   1
         Left            =   3720
         TabIndex        =   30
         Top             =   2085
         Width           =   1335
      End
      Begin VB.Label Label6 
         Alignment       =   2  'Center
         Caption         =   "Setting 0"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         ForeColor       =   &H00FF0000&
         Height          =   255
         Index           =   0
         Left            =   3000
         TabIndex        =   28
         Top             =   1080
         Width           =   1335
      End
      Begin VB.Label Label5 
         Caption         =   "+14dBm"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Index           =   0
         Left            =   5760
         TabIndex        =   27
         Top             =   1080
         Width           =   615
      End
      Begin VB.Label Label4 
         Caption         =   "-16dBm"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   255
         Index           =   0
         Left            =   840
         TabIndex        =   26
         Top             =   1080
         Width           =   735
      End
      Begin VB.Label Label3 
         Caption         =   "TX Power"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   10.5
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   375
         Index           =   0
         Left            =   75
         TabIndex        =   25
         Top             =   840
         Width           =   975
      End
   End
   Begin VB.Frame Frame2 
      Caption         =   "Debug DATA"
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   14.25
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   735
      Left            =   120
      TabIndex        =   11
      Top             =   120
      Width           =   4575
      Begin VB.TextBox Text3 
         BackColor       =   &H8000000B&
         Enabled         =   0   'False
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   14.25
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   345
         Left            =   2400
         TabIndex        =   13
         Top             =   360
         Width           =   2055
      End
      Begin VB.TextBox Text2 
         BackColor       =   &H8000000B&
         Enabled         =   0   'False
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   14.25
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   315
         Left            =   120
         TabIndex        =   12
         Top             =   360
         Width           =   2175
      End
   End
   Begin VB.ComboBox Combo2 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   435
      ItemData        =   "Form1.frx":0A63
      Left            =   120
      List            =   "Form1.frx":0A70
      TabIndex        =   8
      Text            =   "Trigger mode"
      Top             =   7920
      Width           =   3615
   End
   Begin VB.Timer Timer1 
      Enabled         =   0   'False
      Interval        =   700
      Left            =   6720
      Top             =   7800
   End
   Begin VB.CommandButton Command3 
      Caption         =   "exit"
      Height          =   615
      Left            =   8640
      TabIndex        =   5
      Top             =   7920
      Width           =   1215
   End
   Begin VB.ComboBox Combo1 
      BeginProperty Font 
         Name            =   "宋体"
         Size            =   15.75
         Charset         =   134
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   435
      ItemData        =   "Form1.frx":0AA7
      Left            =   4800
      List            =   "Form1.frx":0AD2
      TabIndex        =   4
      Text            =   "COM Port"
      Top             =   360
      Width           =   1815
   End
   Begin VB.Frame Frame1 
      Caption         =   "ID Set"
      Height          =   6015
      Left            =   120
      TabIndex        =   0
      Top             =   1440
      Width           =   6375
      Begin VB.CommandButton Command2 
         Caption         =   "write"
         Height          =   615
         Left            =   4320
         TabIndex        =   10
         Top             =   4680
         Width           =   1335
      End
      Begin VB.CommandButton Command1 
         Caption         =   "read"
         Height          =   615
         Left            =   840
         TabIndex        =   9
         Top             =   4680
         Width           =   1455
      End
      Begin VB.CommandButton Command4 
         Caption         =   "reset"
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   12
            Charset         =   134
            Weight          =   400
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   435
         Left            =   0
         TabIndex        =   7
         Top             =   5520
         Width           =   855
      End
      Begin VB.CheckBox Check1 
         Caption         =   "Auto Inc"
         Height          =   495
         Left            =   1800
         TabIndex        =   3
         Top             =   2640
         Width           =   2415
      End
      Begin VB.TextBox Text1 
         Alignment       =   2  'Center
         BeginProperty Font 
            Name            =   "宋体"
            Size            =   36
            Charset         =   134
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   855
         Left            =   1200
         MaxLength       =   8
         TabIndex        =   2
         Text            =   "00000000"
         Top             =   1440
         Width           =   3495
      End
      Begin VB.Image Image1 
         Height          =   735
         Left            =   4800
         Top             =   1560
         Width           =   735
      End
      Begin VB.Label Label1 
         Caption         =   "ID"
         BeginProperty Font 
            Name            =   "Trebuchet MS"
            Size            =   36
            Charset         =   0
            Weight          =   700
            Underline       =   0   'False
            Italic          =   0   'False
            Strikethrough   =   0   'False
         EndProperty
         Height          =   855
         Left            =   360
         TabIndex        =   1
         Top             =   1440
         Width           =   1335
      End
   End
   Begin MSCommLib.MSComm MSComm1 
      Left            =   7560
      Top             =   7800
      _ExtentX        =   1005
      _ExtentY        =   1005
      _Version        =   393216
      CommPort        =   4
      DTREnable       =   -1  'True
      InBufferSize    =   2048
      OutBufferSize   =   2048
   End
   Begin VB.Image Image4 
      Height          =   495
      Left            =   6720
      Top             =   360
      Width           =   375
   End
   Begin VB.Label Label2 
      ForeColor       =   &H000000FF&
      Height          =   495
      Left            =   3840
      TabIndex        =   6
      Top             =   7800
      Width           =   2535
   End
End
Attribute VB_Name = "Form1"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False

Dim timer_delay_rx_1 As Byte
Public ComStatus As Boolean
Dim InputSignal As String       ' 接收缓冲暂存
Dim InputSignal0 As String
Dim BER_N As Integer
Private Sub Check2_Click()
'If Check2.Value = 1 Then
'Text1.Text = "AAA"
'Text1.Enabled = False
'Else
'Text1.Text = "00000000"
'Text1.Enabled = True
'End If
End Sub
'##################################################################################
'#                                     串口设置                                   #
'##################################################################################
Private Sub CommPort1_Set(id As Byte)
    On Error GoTo error_access
    CommPort = id
    If MSComm1.PortOpen = True Then MSComm1.PortOpen = False
    MSComm1.CommPort = CommPort
    MSComm1.RThreshold = 3
    MSComm1.PortOpen = True
    ComStatus = True
    Image4.Picture = LoadPicture(App.Path & "\kai.jpg")
    Exit Sub
error_access:
    ComStatus = False
    Image4.Picture = LoadPicture(App.Path & "\guan.jpg")
    'MsgBox "COM fail"
    MsgBox "COM is not open", vbInformation, "Error"
    Exit Sub
End Sub

Private Sub Combo1_Click()
Dim id_i As Byte
Dim id_j As Byte

    id_i = Val(Mid(Combo1.Text, 4, 1))
    id_j = Val(Mid(Combo1.Text, 5, 1))
    
    Call CommPort1_Set(id_i * 10 + id_j)


End Sub

Private Sub Combo3_Click(Index As Integer)
Dim d1, d2, d3 As Long
Dim str As String
Dim str0 As String
Dim str1 As String
Dim a As Long
Dim i, i0, char0 As Integer


    If Index = 0 Then
        str0 = Text4(3).Text
        
        d1 = hex2dec(Mid(str, 7, 1)) Mod 4
        d1 = d1 + Combo3(Index).ListIndex * 4
        
        Text4(3).Text = Mid(str0, 1, 6) + Right$("0" + Hex(d1), 1) + Mid(str0, 8, 1)
        Text4(3).BackColor = &H80FF80
    End If
    
    If Index = 1 Then
        str0 = Text4(3).Text

        d1 = hex2dec(Mid(str0, 5, 1)) * 16 + hex2dec(Mid(str0, 6, 1))
        d2 = d1 Mod 8
        d3 = d1 \ 128
        d1 = d3 * 128 + (Combo3(Index).ListIndex + 10) * 8 + d2
        
        Text4(3).Text = Mid(str0, 1, 4) + Right$("00" + Hex(d1), 2) + Mid(str0, 7, 2)
        Text4(3).BackColor = &H80FF80
    End If
    
    If Index = 2 Then
        str0 = Text4(2).Text

        d1 = hex2dec(Mid(str, 3, 1)) \ 8
        d1 = d1 * 8 + Combo3(Index).ListIndex
        
        Text4(2).Text = Mid(str0, 1, 2) + Right$("0" + Hex(d1), 1) + Mid(str0, 4, 5)
        Text4(2).BackColor = &H80FF80
                
    End If
    
    If Index = 3 Then
        str0 = TextR(1).Text

        d1 = hex2dec(Mid(str0, 4, 1)) * 16 + hex2dec(Mid(str0, 5, 1))
        d2 = d1 Mod 8
        d3 = d1 \ 32
        d1 = d3 * 32 + Combo3(Index).ListIndex * 8 + d2
        
        TextR(1).Text = Mid(str0, 1, 3) + Right$("00" + Hex(d1), 2) + Mid(str0, 6, 3)
        TextR(1).BackColor = &H80FF80
                
    End If
    
    If Index = 4 Then
     
       If (ComStatus = False) Then                                     ' \
          MsgBox "COM is not open", vbInformation, "Error"            ' |
          Exit Sub                                                    ' |
       End If
    
        i = Combo3(Index).ListIndex
        
                 Image3.Picture = LoadPicture("")
                 
                 Text2.Text = ""
                 char0 = 0
                
                Text2.Text = "(WJ" + Right$("0" + Hex(i), 1) + ")"
        
                MSComm1.OutBufferCount = 0                   '清发送缓存区
                MSComm1.InBufferCount = 0                    '清接收缓存区
                InputSignal = ""
                MSComm1.RThreshold = 5
        
                'Text3.Text = ""
                MSComm1.Output = Text2.Text
        
                Call timer_delay(200)
        
                'str = MSComm1.Input
                str = InputSignal
                Text3.Text = str
                str0 = Mid(str, 1, 5)
                
'                str1 = "(WJ)" + Right$("0" + Hex(i), 1)
'                If str0 <> str1 Then
'                   char0 = 1
'                End If
                If Combo3(4).ListIndex = 3 Then
                    str1 = ""
                    If str0 = str1 Then
                       char0 = 1
                    End If
                Else
                    str1 = "(WJ)" + Right$("0" + Hex(i), 1)
                    If str0 <> str1 Then
                       char0 = 1
                    End If
                End If
                
                If char0 = 0 Then
                    Image3.Picture = LoadPicture(App.Path & "\navigate_check.bmp")
                
                Else
                   Image3.Picture = LoadPicture(App.Path & "\navigate_cross.bmp")
                End If
                
                Text5.Text = ""
                BER_N = 0
                
    End If
End Sub

Private Sub Command1_Click()

    Dim str As String
    Dim str0 As String
    Dim d1  As Long

    If (ComStatus = False) Then                                     ' \
        MsgBox "COM is not open", vbInformation, "Error"            ' |
        Exit Sub                                                    ' |
    End If                                                          ' /

Command1.Enabled = False
Image1.Picture = LoadPicture("")

Text2.Text = "(RG)"

MSComm1.OutBufferCount = 0                   '清发送缓存区
MSComm1.Output = Text2.Text
MSComm1.InBufferCount = 0                    '清接收缓存区
InputSignal = ""
MSComm1.RThreshold = 10

Text3.Text = ""
Call timer_delay(200)

'str = MSComm1.Input
str = InputSignal
Text3.Text = str
str0 = Mid(str, 1, 4)
If str0 = "(RG)" Then
    d1 = hex2dec(Mid(str, 5, 1)) * 16 + hex2dec(Mid(str, 6, 1))
    d1 = d1 * 256
    d1 = d1 + hex2dec(Mid(str, 7, 1)) * 16 + hex2dec(Mid(str, 8, 1))
    d1 = d1 * 256
    d1 = d1 + hex2dec(Mid(str, 9, 1)) * 16 + hex2dec(Mid(str, 10, 1))
    
    Text1.Text = Right$("00000000" + Trim(d1), 8)
    'str = Right$("00000000" + d1, 8)
    'Text1.Text = str
    
    Image1.Picture = LoadPicture(App.Path & "\navigate_check.bmp")
    
Else
   Text1.Text = Right$("00000000", 8)
   Image1.Picture = LoadPicture(App.Path & "\navigate_cross.bmp")
End If

Command1.Enabled = True

End Sub


Private Sub Command10_Click()
Dim str As String
Dim str0 As String
Dim str1 As String
Dim a As Long
Dim i, i0, char0 As Integer

    If (ComStatus = False) Then                                     ' \
        MsgBox "COM is not open", vbInformation, "Error"            ' |
        Exit Sub                                                    ' |
    End If

 Command10.Enabled = False
 Image3.Picture = LoadPicture("")
 
 Text2.Text = ""
 char0 = 0
 
 'For i = 0 To 4
 For i = 1 To 1

        Text2.Text = "(WI" + Right$("0" + Hex(i), 1) + TextR(i).Text + ")"

        MSComm1.OutBufferCount = 0                   '清发送缓存区
        MSComm1.InBufferCount = 0                    '清接收缓存区
        InputSignal = ""
        MSComm1.RThreshold = 5

        'Text3.Text = ""
        MSComm1.Output = Text2.Text

        Call timer_delay(200)

        'str = MSComm1.Input
        str = InputSignal
        Text3.Text = str
        str0 = Mid(str, 1, 5)
        str1 = "(WI)" + Right$("0" + Hex(i), 1)
        If str0 <> str1 Then
           char0 = 1
        End If
 Next

If char0 = 0 Then
    Image3.Picture = LoadPicture(App.Path & "\navigate_check.bmp")

Else
   Image3.Picture = LoadPicture(App.Path & "\navigate_cross.bmp")
End If
        
Command10.Enabled = True

 For i0 = 0 To 4
   TextR(i0).BackColor = &H80000005
 Next
End Sub

Private Sub Command11_Click()

    Image3.Picture = LoadPicture("")
'-------------------------------RX

HScroll1(2).Value = 2           'VCO Adjust
Label6(2).Caption = "Setting " + Right$("00" + HScroll1(2).Value, 2)

Combo3(3).ListIndex = 2   'PLL Charge Pump

TextR(0).Text = "0954C7B0"
TextR(1).Text = "031B5011"
TextR(2).Text = "00500882"
TextR(3).Text = "29915CD3"
TextR(4).Text = "00289A14"
TextR(10).Text = "049668FA"

TextR(5).Text = "00000005"
TextR(6).Text = "00000006"
TextR(7).Text = "00000007"
TextR(8).Text = "00000008"
TextR(9).Text = "00000009"
TextR(11).Text = "0000000B"
TextR(12).Text = "0000000C"
TextR(13).Text = "0000000D"
TextR(14).Text = "0000000E"
TextR(15).Text = "0000000F"

 For i0 = 0 To 15
   TextR(i0).BackColor = &H80000005
 Next

End Sub

Private Sub Command2_Click()


Dim str As String
Dim str0 As String
Dim a As Long
Dim d1  As Long
Dim Send_Str As String

    If (ComStatus = False) Then                                     ' \
        MsgBox "COM is not open", vbInformation, "Error"            ' |
        Exit Sub                                                    ' |
    End If                                                          ' /

Command2.Enabled = False
Image1.Picture = LoadPicture("")

Text2.Text = ""


Send_Str = Text1.Text
Long_Num = Len(Send_Str)
If Long_Num <> 8 Then
MsgBox "ID bits ! = 8", vbInformation, "Error"
Command2.Enabled = True
Exit Sub
End If

If Val(Text1.Text) > 16777214 Then

MsgBox "ID>16777214", vbInformation, "Error"
Command2.Enabled = True
Exit Sub
End If

If Val(Text1.Text) = 0 Then

MsgBox "ID=0", vbInformation, "Error"
Command2.Enabled = True
Exit Sub
End If

a = Val(Text1.Text)
Text2.Text = "(WG" + Right$("000000" + Hex(a), 6) + ")"

MSComm1.OutBufferCount = 0                   '清发送缓存区
MSComm1.Output = Text2.Text
MSComm1.InBufferCount = 0                    '清接收缓存区
InputSignal = ""
MSComm1.RThreshold = 4

Text3.Text = ""
Call timer_delay(200)

'str = MSComm1.Input
str = InputSignal
Text3.Text = str
str0 = Mid(str, 1, 5)
If str0 = "(WG)" Then

    Image1.Picture = LoadPicture(App.Path & "\navigate_check.bmp")

Else

   Image1.Picture = LoadPicture(App.Path & "\navigate_cross.bmp")
End If


If Check1.Value = 1 Then
If Val(Text1.Text) < 16777214 Then
d1 = Val(Text1.Text) + 1
Text1.Text = Right$("00000000" + Trim(d1), 8)
Else
Text1.Text = "00000001"
End If
End If


Command2.Enabled = True

End Sub

Private Sub Command4_Click()

On Error GoTo err_flag
Text1.Text = "00000000"
Image1.Picture = LoadPicture("")
Label2.Caption = ""

Check1.Value = False
Check2.Value = False
 'Combo1.Text = "串口"
 MSComm1.PortOpen = False                      '关闭串口
err_flag:

End Sub

Private Sub Command5_Click(Index As Integer)
Dim str As String
Dim str0 As String
Dim str1 As String
Dim a As Long

    If (ComStatus = False) Then                                     ' \
        MsgBox "COM is not open", vbInformation, "Error"            ' |
        Exit Sub                                                    ' |
    End If
    
 Command5(Index).Enabled = False
 Image2.Picture = LoadPicture("")
    
Text2.Text = "(WH" + Right$("0" + Trim(Index), 1) + Text4(Index).Text + ")"

MSComm1.OutBufferCount = 0                   '清发送缓存区
MSComm1.InBufferCount = 0                    '清接收缓存区
InputSignal = ""
MSComm1.RThreshold = 5

Text3.Text = ""
MSComm1.Output = Text2.Text

Call timer_delay(200)

'str = MSComm1.Input
str = InputSignal
Text3.Text = str
str0 = Mid(str, 1, 5)
str1 = "(WH)" + Right$("0" + Trim(Index), 1)
If str0 = str1 Then

    Image2.Picture = LoadPicture(App.Path & "\navigate_check.bmp")

Else

   Image2.Picture = LoadPicture(App.Path & "\navigate_cross.bmp")
End If

Text4(Index).BackColor = &H80000005
Command5(Index).Enabled = True
End Sub


Private Sub Command6_Click()
    Dim str As String
    Dim str0 As String
    Dim d1  As Long
    Dim i, char0 As Integer
    
    If (ComStatus = False) Then                                     ' \
        MsgBox "COM is not open", vbInformation, "Error"            ' |
        Exit Sub                                                    ' |
    End If                                                          ' /

Command6.Enabled = False
Image2.Picture = LoadPicture("")

 For i = 0 To 3

        Text2.Text = "(RH" + Right$("0" + Trim(i), 1) + ")"

        MSComm1.OutBufferCount = 0                   '清发送缓存区
        MSComm1.InBufferCount = 0                    '清接收缓存区
        InputSignal = ""
        MSComm1.RThreshold = 12

        'Text3.Text = ""
        MSComm1.Output = Text2.Text

        Call timer_delay(200)

        'str = MSComm1.Input
        str = InputSignal
        Text3.Text = str
        str0 = Mid(str, 1, 4)
        If str0 = "(RH)" Then
           Text4(i).Text = Mid(str, 5, 8)
        Else
          char0 = 1
        End If
 Next

If char0 = 0 Then
    Image2.Picture = LoadPicture(App.Path & "\navigate_check.bmp")

Else
   Image2.Picture = LoadPicture(App.Path & "\navigate_cross.bmp")
End If


Text4(0).BackColor = &H80000005
Text4(1).BackColor = &H80000005
Text4(2).BackColor = &H80000005
Text4(3).BackColor = &H80000005
Command6.Enabled = True
End Sub

Private Sub Command7_Click()
Dim str As String
Dim str0 As String
Dim str1 As String
Dim a As Long
Dim i, char0 As Integer

    If (ComStatus = False) Then                                     ' \
        MsgBox "COM is not open", vbInformation, "Error"            ' |
        Exit Sub                                                    ' |
    End If

 Command7.Enabled = False
 Image2.Picture = LoadPicture("")
 
 Text2.Text = ""
 char0 = 0
 
 For i = 0 To 3

        Text2.Text = "(WH" + Right$("0" + Trim(i), 1) + Text4(i).Text + ")"

        MSComm1.OutBufferCount = 0                   '清发送缓存区
        MSComm1.InBufferCount = 0                    '清接收缓存区
        InputSignal = ""
        MSComm1.RThreshold = 5

        'Text3.Text = ""
        MSComm1.Output = Text2.Text

        Call timer_delay(200)

        'str = MSComm1.Input
        str = InputSignal
        Text3.Text = str
        str0 = Mid(str, 1, 5)
        str1 = "(WH)" + Right$("0" + Trim(i), 1)
        If str0 <> str1 Then
           char0 = 1
        End If
 Next

If char0 = 0 Then
    Image2.Picture = LoadPicture(App.Path & "\navigate_check.bmp")

Else
   Image2.Picture = LoadPicture(App.Path & "\navigate_cross.bmp")
End If
        
Command7.Enabled = True

Text4(0).BackColor = &H80000005
Text4(1).BackColor = &H80000005
Text4(2).BackColor = &H80000005
Text4(3).BackColor = &H80000005
End Sub

Private Sub Command8_Click()
    Image2.Picture = LoadPicture("")
    HScroll1(0).Value = 13           'TX Power
    Label6(0).Caption = "Setting " + Right$("00" + HScroll1(0).Value, 2)
    
    HScroll1(1).Value = 1           'VCO Adjust
    Label6(1).Caption = "Setting " + Right$("00" + HScroll1(1).Value, 2)
    
    '    a = cboSysOp(1).ListIndex
    '    b = cboSysOp(1).ItemData(a)
    Combo3(0).ListIndex = 1  'PLL Charge Pump
    Combo3(1).ListIndex = 0  'Battery Measure
    Combo3(2).ListIndex = 1  'Frequency Deviation
    
    Text4(0).Text = "00884000"
    Text4(1).Text = "00154DC1"
    Text4(2).Text = "011209A6"
    Text4(3).Text = "0021D04F"
    
    Text4(0).BackColor = &H80000005
    Text4(1).BackColor = &H80000005
    Text4(2).BackColor = &H80000005
    Text4(3).BackColor = &H80000005
End Sub

Private Sub Command9_Click()
    Dim str As String
    Dim str0 As String
    Dim d1  As Long
    Dim i, i0, char0 As Integer
    
    If (ComStatus = False) Then                                     ' \
        MsgBox "COM is not open", vbInformation, "Error"            ' |
        Exit Sub                                                    ' |
    End If                                                          ' /

Command9.Enabled = False
Image3.Picture = LoadPicture("")

' For i = 0 To 4
 For i = 1 To 1

        Text2.Text = "(RI" + Right$("0" + Hex(i), 1) + ")"

        MSComm1.OutBufferCount = 0                   '清发送缓存区
        MSComm1.InBufferCount = 0                    '清接收缓存区
        InputSignal = ""
        MSComm1.RThreshold = 12

        'Text3.Text = ""
        MSComm1.Output = Text2.Text

        Call timer_delay(200)

        'str = MSComm1.Input
        str = InputSignal
        Text3.Text = str
        str0 = Mid(str, 1, 4)
        If str0 = "(RI)" Then
           TextR(i).Text = Mid(str, 5, 8)
        Else
          char0 = 1
        End If
 Next

If char0 = 0 Then
    Image3.Picture = LoadPicture(App.Path & "\navigate_check.bmp")

Else
   Image3.Picture = LoadPicture(App.Path & "\navigate_cross.bmp")
End If


 For i0 = 0 To 4
   TextR(i0).BackColor = &H80000005
 Next
Command9.Enabled = True
End Sub

Private Sub CommandR_Click(Index As Integer)
Dim str As String
Dim str0 As String
Dim str1 As String
Dim a As Long

    If (ComStatus = False) Then                                     ' \
        MsgBox "COM is not open", vbInformation, "Error"            ' |
        Exit Sub                                                    ' |
    End If
    
 CommandR(Index).Enabled = False
 Image3.Picture = LoadPicture("")
    
Text2.Text = "(WI" + Right$("0" + Trim(Index), 1) + TextR(Index).Text + ")"

MSComm1.OutBufferCount = 0                   '清发送缓存区
MSComm1.InBufferCount = 0                    '清接收缓存区
InputSignal = ""
MSComm1.RThreshold = 5

Text3.Text = ""
MSComm1.Output = Text2.Text

Call timer_delay(200)

'str = MSComm1.Input
str = InputSignal
Text3.Text = str
str0 = Mid(str, 1, 5)
str1 = "(WI)" + Right$("0" + Trim(Index), 1)
If str0 = str1 Then

    Image3.Picture = LoadPicture(App.Path & "\navigate_check.bmp")

Else

   Image3.Picture = LoadPicture(App.Path & "\navigate_cross.bmp")
End If

TextR(Index).BackColor = &H80000005
CommandR(Index).Enabled = True
End Sub

Private Sub Form_Unload(Cancel As Integer)
On Error GoTo flagg
MSComm1.PortOpen = False
flagg:
End Sub


Private Sub HScroll1_Change(Index As Integer)
Dim d1, d2, d3 As Long
Dim str As String
Dim str0 As String

Label6(Index).Caption = "Setting " + Right$("00" + HScroll1(Index).Value, 2)

    If Index = 0 Then
        str0 = Text4(2).Text

        d1 = hex2dec(Mid(str0, 6, 1)) * 16 + hex2dec(Mid(str0, 7, 1))
        d2 = d1 Mod 2
        d3 = d1 \ 128
        d1 = d3 * 128 + HScroll1(Index).Value * 2 + d2
        
        Text4(2).Text = Mid(str0, 1, 5) + Right$("00" + Hex(d1), 2) + Mid(str0, 8, 1)
        Text4(2).BackColor = &H80FF80
    
    End If
    
    If Index = 1 Then
        str0 = Text4(0).Text

        d1 = hex2dec(Mid(str0, 2, 1)) * 16 + hex2dec(Mid(str0, 3, 1))
        d2 = d1 Mod 8
        d3 = d1 \ 32
        d1 = d3 * 32 + HScroll1(Index).Value * 8 + d2
        
        Text4(0).Text = Mid(str0, 1, 1) + Right$("00" + Hex(d1), 2) + Mid(str0, 4, 5)
        Text4(0).BackColor = &H80FF80
    
    End If
    
    If Index = 2 Then
        str0 = TextR(1).Text

        d1 = hex2dec(Mid(str0, 2, 1)) * 16 + hex2dec(Mid(str0, 3, 1))
        d2 = d1 Mod 8
        d3 = d1 \ 32
        d1 = d3 * 32 + HScroll1(Index).Value * 8 + d2
        
        TextR(1).Text = Mid(str0, 1, 1) + Right$("00" + Hex(d1), 2) + Mid(str0, 4, 5)
        TextR(1).BackColor = &H80FF80
    
    End If
End Sub



Private Sub MSComm1_OnComm()
On Error GoTo Err
    Select Case MSComm1.CommEvent                                                    ' 每接收n个数就触发一次
        Case comEvReceive

                'Call textReceive                                                    ' 文本接收
                InputSignal = MSComm1.Input
                If Combo3(4).ListIndex = 3 Then
                  BER_N = BER_N + 1
                  If BER_N > 22 Then
                     BER_N = 22
                     Text5.Text = Mid(Text5.Text, 5, 84)
                  End If
                  If InputSignal = "(WJ)3" Then
                     InputSignal0 = ""
                  Else
                     InputSignal0 = Mid(InputSignal, 1, 4)
                  End If
                  
                  Text5.Text = Text5.Text + CrLf + InputSignal0
                End If
        Case comEvSend                                                              ' 每发送1个数就触发一次
        Case Else
    End Select
Err:
End Sub

Private Sub Picture1_Click()

End Sub

Private Sub Text1_KeyPress(KeyAscii As Integer)
'判断输入字符的Ascii码,如果不符合英文Ascii码就不进行任何操作
Select Case KeyAscii
Case 48 To 57 '数字有效
Case 8 '退格

Case Else
KeyAscii = 0
End Select
End Sub

Private Sub Command3_Click()
Unload Form1
End Sub

Private Sub Form_Load()
Dim i0 As Integer


'----------------------------TX
HScroll1(0).Value = 13           'TX Power
Label6(0).Caption = "Setting " + Right$("00" + HScroll1(0).Value, 2)

HScroll1(1).Value = 1           'VCO Adjust
Label6(1).Caption = "Setting " + Right$("00" + HScroll1(1).Value, 2)

'    a = cboSysOp(1).ListIndex
'    b = cboSysOp(1).ItemData(a)
Combo3(0).ListIndex = 1  'PLL Charge Pump
Combo3(1).ListIndex = 0  'Battery Measure
Combo3(2).ListIndex = 1  'Frequency Deviation

Text4(0).Text = "00884000"
Text4(1).Text = "00154DC1"
Text4(2).Text = "012209A6"
Text4(3).Text = "0021D04F"

 For i0 = 0 To 3
   Text4(i0).BackColor = &H80000005
 Next


'-------------------------------RX

HScroll1(2).Value = 2           'VCO Adjust
Label6(2).Caption = "Setting " + Right$("00" + HScroll1(2).Value, 2)

Combo3(3).ListIndex = 2   'PLL Charge Pump

TextR(0).Text = "0954C7B0"
TextR(1).Text = "031B5011"
TextR(2).Text = "00500882"
TextR(3).Text = "29915CD3"
TextR(4).Text = "00289A14"
TextR(10).Text = "049668FA"

TextR(5).Text = "00000005"
TextR(6).Text = "00000006"
TextR(7).Text = "00000007"
TextR(8).Text = "00000008"
TextR(9).Text = "00000009"
TextR(11).Text = "0000000B"
TextR(12).Text = "0000000C"
TextR(13).Text = "0000000D"
TextR(14).Text = "0000000E"
TextR(15).Text = "0000000F"

 For i0 = 0 To 15
   TextR(i0).BackColor = &H80000005
 Next


'---------------------------to fty
Frame4.Enabled = False
Frame6.Enabled = False
 For i0 = 0 To 3
   Label9(i0).ForeColor = &H80000010
   Text4(i0).Enabled = False
   Command5(i0).Enabled = False
 Next
  For i0 = 0 To 15
   Label10(i0).ForeColor = &H80000010
   TextR(i0).Enabled = False
   CommandR(i0).Enabled = False
 Next

End Sub



Private Sub Text4_Change(Index As Integer)
  Text4(Index).BackColor = &H80FF80
End Sub

Private Sub TextR_Change(Index As Integer)
  TextR(Index).BackColor = &H80FF80
End Sub

Private Sub Timer1_Timer()
  timer_delay_rx_1 = 0
  Timer1.Enabled = False
End Sub

Sub timer_delay(count As Single)
    timer_delay_rx_1 = 1
    Timer1.Interval = count
    Timer1.Enabled = True
    Do
      DoEvents
    Loop While (timer_delay_rx_1 = 1)
End Sub
'************************************************************
'             十六进制字符串转换成十进制数
'************************************************************
Public Function hex2dec(char As String) As Variant
    Dim i As Integer
    char = UCase(char)
    Select Case char
        Case "0": i = 0
        Case "1": i = 1
        Case "2": i = 2
        Case "3": i = 3
        Case "4": i = 4
        Case "5": i = 5
        Case "6": i = 6
        Case "7": i = 7
        Case "8": i = 8
        Case "9": i = 9
        Case "A": i = 10
        Case "B": i = 11
        Case "C": i = 12
        Case "D": i = 13
        Case "E": i = 14
        Case "F": i = 15
    End Select
    hex2dec = i
End Function
