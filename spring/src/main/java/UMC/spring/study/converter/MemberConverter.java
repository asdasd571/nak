package UMC.spring.study.converter;

import UMC.spring.study.domain.Member;
import UMC.spring.study.domain.enums.Gender;
import UMC.spring.study.web.dto.MemberRequestDTO;
import UMC.spring.study.web.dto.MemberResponseDTO;

import java.time.LocalDateTime;
import java.util.ArrayList;

//member entity를 dto로 전환 해줌
public class MemberConverter {

    public static MemberResponseDTO.JoinResultDTO toJoinResultDTO(Member member){
        return MemberResponseDTO.JoinResultDTO.builder()
                .memberId(member.getId())
                .createdAt(LocalDateTime.now())
                .build();
    }

    public static Member toMember(MemberRequestDTO.JoinDto request){

        Gender gender = null;

        switch (request.getGender()){
            case 1:
                gender = Gender.MALE;
                break;
            case 2:
                gender = Gender.FEMALE;
                break;
            case 3:
                gender = Gender.NONE;
                break;
        }

        return Member.builder()
                .address(request.getAddress())
                .specAddress(request.getSpecAddress())
                .gender(gender)
                .name(request.getName())
                .memberPreferList(new ArrayList<>())
                .build();
    }
}
