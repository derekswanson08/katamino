#ifndef BOARDMODEL_H
#define BOARDMODEL_H

#include <QObject>
#include <QColor>
#include <QVector>

class BoardModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QColor color0  READ color0  WRITE setColor0  NOTIFY color0Changed)
    Q_PROPERTY(QColor color1  READ color1  WRITE setColor1  NOTIFY color1Changed)
    Q_PROPERTY(QColor color2  READ color2  WRITE setColor2  NOTIFY color2Changed)
    Q_PROPERTY(QColor color3  READ color3  WRITE setColor3  NOTIFY color3Changed)
    Q_PROPERTY(QColor color4  READ color4  WRITE setColor4  NOTIFY color4Changed)
    Q_PROPERTY(QColor color5  READ color5  WRITE setColor5  NOTIFY color5Changed)
    Q_PROPERTY(QColor color6  READ color6  WRITE setColor6  NOTIFY color6Changed)
    Q_PROPERTY(QColor color7  READ color7  WRITE setColor7  NOTIFY color7Changed)
    Q_PROPERTY(QColor color8  READ color8  WRITE setColor8  NOTIFY color8Changed)
    Q_PROPERTY(QColor color9  READ color9  WRITE setColor9  NOTIFY color9Changed)
    Q_PROPERTY(QColor color10 READ color10 WRITE setColor10 NOTIFY color10Changed)
    Q_PROPERTY(QColor color11 READ color11 WRITE setColor11 NOTIFY color11Changed)
    Q_PROPERTY(QColor color12 READ color12 WRITE setColor12 NOTIFY color12Changed)
    Q_PROPERTY(QColor color13 READ color13 WRITE setColor13 NOTIFY color13Changed)
    Q_PROPERTY(QColor color14 READ color14 WRITE setColor14 NOTIFY color14Changed)
    Q_PROPERTY(QColor color15 READ color15 WRITE setColor15 NOTIFY color15Changed)
    Q_PROPERTY(QColor color16 READ color16 WRITE setColor16 NOTIFY color16Changed)
    Q_PROPERTY(QColor color17 READ color17 WRITE setColor17 NOTIFY color17Changed)
    Q_PROPERTY(QColor color18 READ color18 WRITE setColor18 NOTIFY color18Changed)
    Q_PROPERTY(QColor color19 READ color19 WRITE setColor19 NOTIFY color19Changed)
    Q_PROPERTY(QColor color20 READ color20 WRITE setColor20 NOTIFY color20Changed)
    Q_PROPERTY(QColor color21 READ color21 WRITE setColor21 NOTIFY color21Changed)
    Q_PROPERTY(QColor color22 READ color22 WRITE setColor22 NOTIFY color22Changed)
    Q_PROPERTY(QColor color23 READ color23 WRITE setColor23 NOTIFY color23Changed)
    Q_PROPERTY(QColor color24 READ color24 WRITE setColor24 NOTIFY color24Changed)
    Q_PROPERTY(QColor color25 READ color25 WRITE setColor25 NOTIFY color25Changed)
    Q_PROPERTY(QColor color26 READ color26 WRITE setColor26 NOTIFY color26Changed)
    Q_PROPERTY(QColor color27 READ color27 WRITE setColor27 NOTIFY color27Changed)
    Q_PROPERTY(QColor color28 READ color28 WRITE setColor28 NOTIFY color28Changed)
    Q_PROPERTY(QColor color29 READ color29 WRITE setColor29 NOTIFY color29Changed)
    Q_PROPERTY(QColor color30 READ color30 WRITE setColor30 NOTIFY color30Changed)
    Q_PROPERTY(QColor color31 READ color31 WRITE setColor31 NOTIFY color31Changed)
    Q_PROPERTY(QColor color32 READ color32 WRITE setColor32 NOTIFY color32Changed)
    Q_PROPERTY(QColor color33 READ color33 WRITE setColor33 NOTIFY color33Changed)
    Q_PROPERTY(QColor color34 READ color34 WRITE setColor34 NOTIFY color34Changed)
    Q_PROPERTY(QColor color35 READ color35 WRITE setColor35 NOTIFY color35Changed)
    Q_PROPERTY(QColor color36 READ color36 WRITE setColor36 NOTIFY color36Changed)
    Q_PROPERTY(QColor color37 READ color37 WRITE setColor37 NOTIFY color37Changed)
    Q_PROPERTY(QColor color38 READ color38 WRITE setColor38 NOTIFY color38Changed)
    Q_PROPERTY(QColor color39 READ color39 WRITE setColor39 NOTIFY color39Changed)

public:
    explicit BoardModel(QObject *parent = nullptr);

    void setColor0 (QColor x) { if(x != m_color0 ) { m_color0  = x; emit color0Changed(); } }
    void setColor1 (QColor x) { if(x != m_color1 ) { m_color1  = x; emit color1Changed(); } }
    void setColor2 (QColor x) { if(x != m_color2 ) { m_color2  = x; emit color2Changed(); } }
    void setColor3 (QColor x) { if(x != m_color3 ) { m_color3  = x; emit color3Changed(); } }
    void setColor4 (QColor x) { if(x != m_color4 ) { m_color4  = x; emit color4Changed(); } }
    void setColor5 (QColor x) { if(x != m_color5 ) { m_color5  = x; emit color5Changed(); } }
    void setColor6 (QColor x) { if(x != m_color6 ) { m_color6  = x; emit color6Changed(); } }
    void setColor7 (QColor x) { if(x != m_color7 ) { m_color7  = x; emit color7Changed(); } }
    void setColor8 (QColor x) { if(x != m_color8 ) { m_color8  = x; emit color8Changed(); } }
    void setColor9 (QColor x) { if(x != m_color9 ) { m_color9  = x; emit color9Changed(); } }
    void setColor10(QColor x) { if(x != m_color10) { m_color10 = x; emit color10Changed(); } }
    void setColor11(QColor x) { if(x != m_color11) { m_color11 = x; emit color11Changed(); } }
    void setColor12(QColor x) { if(x != m_color12) { m_color12 = x; emit color12Changed(); } }
    void setColor13(QColor x) { if(x != m_color13) { m_color13 = x; emit color13Changed(); } }
    void setColor14(QColor x) { if(x != m_color14) { m_color14 = x; emit color14Changed(); } }
    void setColor15(QColor x) { if(x != m_color15) { m_color15 = x; emit color15Changed(); } }
    void setColor16(QColor x) { if(x != m_color16) { m_color16 = x; emit color16Changed(); } }
    void setColor17(QColor x) { if(x != m_color17) { m_color17 = x; emit color17Changed(); } }
    void setColor18(QColor x) { if(x != m_color18) { m_color18 = x; emit color18Changed(); } }
    void setColor19(QColor x) { if(x != m_color19) { m_color19 = x; emit color19Changed(); } }
    void setColor20(QColor x) { if(x != m_color20) { m_color20 = x; emit color20Changed(); } }
    void setColor21(QColor x) { if(x != m_color21) { m_color21 = x; emit color21Changed(); } }
    void setColor22(QColor x) { if(x != m_color22) { m_color22 = x; emit color22Changed(); } }
    void setColor23(QColor x) { if(x != m_color23) { m_color23 = x; emit color23Changed(); } }
    void setColor24(QColor x) { if(x != m_color24) { m_color24 = x; emit color24Changed(); } }
    void setColor25(QColor x) { if(x != m_color25) { m_color25 = x; emit color25Changed(); } }
    void setColor26(QColor x) { if(x != m_color26) { m_color26 = x; emit color26Changed(); } }
    void setColor27(QColor x) { if(x != m_color27) { m_color27 = x; emit color27Changed(); } }
    void setColor28(QColor x) { if(x != m_color28) { m_color28 = x; emit color28Changed(); } }
    void setColor29(QColor x) { if(x != m_color29) { m_color29 = x; emit color29Changed(); } }
    void setColor30(QColor x) { if(x != m_color30) { m_color30 = x; emit color30Changed(); } }
    void setColor31(QColor x) { if(x != m_color31) { m_color31 = x; emit color31Changed(); } }
    void setColor32(QColor x) { if(x != m_color32) { m_color32 = x; emit color32Changed(); } }
    void setColor33(QColor x) { if(x != m_color33) { m_color33 = x; emit color33Changed(); } }
    void setColor34(QColor x) { if(x != m_color34) { m_color34 = x; emit color34Changed(); } }
    void setColor35(QColor x) { if(x != m_color35) { m_color35 = x; emit color35Changed(); } }
    void setColor36(QColor x) { if(x != m_color36) { m_color36 = x; emit color36Changed(); } }
    void setColor37(QColor x) { if(x != m_color37) { m_color37 = x; emit color37Changed(); } }
    void setColor38(QColor x) { if(x != m_color38) { m_color38 = x; emit color38Changed(); } }
    void setColor39(QColor x) { if(x != m_color39) { m_color39 = x; emit color39Changed(); } }

    QColor color0 () const { return m_color0 ; }
    QColor color1 () const { return m_color1 ; }
    QColor color2 () const { return m_color2 ; }
    QColor color3 () const { return m_color3 ; }
    QColor color4 () const { return m_color4 ; }
    QColor color5 () const { return m_color5 ; }
    QColor color6 () const { return m_color6 ; }
    QColor color7 () const { return m_color7 ; }
    QColor color8 () const { return m_color8 ; }
    QColor color9 () const { return m_color9 ; }
    QColor color10() const { return m_color10; }
    QColor color11() const { return m_color11; }
    QColor color12() const { return m_color12; }
    QColor color13() const { return m_color13; }
    QColor color14() const { return m_color14; }
    QColor color15() const { return m_color15; }
    QColor color16() const { return m_color16; }
    QColor color17() const { return m_color17; }
    QColor color18() const { return m_color18; }
    QColor color19() const { return m_color19; }
    QColor color20() const { return m_color20; }
    QColor color21() const { return m_color21; }
    QColor color22() const { return m_color22; }
    QColor color23() const { return m_color23; }
    QColor color24() const { return m_color24; }
    QColor color25() const { return m_color25; }
    QColor color26() const { return m_color26; }
    QColor color27() const { return m_color27; }
    QColor color28() const { return m_color28; }
    QColor color29() const { return m_color29; }
    QColor color30() const { return m_color30; }
    QColor color31() const { return m_color31; }
    QColor color32() const { return m_color32; }
    QColor color33() const { return m_color33; }
    QColor color34() const { return m_color34; }
    QColor color35() const { return m_color35; }
    QColor color36() const { return m_color36; }
    QColor color37() const { return m_color37; }
    QColor color38() const { return m_color38; }
    QColor color39() const { return m_color39; }

signals:
    void boardChanged();
    void color0Changed(); 
    void color1Changed(); 
    void color2Changed(); 
    void color3Changed(); 
    void color4Changed(); 
    void color5Changed(); 
    void color6Changed(); 
    void color7Changed(); 
    void color8Changed(); 
    void color9Changed(); 
    void color10Changed();
    void color11Changed();
    void color12Changed();
    void color13Changed();
    void color14Changed();
    void color15Changed();
    void color16Changed();
    void color17Changed();
    void color18Changed();
    void color19Changed();
    void color20Changed();
    void color21Changed();
    void color22Changed();
    void color23Changed();
    void color24Changed();
    void color25Changed();
    void color26Changed();
    void color27Changed();
    void color28Changed();
    void color29Changed();
    void color30Changed();
    void color31Changed();
    void color32Changed();
    void color33Changed();
    void color34Changed();
    void color35Changed();
    void color36Changed();
    void color37Changed();
    void color38Changed();
    void color39Changed();

    void runSolver();

public slots:
    void solve();
    void onUpdateModel(QVector<QColor> colors);

private:
    QColor m_color0  = "red";
    QColor m_color1  = "red";
    QColor m_color2  = "red";
    QColor m_color3  = "red";
    QColor m_color4  = "red";
    QColor m_color5  = "red";
    QColor m_color6  = "red";
    QColor m_color7  = "red";
    QColor m_color8  = "red";
    QColor m_color9  = "red";
    QColor m_color10 = "red";
    QColor m_color11 = "red";
    QColor m_color12 = "red";
    QColor m_color13 = "red";
    QColor m_color14 = "red";
    QColor m_color15 = "red";
    QColor m_color16 = "red";
    QColor m_color17 = "red";
    QColor m_color18 = "red";
    QColor m_color19 = "red";
    QColor m_color20 = "red";
    QColor m_color21 = "red";
    QColor m_color22 = "red";
    QColor m_color23 = "red";
    QColor m_color24 = "red";
    QColor m_color25 = "red";
    QColor m_color26 = "red";
    QColor m_color27 = "red";
    QColor m_color28 = "red";
    QColor m_color29 = "red";
    QColor m_color30 = "red";
    QColor m_color31 = "red";
    QColor m_color32 = "red";
    QColor m_color33 = "red";
    QColor m_color34 = "red";
    QColor m_color35 = "red";
    QColor m_color36 = "red";
    QColor m_color37 = "red";
    QColor m_color38 = "red";
    QColor m_color39 = "red";
};

#endif // BOARDMODEL_H

