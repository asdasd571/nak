package umc.study.domain;

import org.hibernate.annotations.ColumnDefault;
import umc.study.domain.common.BaseEntity;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

public class User extends BaseEntity {

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    private int id;

    private String name;

    @Enumerated(EnumType.STRING)
    @Column(columnDefinition = "VARCHAR(10)")
    private Gender gender;

    @Enumerated(EnumType.STRING)
    private SocialType socialType;

    @Enumerated(EnumType.STRING)
    @Column(columnDefinition = "VARCHAR(15) DEFAULT 'ACTIVE'")
    private MemberStatus status;

    private Integer age;

    @Column(columnDefinition = "varchar(40)")
    private String address;

    @Column(columnDefinition = "varchar(40)")
    private String specAddress;

    private LocalDate inactiveDate;

    //@Column(nullable = false, length = 50)
    private String email;

    @ColumnDefault("0")
    private Integer point;

    @OneToMany(mappedBy = "member", cascade = CascadeType.ALL)
    private List<MemberAgree> memberAgreeList = new ArrayList<>();

    @OneToMany(mappedBy = "member", cascade = CascadeType.ALL)
    private List<MemberPrefer> memberPreferList = new ArrayList<>();

    @OneToMany(mappedBy = "member", cascade = CascadeType.ALL)
    private List<Review> reviewList = new ArrayList<>();

    @OneToMany(mappedBy = "member", cascade = CascadeType.ALL)
    private List<MemberMission> memberMissionList = new ArrayList<>();
}
